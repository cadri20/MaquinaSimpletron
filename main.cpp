#include "Simpletron.h"
#include <iostream>
using namespace std;
#include <fstream>
using std::ifstream;
int main(int argc, char *argv[]){
    int programa[100];
    int n = 0;
        //cout << "Ingrese una instruccion > ";
        ifstream archivoEntrada(argv[1], ios::in);

        if(!archivoEntrada){
            cerr << "No se pudo abrir el archivo" << endl;
            return 1;
        }
        int entrada;
        while(archivoEntrada >> entrada){
            programa[n] = entrada;
            n++;
        }
           
    Simpletron st;
    int pNumeroMayor[] = {1009,1010,2009,3110,4107,1109,4300,1110,4300};
    int pcicloSuma[] = {1009,2009,4108,1010,3010,2111,1111,4000,4300};
    st.cargarPrograma(programa,9);
    st.ejecutar();
}