#include "signHandler.hpp"
#include "keyHandler.hpp"

#include <openssl/evp.h>

std::string SignHandler::sign (EVP_PKEY *pkey, EVP_PKEY_CTX *pctx, EVP_MD *type, const std::string &filepath) {
    
    ENGINE *e = NULL;
    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
    
    EVP_DigestSignInit(md_ctx, &pctx, type, e, pkey);

    // TODO: error handle EVP_digestSignInit

    // EVP_DigestSignUpdate(md_ctx)

}

std::string SignHandler::verify () {
    
}