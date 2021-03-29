//
// Created by Hp on 24/03/2021.
//

#include "TablaSimbolos.h"

TablaSimbolos::TablaSimbolos() : posTabla(0) {
}

void TablaSimbolos::add(string simbolo, char tipo, int ubicacion) {
    tabla[posTabla] = {simbolo, tipo, ubicacion};
    posTabla++;
}

int TablaSimbolos::getUbicacionMem(string simbolo) {
    for(EntradaTabla entrada: tabla){
        if(entrada.simbolo == simbolo)
            return entrada.ubicacion;
    }
    return -1;
}

int TablaSimbolos::getUbicacionMem(char simbolo) {
    string cadena;
    cadena.push_back(simbolo);
    getUbicacionMem(cadena);
}


