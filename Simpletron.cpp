#include <iostream>
using namespace std;

#include "Simpletron.h"
#include "instrucciones.h"


Simpletron::Simpletron(){
    contador = 0;
}
void Simpletron::cargarPrograma(int programa[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        memoria[i] = programa[i];
    }
    numeroDeInstrucciones = tamanio;
}
void Simpletron::cargarInstruccion(int instruccion){
    codigoDeOperacion = instruccion / 100;
    operando = instruccion % 100;
}

int Simpletron::ejecutarInstruccion(int operacion){
    bool seBifurco = false;
    switch(operacion){
        case Instrucciones::LEER :
            cin >> memoria[operando];
            break;
        case Instrucciones::ESCRIBIR :
            cout << memoria[operando] << endl;
            break;
        case Instrucciones::CARGAR :
            acumulador = memoria[operando];
            break;
        case Instrucciones::ALMACENAR :
            memoria[operando] = acumulador;
            break;
        case Instrucciones::SUMAR :
            acumulador+= memoria[operando];
            break;
        case Instrucciones::RESTAR :
            acumulador-= memoria[operando];
            break;
        case Instrucciones::MULTIPLICAR :
            acumulador*= memoria[operando];
            break;
        case Instrucciones::DIVIDIR :
            acumulador/= operando;
            break;
        case Instrucciones::BIFURCAR :
            contador = operando;
            seBifurco = true;
            break;
        case Instrucciones::BIFURCAR_NEG :
            if(acumulador < 0){
                contador = operando;
                seBifurco = true;
                //cout << "Se bifurco a la instruccion " << contador;
            }
            break;
        case Instrucciones::BIFURCAR_CERO :
            if(acumulador == 0){
                contador = operando;
                seBifurco = true;
            }
            break;
        case Instrucciones::ALTO:
            return 1;
        default:
            cout << "Instruccion no válida" << endl;
    }
    if(!seBifurco)
        contador++;
    return 0;

    
}

void Simpletron::ejecutar(){
    while(1){
        cargarInstruccion(memoria[contador]);
        //cout << "instruccion cargada " << memoria[contador] << endl; 
        int terminar = ejecutarInstruccion(codigoDeOperacion);
        if(terminar == 1 || contador >= numeroDeInstrucciones){
            break;
        }        
    }
}