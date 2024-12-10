cmake_minimum_required(VERSION 3.17)

project(test)

set(CMAKE_CXX_FLAGS"-std=c++11")

set(CMAKE_PREFIX_PATH"/usr/lid/x86_64-linux-gnu/cmake")

find_package(OpenCV REQUIRED)

add_executable(test main.cpp)

target_include_directories(test PUBLIC ${OpenCV_INCLUDE_DIRS})

target_link_libraries(test ${OpenCV_LIBS})