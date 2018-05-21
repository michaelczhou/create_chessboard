CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(chessboard)

FIND_PACKAGE(OpenCV REQUIRED)
MESSAGE("include_dir = " ${OpenCV_INCLUDE_DIRS})

add_executable ( create src/create.cpp)
target_link_libraries(create ${OpenCV_LIBS})
add_executable ( create1 src/create1.cpp)
target_link_libraries(create1 ${OpenCV_LIBS})


