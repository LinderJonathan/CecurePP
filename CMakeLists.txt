cmake_minimum_required(VERSION 3.10)
project(CecurePP)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenSSL
find_package(OpenSSL REQUIRED)

# TODO: make this shit build
#cmake --trace-expand -B build -S . \
#  -DCMAKE_TOOLCHAIN_FILE=C:/Users/linde/tools/vcpkg/scripts/buildsystems/vcpkg.cmake \
#  -DVCPKG_TARGET_TRIPLET=x64-windows | grep SDL2


# SDL
find_package(SDL2 CONFIG REQUIRED) # Apparently makes CMake look for SDL2config.cmake instead of SDL2.cmake
include_directories("C:/msys64/mingw64/include/SDL2")
link_directories("C:/msys64/mingw64/lib")

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

target_link_libraries(cecurepp_lib PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
    SDL2main #(use if we swant SDL2 main entry wrapper)
    SDL2
)

add_executable(cecurepp src/main.cpp)
target_link_libraries(cecurepp PRIVATE cecurepp_lib)

add_subdirectory(tests)
