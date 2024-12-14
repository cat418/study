cmake_minimum_required(VERSION 3.10)

project(all)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)#c++标准必须严格满足

add_subdirectory(armor_detect)

add_subdirectory(HikDriver)