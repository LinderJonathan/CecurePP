# tests
add_executable(generateRsaHandlerTest generateRsaHandlerTest.cpp)

# link
target_link_libraries(generateRsaHandlerTest PRIVATE
    cecurepp_lib
    Catch2::Catch2WithMain
)

# register
include(CTest)
include(Catch)
catch_discover_tests(generateRsaHandlerTest)
