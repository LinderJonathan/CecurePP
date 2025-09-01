#pragma once

#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <string>
#include <optional>

enum class Algorithm
{
    RSA,
    ED25519,
    DIFFIE,
};

class KeyHandler
{
private:
    
public:


    KeyHandler();
    ~KeyHandler();

    EVP_PKEY *pkey;

    std::string generateRsaHandler();
    std::string generateEd25519Handler();
    std::string generateDhHandler();

    std::string generateKeyPairHandler(Algorithm algorithm);
    std::string storeKeyPair (const std::string &pwd, const std::string &fpPriv, const std::string &fpPub);
    std::string loadKeyPrivate (EVP_PKEY** pkey, const std::string &filepath, const char *pwd = NULL);
    std::string loadKeyPublic (EVP_PKEY** pkey, const std::string &filepath);
};
