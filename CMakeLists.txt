cmake_minimum_required(VERSION 3.12)
project(libpoyo)

set(CMAKE_CXX_STANDARD 14)
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES library.cpp)
add_library(libpoyo SHARED ${SOURCE_FILES})
