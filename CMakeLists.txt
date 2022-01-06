cmake_minimum_required(VERSION 3.17)
project(Coursera_Part1)

set(CMAKE_CXX_STANDARD 14)

add_executable(MergeSort MergeSort.cpp mergeSorting.h vector_exmaple.cpp)
add_executable(Insertion InsertionSort.cpp)
add_executable(QuickSort main.cpp quickSorting.h)
add_executable(Shuffle shuffle.cpp)
add_executable(JarvisMarch JarvisMarch.cpp Point.h pbPlots.hpp pbPlots.cpp supportLib.cpp supportLib.hpp convexhull_helper.h)
add_executable(Graham_scan Graham_scan.cpp Graham_scan.h Point.h pbPlots.hpp pbPlots.cpp supportLib.cpp supportLib.hpp convexhull_helper.h)
