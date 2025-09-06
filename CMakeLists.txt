cmake_minimum_required(VERSION 3.10)
project(CecurePP)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenSSL
find_package(OpenSSL REQUIRED)

# Catch2
include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(catch2)

add_library(cecurepp_lib
    src/hasher.cpp
    src/keyHandler.cpp
    src/signHandler.cpp
    utils/fileUtils.cpp
)

target_include_directories(cecurepp_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/utils
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(cecurepp_lib
    OpenSSL::SSL
    OpenSSL::Crypto
)

add_executable(cecurepp src/main.cpp)
target_link_libraries(cecurepp PRIVATE cecurepp_lib)

add_subdirectory(tests)
