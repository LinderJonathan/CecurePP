cmake_minimum_required(VERSION 3.10)
project(CecurePP)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenSSL
find_package(OpenSSL REQUIRED)

# SDL
# find_package(SDL2 CONFIG REQUIRED) # Apparently makes CMake look for SDL2config.cmake instead of SDL2.cmake
find_library(SDL2_LIBRARY NAMES SDL2 PATHS C:/msys64/mingw64/lib)
find_path(SDL2_INCLUDE_DIR SDL.h PATHS C:/msys64/mingw64/include/SDL2)

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
    src/graphics/windowHandler.cpp
)

target_include_directories(cecurepp_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/utils
    ${CMAKE_SOURCE_DIR}/src
    ${SDL2_INCLUDE_DIR}

)

target_link_libraries(cecurepp_lib PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
    ${SDL2_LIBRARY}
)

add_executable(cecurepp src/main.cpp)
target_link_libraries(cecurepp PRIVATE cecurepp_lib)

if(MINGW)
    set_target_properties(cecurepp PROPERTIES LINK_FLAGS "-mconsole")
endif()

add_subdirectory(tests)