#include "utils.h"
#include <iostream>
#include "instrucciones.h"

using namespace std;
bool esOperador(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '/' || c == '^' || c == '%' || c == '^'; 
}

bool esOperando(char c){
    return isalpha(c) || isdigit(c);
}

int calcular(int x, int y, char operador){
    if(operador == '+')
        return x + y;
    if(operador == '-')
        return x - y;
    if(operador == '*')
        return x * y;
    if(operador == '/')
        return x / y;
    if(operador == '%')
        return x % y;
    if(operador == '^'){
        int potencia = 1;
        for(int i = 1; i <= y; i++){
            potencia*= x;
        }
        return potencia;
    }
    cout << "El operador ingresado no es valido:" << operador << endl;
    return 0;
}

void calcular(int x, int y, char operador, vector<int> *instrucciones){
    instrucciones->push_back(CARGAR*100 + x);
    int operacion;
    if(operador == '+'){
        operacion = SUMAR*100;
    }
    if(operador == '-')
        operacion = RESTAR*100;
    if(operador == '*')
        operacion = MULTIPLICAR*100;
    if(operador == '/')
        operacion = DIVIDIR * 100;

    instrucciones->push_back(operacion + y);
}

int tamCadena(char cadena[]){
    //int tam = 0;
    int i = 0;
    while(cadena[i] != '\0')
        i++;
    return i;
}