cmake_minimum_required(VERSION 3.25)
project(Tubes-1-OOP-O08)


add_executable(Tubes-1-OOP-O08
    src/main.cpp)

set_target_properties(Tubes-1-OOP-O08
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/../bin)