#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../../src/keyHandler.hpp"

// TODO: probably just use CMake instead to fix building isses

TEST_CASE ("Key handler object is created correctly. key structures are present after creation", "[]"){
    // Create keyHandler object and assert no key pair present

    // This code will be executed once for each section
    KeyHandler kh;

    REQUIRE(kh.pkey == nullptr);

    SECTION("");
}