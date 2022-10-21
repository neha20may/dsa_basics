cmake_minimum_required(VERSION 3.23)
project(linked_list)

set(CMAKE_CXX_STANDARD 14)
add_executable(linked_list driver.cpp LinkedList.cpp LinkedList.h)
add_executable(oddeven odd_even.cpp odd_even.h)
add_executable(linkedhashmap linked_hash_map_driver.cpp LinkedHashMap.cpp LinkedHashMap.h DLinkedList.h)