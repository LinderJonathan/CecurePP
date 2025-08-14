#pragma once

#include <string>
#include <openssl/evp.h>

class SignHandler {
    private:
        SignHandler() = delete;

    public:
        SignHandler (EVP_MD *digestType);
        ~SignHandler ();

        unsigned char *sig;
        EVP_MD *type;   // This is the digest algorithm

        std::string sign (EVP_PKEY *pkey, const std::string &filepath);
        std::string verify (EVP_PKEY *pubkey, EVP_PKEY_CTX *pubctx);
        
};