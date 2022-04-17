cmake_minimum_required(VERSION 3.17)
project(Convex_hull)

set(CMAKE_CXX_STANDARD 14)
add_executable(JarvisMarch JarvisMarch.cpp Point.h ../../plotting/pbPlots.hpp ../../plotting/pbPlots.cpp ../../plotting/supportLib.cpp ../../plotting/supportLib.hpp convexhull_helper.h)
add_executable(Graham_scan Graham_scan.cpp Graham_scan.h Point.h ../../plotting/pbPlots.hpp ../../plotting/pbPlots.cpp ../../plotting/supportLib.cpp ../../plotting/supportLib.hpp convexhull_helper.h)