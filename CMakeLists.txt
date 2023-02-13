cmake_minimum_required(VERSION 3.20)

project(RuntimeLoader)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

include_directories(Interface)

add_executable(${PROJECT_NAME} main.cpp SOClassLoader.h)
target_link_libraries(${PROJECT_NAME} dl)
add_subdirectory(SharedClass)
