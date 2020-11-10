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
}
void Simpletron::cargarInstruccion(int instruccion){
    codigoDeOperacion = instruccion / 100;
    operando = instruccion % 100;
}

void Simpletron::ejecutarInstruccion(int operacion){
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
            acumulador/= memoria[operando];
            break;
        case Instrucciones::BIFURCAR :
            contador = memoria[operando];
            break;
        case Instrucciones::BIFURCAR_NEG :
            if(acumulador < 0)
                contador = memoria[operando];
            break;
        case Instrucciones::BIFURCAR_CERO :
            if(acumulador == 0)
                contador = memoria[operando];
            break;
        default:
            cout << "Instruccion no válida" << endl;
    }
}

void Simpletron::ejecutar(){
    while(memoria[contador] != ALTO){
        cargarInstruccion(memoria[contador]);
        ejecutarInstruccion(codigoDeOperacion);
        if(codigoDeOperacion != BIFURCAR && codigoDeOperacion != BIFURCAR_NEG && codigoDeOperacion != BIFURCAR_CERO)
            contador++;              
    }
}