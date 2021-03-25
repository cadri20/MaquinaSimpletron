cmake_minimum_required(VERSION 3.17)
project(MaquinaSimpletron)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MaquinaSimpletron
        instrucciones.h
        main.cpp
        Simpletron.cpp
        Simpletron.h TablaSimbolos.cpp TablaSimbolos.h
        Compilador/evaluarPostfijo.cpp Compilador/evaluarPostfijo.h Compilador/postfijo.cpp
        Compilador/utils.cpp Compilador/utils.h Compilador/type.h Compilador/Compilador.cpp Compilador/Compilador.h)
