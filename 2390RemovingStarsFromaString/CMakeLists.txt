add_executable(2390RemovingStarsFromaString_test main_test.cpp)

target_link_libraries(2390RemovingStarsFromaString_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(2390RemovingStarsFromaString_test)