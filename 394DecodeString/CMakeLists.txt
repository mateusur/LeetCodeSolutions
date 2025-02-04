add_executable(394DecodeString_test main_test.cpp)

target_link_libraries(394DecodeString_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(394DecodeString_test)
