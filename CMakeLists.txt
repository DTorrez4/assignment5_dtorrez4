cmake_minimum_required(VERSION 4.1)
project(assignment5_vector_string)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment5_vector_string main.cpp pixel.h)

#i put the file path where i save the pixels.dat file. that is how i copied it over.

file(COPY "C:/Users/torre/Downloads/pixels.dat" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
