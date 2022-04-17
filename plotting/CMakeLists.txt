cmake_minimum_required(VERSION 3.17)
project(Plotting)

set(CMAKE_CXX_STANDARD 14)
add_executable(test_plot main.cpp  pbPlots.cpp pbPlots.hpp supportLib.hpp supportLib.cpp ../geometric_algo/convex_hull/convexhull_helper.h)
