find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(test main.cpp ${SRC})

target_include_directories(test PUBLIC ${OpenCV_INCLUDE_DIRS} include)

target_link_libraries(test ${OpenCV_LIBS} )

target_link_libraries(test hik_driver)

link_directories("${PROJECT_DIR}/hik_driver/lib/64")             #从该路径下寻找需要的库