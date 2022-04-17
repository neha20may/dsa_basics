cmake_minimum_required(VERSION 3.17)
project(Coursera_Part1)

set(CMAKE_CXX_STANDARD 14)

add_executable(MergeSort sorting/MergeSort.cpp sorting/mergeSorting.h sorting/vector_exmaple.cpp)
add_executable(Insertion sorting/InsertionSort.cpp)
add_executable(QuickSort main.cpp sorting/quickSorting.h)
add_executable(Shuffle shuffling/shuffle.cpp)
