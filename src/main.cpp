#include <iostream>
#include <string>
#include <vector>
#include "hasher.hpp"
#include "keyHandler.hpp"
#include "signHandler.hpp"
#include "fileUtils.hpp"
#include "interface/startWindow.cpp"


int main () {

    // TODO: GUI loop

    // TODO: 1. generate private and public key 2. make password input optional

    uint8_t test;
    std::cout << "Enter 0 to run, 1 to test" << std::endl;
    std::cin >> test;

    if (test) {
        std::cout << "Enter 1. private path 2. public path 3. pwd" << std::endl;
        std::string priv_path;
        std::string pub_path;
        std::string pwd;
        std::cin >> priv_path;
        std::cin >> pub_path;
        std::cin >> pwd;
        std::string error;
        KeyHandler kh;
        // SignHandler sh();

        error = kh.generateKeyPairHandler(Algorithm::RSA);
        if (!error.empty()) {
            // write error to GUI, write to terminal for now
            std::cout << error << std::endl;
            return 0;
        }

        if (!priv_path.compare(pub_path)) {
            // TODO: handle file path selection
        }

        error = kh.storeKeyPair(pwd, priv_path, pub_path);
        if (!error.empty()) {
            // write error to GUI, write to terminal for now
            std::cout << error << std::endl;
            return 0;
        }

        std::cout << "Loading private key" << std::endl;
        EVP_PKEY *pkey = NULL;
        error = kh.loadKeyPrivate(&pkey, "");
        if (!error.empty()) {
            std::cout << "private key was null" << std::endl;
        }
    }
    
    std::vector<unsigned char> fc = readFileData("../test/helloWorld.txt");
    for (auto c : fc) {
        std::cout << c << std::endl;
    }


    // TODO: test signing

    // TODO: test verifying
    return 0;
}