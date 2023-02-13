cmake_minimum_required(VERSION 3.20)

project(SumClass VERSION 1.0 DESCRIPTION "process two numbers and return sum")

set(CMAKE_CXX_STANDARD 23)

include_directories(../Interface)

add_library(${PROJECT_NAME} SHARED ../Interface/ITemplateClass.h Sum.h Sum.cpp)
