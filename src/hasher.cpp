#include <hasher.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <openssl/sha.h>

std::string Hasher::hash(const std::string &filePath) {

    std::ifstream f(filePath, std::ios::binary);

    f.seekg(0, std::ios::end);
    std::streamsize ibufSize = f.tellg();
    f.seekg(0, std::ios::beg);

    std::vector<unsigned char> ibuf(ibufSize);
    unsigned char obuf[64];

    if (!f.is_open()) {
        // TODO: correct error handling for this class?
        std::cerr << "Failed to open file for reading";
    }

    // read from file into starting adress of 
    f.read(reinterpret_cast<char*>(ibuf.data()), ibufSize);

    SHA256(ibuf.data(), ibufSize, obuf);


    std::ostringstream oss;
    for (int i = 0; i < 64; i++){
        oss << std::hex << (int)obuf[i];
    }

    // TODO: test this tommorow
    std::string hash = oss.str();
    std::cout << "hash: " << hash << std::endl;
    return hash;
}