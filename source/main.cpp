#include <iostream>
#include "funcion.h"



int main(int argc, char *argv[]){

    std::cout << "Inicio del programa" << std::endl;

    std::cout << "Suma Global 3 + 4 = " << sumaGlobal(3, 4) << std::endl;
    std::cout << "Division Global 6 / 3 = " << division(6, 3) << std::endl;

    Operacion op;

    std::cout << "Suma publica 2 + 3 = " << op.sumaPublica(2, 3) << std::endl;

    int ndia = op.leerNumeroDeTeclado();
    std::cout << "El dia de la semana es " << op.devolverDiaDeLaSemana(ndia) << std::endl;

    return 0;
}