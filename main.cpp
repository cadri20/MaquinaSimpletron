#include "Simpletron.h"
#include <iostream>
using namespace std;
int main(){
    /*int programa[100];
    int n = 0;
    do{
        cout << "Ingrese una instruccion > ";
        int entrada;
        cin >> entrada;
        if(entrada == -1)
            break;
        programa[n] = entrada;
        n++;
    }while(1);*/
    Simpletron st;
    int pNumeroMayor[] = {1009,1010,2009,3110,4107,1109,4300,1110,4300};
    int pcicloSuma[] = {1009,2009,4108,1010,3010,2111,1111,4000,4300};
    st.cargarPrograma(pcicloSuma,9);
    st.ejecutar();
}