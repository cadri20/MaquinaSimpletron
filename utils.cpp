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
    if(operador = '%')
        return x % y;
    
    if(operador == '^')
        return x ^ y;
    cout << "El operador ingresado no es valido:" << operador << endl;
    return 0;
}