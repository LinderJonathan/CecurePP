#include <iostream>
#include <string>
#include "hasher.hpp"
int main () {

    Hasher h;

    std::string hash = h.hash("test/helloWorld.txt");
    std::cout << hash << std::endl;
    return 0;
}