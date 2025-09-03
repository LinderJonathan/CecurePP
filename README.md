# CecurePP

## How to use
1. VCPKG package management

CecurePP handle and resolve dependencies through `vcpkg`. Into a suitable folder (i.e. C:/users/user/tools/), clone a copy of `vcpkg`:

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh  # or .\bootstrap-vcpkg.bat on Windows
```

2. Build with CMake

To build yourself, a cmake installation is required. Given an installation, navigate to the root directory of the repository (`path/to/CecurePP/`) and perform the following commands to generate the build files:
```bash
mkdir build # perform only once
cd build
cmake ..
```

Then, navigate back to the root directory of the repo and build:
```bash
cd ..
cmake --build build
```

3. Testing
Testing depends on the external unit testing framework [Catch2](https://github.com/catchorg/Catch2/tree/devel). 

Tests are written, and compiled with `g++`. To obtain the test binary, it is extremely important to add the `#define CATCH_CONFIG_MAIN` in each test file.

Tests can then be compiled 

## Contribute

### Testing & Code coverage
