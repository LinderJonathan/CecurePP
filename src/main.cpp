#include <iostream>
#include <string>
#include "hasher.hpp"
#include "keyHandler.hpp"
int main () {

    // TODO: GUI loop

    // TODO: 1. generate private and public key 2. make password input optional

    std::string priv_path;
    std::string pub_path;
    std::string pwd;
    std::cin >> priv_path;
    std::cin >> pub_path;
    std::cin >> pwd;
    std::string error;
    KeyHandler kh;

    error = kh.generateKeyPair();
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

    // TODO: 
    return 0;
}