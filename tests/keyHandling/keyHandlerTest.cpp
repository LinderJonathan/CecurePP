#include "catch_amalgamated.hpp"
#include "../../src/keyHandler.hpp"

// TODO: start with test cases after multiple algorithms are supported
TEST_CASE ("Key handler object is created correctly. key structures are present after creation", "[generatekeypair]"){
    // Create keyHandler object and assert no key pair present
    KeyHandler kh;

    REQUIRE(kh.pkey == NULL);

    SECTION("")
}