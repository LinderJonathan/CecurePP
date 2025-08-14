#pragma once

#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <string>
#include <optional>

class KeyHandler
{
private:
    
public:
    KeyHandler();
    ~KeyHandler();

    EVP_PKEY *pkey;

    std::string generateKeyPair();
    std::string storeKeyPair (const std::string &pwd, const std::string &fpPriv, const std::string &fpPub);
    EVP_PKEY* loadKeyPrivate (const std::string &filepath, const char *pwd = NULL);
    EVP_PKEY* loadKeyPublic (const std::string &filepath);
};
