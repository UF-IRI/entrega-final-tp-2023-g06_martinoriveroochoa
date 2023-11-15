#include <catch2/catch.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "gimnasio.h"
#include "archivos.h"
#include "libreria.h"
#include "libreria_global.h"
#include <sstream>

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}

TEST_CASE("Leer archivo CSV y guardar en lista", "[leerArchivosCSV]"){
    //Creo archivo de prueba
    std::ofstream archivo_prueba("datos_prueba.csv");
    archivo_prueba<< "idClase,NombreClase,horario,cupo\n";
    archivo_prueba << "1,Yoga,10.30,20\n";
    archivo_prueba << "2,Zumba,15.45,15\n";
    archivo_prueba << "3,Pilates,18.00,10\n";
    archivo_prueba.close();
    // Usar std::ifstream para leer desde el archivo de prueba
    std::ifstream archivo_input("datos_prueba.csv");

    // Llama a la función para leer el archivo CSV y guardar en la lista
    sClase* lista_clases = nullptr;
    unsigned int tamClases = 0;

    leerArchivosCSV(archivo_input, lista_clases, tamClases);

    // Asegúrate de que la función haya tenido éxito al leer el archivo CSV
    REQUIRE(tamClases == 3);
    // Limpia la memoria
    delete[] lista_clases;

    // Cierra el archivo después de usarlo
    archivo_input.close();
}

/*
TEST_CASE("Buscar por Nombre", "[buscarxnombre]"){
    sClase *listita=new sClase[2];

    listita[0].idClase=1;
    listita[0].NombreClase="spinning";
    listita[0].horario=17.00;
    listita[0].cupo=45;

    listita[1].idClase=2;
    listita[1].NombreClase="yoga";
    listita[1].horario=18.00;
    listita[1].cupo=35;


    int resultado=buscarPorNombre(listita,2,"spinning");

    REQUIRE(resultado==0);

}

TEST_CASE("Buscar por Nombre y Hora", "[buscarxnombreyhora]"){
    sClase *listita=new sClase[2];

    listita[0].idClase=1;
    listita[0].NombreClase="spinning";
    listita[0].horario=17.00;
    listita[0].cupo=45;

    listita[1].idClase=2;
    listita[1].NombreClase="yoga";
    listita[1].horario=18.00;
    listita[1].cupo=35;


    int resultado=buscarPorNombre(listita,2,"spinning",17.00);

    REQUIRE(resultado==0);

}
*/
