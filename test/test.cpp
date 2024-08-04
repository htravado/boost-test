#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ModuloTest
/* El include de la libreria de boost test puede depender de la plataforma y de la instalacion */
#include <boost/test/unit_test.hpp>
#include "funcion.h"

/* Clase que actua como wrapper para poder testear metodos privado                 */
/* dentro de la clase que estoy heredando tengo que incluir esta clase como friend */
/* para que pueda llamar a los metodos privados de la clase heredada.              */
class OperacionTest : public Operacion{
public:
    int test_multiplicacion(int a, int b){
        return multiplicacionPrivada(a, b);
    }

/* Sobreescrivo el metodo de la clase base para que funcione autonomo */
/* Esta funcion se puede extrapolar a leer un archivo o obtener un dato de una BBDD*/
    int leerNumeroDeTeclado(){
        return 5;
    }

};

/* Para hacer test de metodos globales me alcanza con incluir el .h y llamar al metodo dentro del test case */
BOOST_AUTO_TEST_CASE(TestParaLaFuncionSumaGlobal){
    BOOST_CHECK(sumaGlobal(2,6) == 8);
    BOOST_CHECK(sumaGlobal(3,4) == 7);
}

BOOST_FIXTURE_TEST_CASE(TestParaLaDivision, Operacion){
    BOOST_REQUIRE_EQUAL(division(6,2), 3);
/* Como es una division por cero levanta una excepcion. Con este test 
   chequeamos que se produzca esa excepcion y matchee con invalid_argument */
    BOOST_CHECK_THROW(division(4,0), std::invalid_argument);
}

BOOST_FIXTURE_TEST_CASE(TestParaLaSumaPublica, Operacion){
    BOOST_REQUIRE_EQUAL(sumaPublica(2,6), 8);
/* Este test controla que los dos parametros sean iguales */
    BOOST_REQUIRE_EQUAL(sumaPublica(3,4), 7);
/* Este test controla que los dos parametros NO sean iguales */
    BOOST_REQUIRE_NE(sumaPublica(5,1), 7);
}

/* Para testear los metodos privado se puede usar como fixture directamente la clase a testear */
BOOST_FIXTURE_TEST_CASE(TestParaLaSumaProtected, Operacion){
    BOOST_REQUIRE_EQUAL(sumaProtected(2,6), 8);
    BOOST_REQUIRE_NE(sumaProtected(5,1), 4);
}

/* Si queremos testear un metodo privado, necesitamos declarar una clase "friend" y hace un wrapper */
/* que internamente llame al metodo privado. Este wrapper es el que usamos como fixture             */
BOOST_FIXTURE_TEST_CASE(TestParaLaMultiplicacionPrivada, OperacionTest){
/* Para el test usamos el metodo publico del wrapper */
    BOOST_REQUIRE_EQUAL(test_multiplicacion(2,6), 12);
}

/* Si tenemos un metodo que usa datos de una fuente de datos como ser un archivo. Y tenemos un metodo */
/* que lee estos datos, podemos sobreescribir el metodo de lectura de estos datos para que devuelva un*/
/* datos fijo y conocido para poder evaluar el comportamiento de los metodos que procesan estos datos */
BOOST_FIXTURE_TEST_CASE(TestParaElMetodoQueUsaDatosDeArchivo, OperacionTest){
/* Para el test usamos el metodo leerNumeroDeTeclado que esta sobreescrito en el wrapper              */
/* Si no estaria esta funcion el test va a usar la funcion de la clase base y se va a quedar esperando*/
/* que se ingrese un numero por teclado                                                               */
    int ndia = leerNumeroDeTeclado();
    BOOST_REQUIRE_EQUAL(devolverDiaDeLaSemana(ndia), "VIERNES");
}


