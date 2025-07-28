#include "keyHandler.hpp"
#include <iostream>
#include <string>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

KeyHandler::KeyHandler() {}
KeyHandler::~KeyHandler() {}

// TODO: return RSA* object?
std::string KeyHandler::generateKeyPair () {

    EVP_PKEY_CTX *ctx = NULL;
    EVP_PKEY *pkey = NULL;
    ENGINE *e = NULL;

    pkey = EVP_PKEY_new();
    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, e);
    if (!ctx) {

    }
    // handle ctx err
    if (EVP_PKEY_keygen_init(ctx) <= 0) {

    }
    
    // handle keygen init err
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 2048) <= 0) {

    }
    // handle ctx rsa keygen bits
    int result = EVP_PKEY_generate(ctx, &pkey);
    // handle result err
    if ()
    if (result != 1) {
        std::cerr << ERR_get_error() << std::endl;
        // EVP_pkey_free(key);
        BN_free(e);

        // TODO: handle this return case
        return nullptr;
    }
    BN_free(e);
    return rsa;
}

int KeyHandler::storeKeyPair (RSA *rsa, const std::string &pwd , const std::string &filepath) {
    FILE *pk = fopen(filepath.c_str(), "wb");
    if (!pk) {
        perror("fopen");
        return -1;
    }

    EVP_PKEY *x = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(x, rsa);
    const EVP_CIPHER *enc = nullptr;

    if (!pwd.empty()) {
        enc = EVP_aes_128_cbc();
    }

    const char *kstr = reinterpret_cast<const char *>(pwd.c_str());

    if (!PEM_write_PKCS8PrivateKey(pk, x, enc, kstr, strlen(kstr), nullptr, nullptr)) {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_free(x);
        fclose(pk);
    }

    EVP_PKEY_free(x);
    fclose(pk);

    return 0;
}

