cmake_minimum_required(VERSION 3.10)
project (CecurePP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO: find openSSL and crypto++
find_package(OpenSSL REQUIRED)

# TODO: add executable
add_executable(cecurepp
    src/main.cpp 
    src/hasher.cpp    
)

# TODO: link openSSL
target_link_libraries(cecurepp OpenSSL::SSL OpenSSL::Crypto)