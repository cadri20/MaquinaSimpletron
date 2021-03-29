//
// Created by Hp on 24/03/2021.
//

#include "instrucciones.h"
#include <cstring>
#include "Compilador.h"

vector<int> Compilador::evaluarExpresionPostfijo(vector<char> postfijo, int dirAlmacenar){
    int contadorResultados = dirVarActual;
    postfijo.push_back('\0');
    stack<int> pila;
    int resultado;
    size_t tamanio = postfijo.size();
    vector<int> instrucciones;
    for(int i = 0; i < tamanio; i++){
        char charActual = postfijo[i];
        if(esOperando(charActual))
            pila.push(tabla.getUbicacionMem(charActual));
        else if(esOperador(charActual)){
            int x = pila.top();
            pila.pop();
            int y = pila.top();
            pila.pop();
            calcular(y,x,charActual, &instrucciones);
            instrucciones.push_back(ALMACENAR*100 + contadorResultados);
            pila.push(contadorResultados);
            contadorResultados--;

        }else if(charActual == '\0'){
            resultado = pila.top();
            pila.pop();
            instrucciones.push_back(CARGAR*100 + resultado);
            instrucciones.push_back(ALMACENAR*100 + dirAlmacenar);
            break;
        }

        return instrucciones;
    }

}



Compilador::Compilador(char *pathArchivoFuente) {
    pathArchivoEntrada = pathArchivoFuente;
    Compilador::contInstruc = 0;
    Compilador::dirVarActual = 99;

    for(int i = 0; i < 100; i++)
        banderas[i] = -1;
}

void Compilador::primeraPasada() {
    ifstream archivoEntrada(pathArchivoEntrada, ios::in);

    if(!archivoEntrada){
        cerr << "No se pudo abrir el archivo" << endl;
    }
    char *entrada;
    std::cout << "Se abrio el archivo" << endl;
    while(archivoEntrada >> entrada){
        std::cout << "Entro en el bucle" << endl;
        char *linea = strtok(entrada, " ");
        tabla.add(linea, 'L', contInstruc);
        string cmd = strtok(0, " ");

        if(cmd == "input"){
            string simbolo = strtok(0, " ");
            int ubicacion = tabla.getUbicacionMem(simbolo);
            if(ubicacion == -1) { //el simbolo no se encuentra en la tabla
                tabla.add(simbolo, 'V', dirVarActual);
                ubicacion = dirVarActual;
                dirVarActual--;
            }

            instrucciones.push_back(LEER*100 + ubicacion);
        }
        else if(cmd == "print"){
            string simbolo = strtok(0, " ");
            int ubicacion = tabla.getUbicacionMem(simbolo);
            instrucciones.push_back(ESCRIBIR*100 + ubicacion);
        }
    }

    std::cout << "Se salio del bucle" << endl;
}

void Compilador::segundaPasada(string nombreArchivoSalida) {
    for(int i = 0; i < 100; i++){
        int bandera = banderas[i];
        if(bandera == -1)
            continue;

        int ubicacion = tabla.getUbicacionMem(to_string(bandera));
        instrucciones[i] = instrucciones[i] + ubicacion;
    }

    ofstream codigoObj(nombreArchivoSalida, ios::out);
    if( !codigoObj){
        cerr << "No se pudo crear el archivo" << endl;
        exit(1);
    }

    for(int inst: instrucciones){
        codigoObj << inst << endl;
    }

}




