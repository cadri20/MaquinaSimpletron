
class Simpletron{
    private:
        int memoria[100];
        int acumulador;
        int contador;
        int codigoDeOperacion;
        int operando;

        void cargarInstruccion(int);
        int ejecutarInstruccion(int);
    public:
        Simpletron();       
        void cargarPrograma(int [],int );
        void ejecutar();
        
};