cmake_minimum_required(VERSION 3.10)

project(test)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/opencv4")

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SRC src/Detect/*.cpp src/DetectR/*.cpp src/DetectBuff/*.cpp)

add_executable(test main.cpp ${SRC})

target_include_directories(test PUBLIC ${OpenCV_INCLUDE_DIRS} include)

target_link_libraries(test ${OpenCV_LIBS})