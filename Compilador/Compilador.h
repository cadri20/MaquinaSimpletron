//
// Created by Hp on 24/03/2021.
//

#ifndef MAQUINASIMPLETRON_COMPILADOR_H
#define MAQUINASIMPLETRON_COMPILADOR_H
#include <vector>
using namespace std;
#include <stack>
using namespace std;
#include "utils.h"
#include "type.h"

class Compilador {
private:
    int banderas[100];
    EntradaTabla tablaSimbolos[100];
    int contInstruc;
    int dirVarActual;
    vector<int> evaluarExpresionPostfijo(vector<char> postfijo, int dirAlmacenar);
    int getUbicacionMem(char simbolo);
};


#endif //MAQUINASIMPLETRON_COMPILADOR_H
