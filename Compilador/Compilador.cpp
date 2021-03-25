//
// Created by Hp on 24/03/2021.
//

#include <instrucciones.h>
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
            pila.push(getUbicacionMem(charActual));
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

int Compilador::getUbicacionMem(char simbolo) {
    for(EntradaTabla entrada: tablaSimbolos){
        if(entrada.simbolo == simbolo)
            return entrada.ubicacion;
    }
    return 0;
}
