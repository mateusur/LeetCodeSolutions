add_executable(605CanPlaceFlowers_test main_test.cpp)

target_link_libraries(605CanPlaceFlowers_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(605CanPlaceFlowers_test)
