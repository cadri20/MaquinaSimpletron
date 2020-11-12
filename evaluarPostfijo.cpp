#include <cctype>
#include <stack>
using namespace std;
#include <vector>
#include "utils.h"
#include "evaluarPostfijo.h"
#include <iostream>
using namespace std;
int evaluarExpresionPostfijo(vector<char> postfijo){
    postfijo.push_back('\0');
    stack<int> pila;
    int resultado;
    size_t tamanio = postfijo.size();
    for(int i = 0; i < tamanio; i++){
        char charActual = postfijo[i];
        if(isdigit(charActual))
            pila.push(charActual - '0');
        else if(esOperador(charActual)){
            int x = pila.top();
            pila.pop();
            int y = pila.top();
            pila.pop();
            pila.push(calcular(y,x,charActual));
        }else if(charActual == '\0'){
            resultado = pila.top();
            pila.pop();
            break;
        }
        
    }
    return resultado;
}

