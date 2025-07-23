#include "hasher.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

Hasher::Hasher() {}
Hasher::~Hasher() {}

std::string Hasher::hash(const std::string &filePath) {

    std::ifstream f(filePath, std::ios::binary);
    
    if (!f.is_open()) {
        std::cerr << "Failed to open file for reading \n";
    }

    f.seekg(0, std::ios::end);
    std::streamsize ibufSize = f.tellg();
    f.seekg(0, std::ios::beg);
    std::vector<unsigned char> ibuf(ibufSize);
    unsigned char obuf[32];
 
    f.read(reinterpret_cast<char*>(ibuf.data()), ibufSize);

    SHA256(ibuf.data(), ibufSize, obuf);

    std::ostringstream oss;
    for (uint8_t i = 0; i < 32; i++){
        oss << std::setw(2) << std::setfill('0') << std::hex << (int)obuf[i];
    }

    std::string hash = oss.str();
    return hash;
}