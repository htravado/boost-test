#include "funcion.h"

int sumaGlobal(int a, int b)
{
    return a + b;
}

int division(int a, int b)
{
    if (b==0) throw std::invalid_argument("Division por cero");

    return a / b;
}

int Operacion::multiplicacionPrivada(int a, int b)
{
    std::cout << "Ejecutando una multiplicacion privada" << std::endl;
    return a * b;
}

int Operacion::leerNumeroDeTeclado()
{   
    int res;
    std::cout << "Ingrese un numero: ";
    std::cin >> res;
    return res;
}

std::string Operacion::devolverDiaDeLaSemana(int ndia)
{   
    std::string dia = "DESCONOCIDO";
    switch (ndia)
    {
    case 1:
        dia = "LUNES";
        break;
    case 2:
        dia = "MARTES";
        break;
    case 3:
        dia = "MIERCOLES";
        break;
    case 4:
        dia = "JUEVES";
        break;
    case 5:
        dia = "VIERNES";
        break;
    case 6:
        dia = "SABADO";
        break;
    case 7:
        dia = "DOMINGO";
        break;
    
    default:
        break;
    }
    return dia;
}

int Operacion::sumaProtected(int a, int b)
{
    return a + b;
}

int Operacion::sumaPublica(int a, int b)
{
    return a + b;
}

Operacion::Operacion()
{
    std::cout << "Operacion::Operacion()" << std::endl;
}

Operacion::~Operacion()
{
    std::cout << "Operacion::~Operacion()" << std::endl;
}
