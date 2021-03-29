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
#include <iostream>
#include <fstream>
using std::ofstream;
#include <string>
#include "TablaSimbolos.h"
using namespace std;

class Compilador {
private:
    int banderas[100];
    TablaSimbolos tabla;
    int contInstruc;
    int dirVarActual;
    vector<int> instrucciones;
    vector<int> evaluarExpresionPostfijo(vector<char> postfijo, int dirAlmacenar);
    char *pathArchivoEntrada;
public:
    Compilador(char *pathArchivoFuente);
    void primeraPasada();
    void segundaPasada(string);
};


#endif //MAQUINASIMPLETRON_COMPILADOR_H
