cmake_minimum_required(VERSION 3.10)

project(MyLibrary)

add_library(TreeNode STATIC "TreeNode.cpp" "TreeNode.h")
add_library(ListNode STATIC "ListNode.cpp" "ListNode.h")