#include "Compilador.h"

//
// Created by Hp on 25/03/2021.
//
#include <iostream>
int main(int argc, char **argv){
    Compilador comp(argv[1]);
    std::cout << "Se ejecuto constructor" << endl;
    comp.primeraPasada();
    std::cout << "Se ejecuto segunda pasada" << endl;
    comp.segundaPasada(argv[2]);
    std::cout << "Se ejecuto con exito" << std::endl;
}
