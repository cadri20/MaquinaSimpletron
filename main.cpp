#include "Simpletron.h"
int main(){
    Simpletron st;
    int programa[] = {1007,1008,2007,3008,2109,1109,4300};
    st.cargarPrograma(programa,7);
    st.ejecutar();
}