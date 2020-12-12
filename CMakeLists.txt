cmake_minimum_required(VERSION 3.17)
project(MaquinaSimpletron)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MaquinaSimpletron
        instrucciones.h
        main.cpp
        Simpletron.cpp
        Simpletron.h)
