#include "utils.h"
#include <iostream>
using namespace std;
bool esOperador(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '/' || c == '^' || c == '%' || c == '^'; 
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
int tamCadena(char cadena[]){
    //int tam = 0;
    int i = 0;
    while(cadena[i] != '\0')
        i++;
    return i;
}