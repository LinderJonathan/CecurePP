#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

#include <openssl/sha.h>
class Hasher {

    Hasher();
    ~Hasher();

    public:
    std::string hash(const std::string &filePath);

    std::size_t operator()(const std::string &filePath) const;
};