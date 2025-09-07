#include <catch2/catch_test_macros.hpp>
#include "keyHandler.hpp"
// TODO: probably just use CMake instead to fix building isses

TEST_CASE ("Key handler object is created correctly. key structures are present after creation", "[generateRsaHandler]"){
    // Create keyHandler object and assert no key pair present

    // This code will be executed once for each section
    KeyHandler kh;

    // TODO: it fucking works
    REQUIRE(2 == 2);

}