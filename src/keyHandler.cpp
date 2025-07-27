#include "keyHandler.hpp"
#include <iostream>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

KeyHandler::KeyHandler() {}
KeyHandler::~KeyHandler() {}

// TODO: return RSA* object?
RSA* KeyHandler::generateKeyPair () {
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, 61337);
    
    int result = RSA_generate_key_ex(rsa, 2048, e, NULL);
    if (result != 1){
        std::cerr << ERR_get_error() << std::endl;
        RSA_free(rsa);
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

