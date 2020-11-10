
class Simpletron{
    private:
        int memoria[100];
        int acumulador;
        int contador;
        int codigoDeOperacion;
        int operando;

        void cargarInstruccion(int);
        void ejecutarInstruccion(int);
    public:
        Simpletron();       
        void cargarPrograma(int [],int );
        void ejecutar();
        
};