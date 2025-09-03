# TESTS

add_executable(generateRsaHandlerTest
    generateRsaHandlerTest.cpp
)

# INCLUDE
target_include_directories( generateRsaHandlerTest PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# TARGET SOURCES
target_sources( generateRsaHandlerTest PRIVATE
    ${CMAKE_SOURCE_DIR}/src/hasher.cpp
    ${CMAKE_SOURCE_DIR}/src/keyHandler.cpp
    ${CMAKE_SOURCE_DIR}/src/signHandler.cpp
)

# REGISTER TESTS
add_test(NAME generateRsaHandlerTest COMMAND generateRsaHandlerTest)