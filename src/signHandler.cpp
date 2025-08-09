#include "signHandler.hpp"
#include "keyHandler.hpp"
#include "fileUtils.hpp"

#include <vector>
#include <openssl/evp.h>

// TODO: set EVP_MD type on construction
SignHandler::SignHandler (EVP_MD *digestType) : sig(NULL), type(digestType) {}

SignHandler::~SignHandler () {
    if (sig) {
        OPENSSL_free(sig);
        sig = NULL;
    }
}

std::string SignHandler::sign (EVP_PKEY *pkey, const std::string &filepath) {

    size_t siglen;
    ENGINE *e = NULL;
    EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new(pkey, e); // Private
    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
    
    // type points to a message digest algorithm (sha256, ...)
    if (!EVP_DigestSignInit(md_ctx, &pctx, this->type, e, pkey)) {
        EVP_MD_CTX_free(md_ctx);
        EVP_PKEY_CTX_free(pctx);
        return "Unnable to initialize file signing digest";
    }

    std::vector<unsigned char> data = readFileData(filepath);

    if (!EVP_DigestSignUpdate(md_ctx, data.data(), data.size())) {
        EVP_MD_CTX_free(md_ctx);
        EVP_PKEY_CTX_free(pctx);
        return "Unnable to hash file data into the context";
    }

    if (!EVP_DigestSignFinal(md_ctx, NULL, &siglen)) {
        EVP_MD_CTX_free(md_ctx);
        EVP_PKEY_CTX_free(pctx);
        return "Unnable to finalize sign of file (digest)";
    }

    // Calling EVP_DigestSignFinal with sig as NULL writes required buffer length to siglen
    unsigned char *sig = (unsigned char*)OPENSSL_malloc(siglen);
    if (!sig) {
        EVP_MD_CTX_free(md_ctx);
        EVP_PKEY_CTX_free(pctx);
        return "Unnable to allocate signature buffer";
    }

    if (!EVP_DigestSignFinal(md_ctx, sig, &siglen)) {
        EVP_MD_CTX_free(md_ctx);
        EVP_PKEY_CTX_free(pctx);
        OPENSSL_free(sig);
        return "Unnable to finalize sign of file (digest)";
    }
    
    EVP_MD_CTX_free(md_ctx);
    EVP_PKEY_CTX_free(pctx);
    this->sig = sig;

    return {};
}

std::string SignHandler::verify (EVP_PKEY *pubkey, EVP_PKEY_CTX *pubctx) {

    // TODO: *pubctx should be created from scratch


    size_t siglen;
    ENGINE *e = NULL;
    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();

    // if (!EVP_DigestVerifyInit())
    return {};
}