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

std::string KeyHandler::generateRsaHandler() {
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

std::string KeyHandler::generateEd25519Handler() {

    EVP_PKEY_CTX *ctx = NULL;
    ENGINE *e = NULL;

    pkey = EVP_PKEY_new();
    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_ED25519, e);
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

std::string KeyHandler::generateDhHandler() {
    
    int priv_len = 2 * 112;
    EVP_PKEY_CTX *ctx = NULL;
    ENGINE *e = NULL;
    OSSL_PARAM params[3];

    pkey = EVP_PKEY_new();
    ctx = EVP_PKEY_CTX_new_from_name(NULL, "DH", NULL);

    params[0] = OSSL_PARAM_construct_utf8_string("group", "ffdhe2048", 0);
    params[1] = OSSL_PARAM_construct_int("priv_len", &priv_len);
    params[2] = OSSL_PARAM_construct_end();

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
    
    if (!EVP_PKEY_CTX_set_params(ctx, params)) {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return "Unnable to set Diffie Hellman parameters (p,q,x primes)";
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

// TODO: handle several key generation algorithms
std::string KeyHandler::generateKeyPairHandler (uint8_t algorithm) {
    // TODO: switch on algorithm

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

// a pointer to an empty EVP_PKEY structure should always be passed
std::string KeyHandler::loadKeyPrivate(EVP_PKEY** pkey, const std::string &filepath, const char *pwd) {

    if (*pkey) {
        return "Function requires to pass null EVP_PKEY structure";
    }

    FILE *f = fopen(filepath.c_str(), "rb");
    if (!f) {
        return "Key file not found";
    }
    
    if (!PEM_read_PrivateKey(f, NULL, NULL, (void*)pwd)){
        return "Unnable to read private key file conents into EVP_PKEY structure. Did you provide the correct password?";
    }
    
    return {};
}

// a pointer to an empty EVP_PKEY structure should always be passed
std::string KeyHandler::loadKeyPublic(EVP_PKEY** pkey, const std::string &filepath) {

    // An empty pkey pointer should always be passed
    if (*pkey) {
        return "Function requires to pass null EVP_PKEY structure";
    }

    FILE *f = fopen(filepath.c_str(), "rb");
    if (!f) {
        return "Key file not found";
    }

    if (!PEM_read_PUBKEY(f, pkey, NULL, NULL)){
        return "Unnable to read public key file contents into EVP_PKEY structure";
    }

    return {};
}