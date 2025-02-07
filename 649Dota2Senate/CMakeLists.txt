add_executable(649Dota2Senate_test main_test.cpp)

target_link_libraries(649Dota2Senate_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(649Dota2Senate_test)
