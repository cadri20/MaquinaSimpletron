//
// Created by Hp on 24/03/2021.
//

#ifndef MAQUINASIMPLETRON_TABLASIMBOLOS_H
#define MAQUINASIMPLETRON_TABLASIMBOLOS_H

#include "type.h"
#include <string>
using namespace std;
class TablaSimbolos {
private:
    EntradaTabla tabla[100];
    int posTabla;
public:
    TablaSimbolos();
    void add(string simbolo, char tipo, int ubicacion);
    int getUbicacionMem(string simbolo);
    int getUbicacionMem(char simbolo);
};


#endif //MAQUINASIMPLETRON_TABLASIMBOLOS_H
