#pragma once

#include <string>

class SignHandler {
    private:

    public:
        SignHandler () {};
        ~SignHandler () {};

        std::string sign (EVP_PKEY *pkey, EVP_PKEY_CTX *pctx, EVP_MD *type, const std::string &filepath) {};
        std::string verify () {};
        
};