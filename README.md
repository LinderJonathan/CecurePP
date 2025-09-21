# CecurePP

## How to use
### VCPKG package management

CecurePP handle and resolve most dependencies through `vcpkg`. Into a suitable folder (i.e. C:/users/user/tools/), clone a copy of `vcpkg`:

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh  # or .\bootstrap-vcpkg.bat on Windows

```
### SDL2 dependency
SDL2 is in this project not handled by vcpkg, and needs to be installed manually on your machine. In your mingW shell,
```bash
pacman -S mingw-w64-x86_64-SDL2
pacman -S mingw-w64-x86_64-SDL2_ttf

```

            "includePath": [
                "${workspaceFolder}/**",
                "${vcpkgRoot}/x64-windows/include",
                "${vcpkgRoot}/x64-windows-static/include",
                "C:/msys64/mingw64/include",
                "C:/msys64/mingw64/include/SDL2"
            ],

### Build with CMake

To build yourself, a cmake installation is required. Given an installation, navigate to the root directory of the repository (`path/to/CecurePP/`) and perform the following commands to generate the build files:
```bash
mkdir build # perform only once
cd build
cmake ..
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake # is this needed?

```

Then, navigate back to the root directory of the repo and build:
```bash
cd ..
cmake --build build
```

### Testing: creating & running
Testing depends on the external unit testing framework [Catch2](https://github.com/catchorg/Catch2/tree/devel). 

Tests are built & compiled with CMake, and requires re-building once a test file has been written/edited and is ready for use:

```bash
cd /cecurepp/
cd build
cmake ..

cd ..
cmake --build build
```
It's possible to run tests either through the produced executable for the test target, or with ctest
```bash
./cecurepp/build/tests/fooTest # runs test file executable

./cecurepp/build/tests/fooTest -s # runs test file executable, provides more test info (recommended)
```

Adding a new test is easy. In `/cecurepp/tests/CMakeLists.txt`, test cases are defined as follows:
**TODO: show test case**
## Contribute

### Testing & Code coverage
