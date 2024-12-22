cmake_minimum_required(VERSION 3.17)
project(test)
set(CMAKE_CXX_STANDARD 17)
add_executable(test main.cpp ${SRC} )

find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})