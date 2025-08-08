#include "keyHandler.hpp"
#include <iostream>
#include <string>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

KeyHandler::KeyHandler() : pkey(NULL) {}

KeyHandler::~KeyHandler() {
    if (pkey) {
        EVP_PKEY_free(pkey);
        pkey = NULL;
    }
}

// TODO: handle several methods f 
std::string KeyHandler::generateKeyPair () {

    EVP_PKEY_CTX *ctx = NULL;
    ENGINE *e = NULL;

    pkey = EVP_PKEY_new();
    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, e);
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return "Unnable to initiate context with key generation algorithm";
    }
    if (EVP_PKEY_keygen_init(ctx) <= 0) {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return "Unnable to initialize key generation algorithm";
    }
    
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 2048) <= 0) {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return "Unnable to set RSA key generation bits";
    }

    if (!EVP_PKEY_generate(ctx, &pkey)) {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return "Unnable to generate assymetric key pair";
    }

    this->pkey = pkey;
    EVP_PKEY_CTX_free(ctx);

    return {};
}

// TODO: handle several methods of encryption
std::string KeyHandler::storeKeyPair (const std::string &pwd, const std::string &fpPriv, const std::string &fpPub) {

    const EVP_CIPHER *enc = NULL;
    const char *kstr = "";
    FILE *privk = fopen(fpPriv.c_str(), "wb");
    FILE *pubk = fopen(fpPub.c_str(), "wb");
    if (!privk) {
        perror("fopen");
        return "Unnable to find private file path" + fpPriv;
    }

    if (!pubk) {
        perror("fopen");
        return "Unnable to find public file path " + fpPub;
    }

    if (!pwd.empty()) {
        enc = EVP_aes_128_cbc();
        kstr = reinterpret_cast<const char *>(pwd.c_str());
    }

    if (!PEM_write_PKCS8PrivateKey(privk, this->pkey, enc, kstr, strlen(kstr), NULL, NULL) || !PEM_write_PUBKEY(pubk, this->pkey)) {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_free(this->pkey);
        this->pkey = NULL;
        fclose(privk);
        fclose(pubk);
        return "Unnable to write write keypair to file";
    }


    EVP_PKEY_free(this->pkey);
    this->pkey = NULL;
    fclose(privk);
    fclose(pubk);

    return {};
}

