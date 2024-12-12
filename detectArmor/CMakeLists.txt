cmake_minimum_required(VERSION 3.10)

project(test)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/opencv4")

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SRC SRC/src/*.cpp hik_camera/src/*.cpp src/*.cpp)

link_directories("${PROJECT_DIR}/hik_driver/lib/64")

add_executable(test main.cpp ${SRC})

target_include_directories(test PUBLIC ${OpenCV_INCLUDE_DIRS} include hik_camera/include hik_driver/include)

target_link_libraries(test ${OpenCV_LIBS} )

target_link_libraries(${PROJECT_NAME}  -lX11)

target_link_libraries(${PROJECT_NAME} libMvCameraControl.so )
