#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

class Hasher {

    public:
    Hasher();
    ~Hasher();

    std::string hash(const std::string &filePath);
    std::size_t operator()(const std::string &filePath) const;
};