cmake_minimum_required(VERSION 3.10)
project(LinkedListCycle)

add_executable(LinkedListCycle main.cpp)
include_directories("../MyLibrary")
target_link_libraries(LinkedListCycle ListNode)