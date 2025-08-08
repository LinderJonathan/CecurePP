#include "signHandler.hpp"
#include "keyHandler.hpp"
#include "fileUtils.hpp"

#include <vector>
#include <openssl/evp.h>

SignHandler::SignHandler () : sig(NULL) {}

SignHandler::~SignHandler () {
    if (sig) {
        OPENSSL_free(sig);
        sig = NULL;
    }
}

std::string SignHandler::sign (EVP_PKEY *pkey, EVP_PKEY_CTX *pctx, EVP_MD *type, const std::string &filepath) {

    size_t siglen;
    ENGINE *e = NULL;
    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
    
    // type points to a message digest algorithm (sha256, ...)
    if (!EVP_DigestSignInit(md_ctx, &pctx, type, e, pkey)) {
        EVP_MD_CTX_free(md_ctx);
        return "Unnable to initialize file signing digest";
    }

    std::vector<unsigned char> data = readFileData(filepath);

    if (!EVP_DigestSignUpdate(md_ctx, data.data(), data.size())) {
        EVP_MD_CTX_free(md_ctx);
        return "Unnable to hash file data into the context";
    }

    if (!EVP_DigestSignFinal(md_ctx, NULL, &siglen)) {
        EVP_MD_CTX_free(md_ctx);
        return "Unnable to finalize sign of file (digest)";
    }

    // Calling EVP_DigestSignFinal with sig as NULL writes required buffer length to siglen
    unsigned char *sig = (unsigned char*)OPENSSL_malloc(siglen);
    if (!sig) {
        return "Unnable to allocate signature buffer";
    }

    if (!EVP_DigestSignFinal(md_ctx, sig, &siglen)) {
        EVP_MD_CTX_free(md_ctx);
        OPENSSL_free(sig);
        return "Unnable to finalize sign of file (digest)";
    }

    this->sig = sig;
    return {};
}

std::string SignHandler::verify () {

    return {};
}