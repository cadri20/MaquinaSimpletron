
class Simpletron{
    private:
        int memoria[100];
        int acumulador;
        int contador;
        int codigoDeOperacion;
        int operando;
        int numeroDeInstrucciones;

        void cargarInstruccion(int);
        int ejecutarInstruccion(int);
        void bifurcar(int);
    public:
        Simpletron();       
        void cargarPrograma(int [],int );
        void ejecutar();
        
};