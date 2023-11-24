cmake_minimum_required(VERSION 3.10)
project(IntersectionOfTwoLinkedLists)

add_executable(IntersectionOfTwoLinkedLists main.cpp)
include_directories("../MyLibrary")
target_link_libraries(IntersectionOfTwoLinkedLists ListNode)