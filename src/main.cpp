#include <iostream>
#include <string>
#include "hasher.hpp"
#include "keyHandler.hpp"
int main () {



    // TODO: generate private and public key

    std::string fp;
    std::string pwd;
    std::cin >> fp;
    std::cin >> pwd;
    std::string error;
    KeyHandler kh;

    error = kh.generateKeyPair();
    if (!error.empty()) {
        // write error to GUI, write to terminal for now
        std::cout << error << std::endl;
        return 0;
    }

    error = kh.storeKeyPair(pwd, "../test_pkcs8/test.pem");
    if (!error.empty()) {
        // write error to GUI, write to terminal for now
        std::cout << error << std::endl;
        return 0;
    }
    return 0;
}