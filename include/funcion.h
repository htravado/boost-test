#ifndef __FUNCION_H__
#define __FUNCION_H__

#include <iostream>

int sumaGlobal(int a, int b);
int division(int a, int b);

class Operacion{
    friend class OperacionTest;
    
    private:
        int multiplicacionPrivada(int a, int b);

    protected:
        int sumaProtected(int a, int b);
    
    public:
        int sumaPublica(int a, int b);
        int leerNumeroDeTeclado();
        std::string devolverDiaDeLaSemana(int ndia);

        Operacion();
        ~Operacion();
};


#endif