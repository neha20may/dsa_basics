cmake_minimum_required(VERSION 3.17)
project(Coursera_Part1)

set(CMAKE_CXX_STANDARD 14)

add_executable(MergeSort MergeSort.cpp mergeSorting.h vector_exmaple.cpp  ex.cpp)
add_executable(Insertion InsertionSort.cpp)
add_executable(QuickSort main.cpp  quickSorting.h)
add_executable(Shuffle shuffle.cpp)
add_executable(ConvexHull JarvisMarch.cpp Point.h pbPlots.hpp pbPlots.cpp supportLib.cpp supportLib.hpp convexhull_helper.h)
#find_package(PythonLibs REQUIRED)
##find_package (BZip2)
#include_directories("C:\\Users\\neha2\\AppData\\Local\\Programs\\Python\\Python310;C:\\Users\\neha2\\AppData\\Local\\Programs\\Python\\Python310\\include;C:\\Users\\neha2\\AppData\\Local\\Programs\\Python\\Python310\\Lib\\site-packages\\numpy\\core\\include")

#find_package(PythonLibs 2.7)
#find_package(Python2 COMPONENTS Interpreter Development NumPy REQUIRED)
#include_directories(${PYTHON_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})
add_executable(InsertionSort InsertionSort.cpp)
#target_link_libraries(InsertionSort ${PYTHON_LIBRARIES} Python::NumPy )

#target_link_libraries(Coursera_Part1
#        PRIVATE
#        ${PYTHON_LIBRARIES}
#        Python2::NumPy
#        )