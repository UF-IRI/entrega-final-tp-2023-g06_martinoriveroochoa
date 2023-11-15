#include <iostream>
#include "gimnasio.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include "archivos.h"
using namespace std;

struct Clase;
typedef struct Clase sClase;

struct Asistencia;
typedef struct Asistencia sAsistencia;

struct Inscripcion;
typedef struct Inscripcion sInscripcion;

int main() {

    unsigned int primera_opcion, segunda_opcion;
    int exitoClase, PosicionClase;
    std::string ClaseRequerida;
    double HorarioMusculacion, HorarioClase;
    std::cout<<"Bienvenido a Musculito"<<std::endl;
    std::cout<<"Ingrese la opcion que desee"<<std::endl;
    std::cout<<"1.Mostrar lista de reservas de hoy"<<std::endl<<"2.Realizar una reserva para el dia siguiente"<<std::endl;
    std::cin>>primera_opcion;

    if(primera_opcion==1){
        if(esDomingo()){
          std::cout << "¡Hoy es Domingo!.Los Domingos no abre nuestro gimnasio, por lo tanto no hay clases hoy" << std::endl;
        }
        else{
          std::cout<<"Eligio leer la lista de reservas de hoy"<<std::endl;
        }
    }

    else if(primera_opcion==2){
        if (esSabado()){
          std::cout << "¡Hoy es Sabado!. Los Domingos no abre nuestro gimnasio. Intente nuevamente otro dia" << std::endl;
        }
        else {
        /*
         ifstream archivo_clases;
         archivo_clases.open("iriClasesGYM.csv");


          sClase *lista_clases=nullptr;
          unsigned int tamClases=0;

         //leerArchivosCSV(archivo_clases,lista_clases,tamClases);

          archivo_clases.close();

          std::cout<<"Eligio hacer una reserva"<<std::endl<<"Ingrese la opcion de lo que desea reservar"<<std::endl<<"1.Clase"<<std::endl<<"2.Musculacion"<<std::endl;
          std::cin>>segunda_opcion;

          if(segunda_opcion==1){
              std::cout<<"Eligio reservar una clase."<<std::endl;
              std::cout<<"Ingrese el nombre de la clase que desea EN MINUSCULA:"<<std::endl;
              std::cin>>ClaseRequerida;
              std::cout<<"Buscando "<<ClaseRequerida<<"..."<<std::endl;
              //busca

              /*exitoClase=buscarPorNombre(lista_clases,tamClases,ClaseRequerida);
              if (exitoClase==0){
                  std::cout << "La clase fue encontrada." << std::endl;
                  std::cout << "Ahora necesitaremos el horario que desees."<< std::endl<<"Recorda ingresar de la siguiente manera: Ej.7.00,7.30."<< std::endl;
                  std::cin>>HorarioClase;
                  PosicionClase=buscarPorNombreYHorario(lista_clases,tamClases,ClaseRequerida,HorarioClase);
                  if(PosicionClase!=-1){
                  std::cout << "La clase fue encontrada." << std::endl;
                  std::cout<<"Para continuar vamos a necesitar que ingreses tu id:"<< std::endl;
                  std::cin>>IDCLIENTE;


                  const std::string nombreArchivo= "asistencias_1697673600000.dat";
                  sAsistencia *listaAsistencias=nullptr;
                  unsigned int cantAsistencias=0;


                  leerArchivoBinario(nombreArchivo, listaAsistencias, cantAsistencias);


                  int n=chequearReserva(listaAsistencia,cantAsistencias, lista_clases[PosicionClase].idClase, IDCLIENTE);







                  delete[]listaAsistencias;



                  }
                  else {
                  std::cout << "No se encontró ninguna clase con el horario especificado." << std::endl;
                  }
              }
              else if(exitoClase==1){

                  std::cout << "No se encontró ninguna clase con el nombre especificado." << std::endl;


          }
          else if(segunda_opcion==2){
              std::cout<<"Eligio reservar en musculacion"<<std::endl;
              std::cout<<"Recuerde que se reserva en periodos de 30 minutos"<<endl;
              std::cout<<"Ingrese horario que desee:"<< std::endl<<"Ej.7.00,7.30."<<std::endl;
              std::cin>>HorarioMusculacion;
              std::cout<<HorarioMusculacion<<std::endl;
          }
          else{
              std::cout<<"Ingreso algo incorrecto"<<std::endl;
          }


          if (lista_clases!=nullptr){
              delete[] lista_clases;
              lista_clases=nullptr;
          }
          }*/

        }

    }

    else {
      std::cout<<"Ingreso un numero incorrecto, vuelva a ingresar"<<std::endl;
    }



    return 0;
}

/*
    ofstream archivoTXT("Probando.txt");
    escribirTXT(archivoTXT);
    archivoTXT.close();

*/

