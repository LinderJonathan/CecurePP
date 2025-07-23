#include "keyHandler.hpp"
#include <iostream>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/err.h>

KeyHandler::KeyHandler() {}
KeyHandler::~KeyHandler() {}

int KeyHandler::generateKeyPair (int bits) {
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, 61337);
    
    int result = RSA_generate_key_ex(rsa, 2048, e, NULL);
    if (result != 0){
        std::cerr << ERR_get_error() << std::endl;
    }
    
    // TODO: write key-pairs to file
}