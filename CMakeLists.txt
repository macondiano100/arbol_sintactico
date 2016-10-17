cmake_minimum_required(VERSION 3.6)
project(Arbol_Sintactico)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Parser.cpp Parser.h lexico/lexico.cpp lexico/Buffered_Stream.cpp lexico/Token.cpp)
add_executable(Arbol_Sintactico ${SOURCE_FILES})