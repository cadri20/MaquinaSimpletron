#include <iostream>
using namespace std;
#include<stack>
using namespace std;
#include<list>
using namespace std;
#include <cctype>
using namespace std;
#include <vector>
using namespace std;
int valorPrecedencia(char);
int precedencia(char op1, char op2);
bool esOperador(char c);
void imprimirArreglo(char arreglo[], char length){
    for(int i = 0; i < length; i++)
        cout << arreglo[i];
    cout << endl;
}
void convertirAPostfijo(char expresion[], int tam_expresion, vector<char> &postfijo){
    stack<char> pila;
    pila.push('(');
    //list<char> postfijo;
    char infijo[tam_expresion + 1];
    for(int i = 0; i < tam_expresion; i++){
        infijo[i] = expresion[i];
    }
    infijo[tam_expresion] = ')';
    imprimirArreglo(infijo,tam_expresion + 1);
    for(int i = 0; i <= tam_expresion; i++){
        if(pila.empty())
            break;
        char charActual = infijo[i];
        if(isdigit(charActual))
            postfijo.push_back(charActual);
        else if(charActual == '(')
            pila.push(charActual);
        else if(esOperador(charActual)){
            while(esOperador(pila.top())){
                char elementoSuperior = pila.top();
                if(precedencia(elementoSuperior,charActual) == -1)
                    break;
                pila.pop();
                postfijo.push_back(elementoSuperior);
            }
            pila.push(charActual);
        }else if(charActual == ')'){
            while(pila.top() != '('){
                postfijo.push_back(pila.top());
                pila.pop();
            }
            pila.pop();
        }
    }
    
    
}
bool esOperador(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '/' || c == '^' || c == '%'; 
}
int precedencia(char op1, char op2){
    int precedencia1 = valorPrecedencia(op1);
    int precedencia2 = valorPrecedencia(op2);
    if(precedencia1 > precedencia2)
        return 1;
    else{
        if(precedencia1 == precedencia2)
            return 0;
        return -1;
    }
    
}
int valorPrecedencia(char operador){
    if(operador == '*' || operador == '/' || operador == '%') return 1;
    if(operador == '+' || operador == '-') return 0;
    return -1;
}

int main(){
    char expresion[] = "(5+3)*5/2%2";
    vector<char> postfij;
    convertirAPostfijo(expresion,11,postfij);
    for(int i = 0; i < postfij.size();i++)
        cout << postfij[i];
}