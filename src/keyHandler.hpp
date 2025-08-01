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
};
