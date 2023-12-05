#include <iostream>
#include "gimnasio.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include "archivos.h"
#include <cstring>

using namespace std;

struct Clase;
typedef struct Clase sClase;

struct Cliente;
typedef struct Cliente sCliente;

struct Asistencia;
typedef struct Asistencia sAsistencia;

struct Inscripcion;
typedef struct Inscripcion sInscripcion;

int main() {

    unsigned int primera_opcion, segunda_opcion, IDCLIENTE, IdCLIENTEmusculacion,eleccion,eleccion2;
    int exitoClase, PosicionClase, PosicionMusculacion,BuscarClientela ,chequearReserva,chequearCupo, AgregarReserva;
    std::string ClaseRequerida;



    double HorarioMusculacion, HorarioClase;
    std::cout<<"Bienvenido a Musculito"<<std::endl;
    std::cout<<"Ingrese la opcion que desee"<<std::endl;
    std::cout<<"1.Mostrar info. de clases"<<std::endl<<"2.Realizar una reserva para el dia siguiente"<<std::endl;
    std::cin>>primera_opcion;

    if(primera_opcion==1){
        std::cout << "----------GIMNASIO MUSCULITO-----------" << std::endl;
        std::cout << "Lunes a Sabados: de 7 a 21 hs" << std::endl;
        std::cout << "Clases: Spinning,Yoga,Pilates,Stretching,Zumba,Boxeo" << std::endl;
        std::cout << "Ademas, gran espacio de musculacion" << std::endl;
        std::cout << "1.Conocer horarios de clases" << std::endl<<"2.Conocer horarios de musculacion"<<std::endl<<"3.Salir"<<std::endl;
        std::cin>>eleccion;
        if(eleccion==1){
          std::cout << "1.Spinning" << std::endl<< "2.Yoga" << std::endl<< "3.Pilates" << std::endl<<"4.Stretching" << std::endl<< "5.Zumba"<< std::endl << "6.Boxeo" << std::endl;
          std::cin>>eleccion2;

          switch(eleccion2){
          case 1: std::cout << "8 am, 10 am, 12 pm, 16 pm, 18 pm " << std::endl;
              break;
          case 2: std::cout << "9 am, 10 am, 11 am, 15 pm, 16 pm, 19 pm " << std::endl;
              break;
          case 3: std::cout << "8 am, 9 am, 10 am, 12 pm, 18 pm, 19 pm" << std::endl;
              break;
          case 4: std::cout << "8 am, 14 pm, 15 pm, 16 pm, 18 pm, 19 pm" << std::endl;
              break;
          case 5: std::cout << "8 am, 10 am, 12 pm, 16 pm, 17 pm, 18 pm" << std::endl;
              break;
          case 6:  std::cout << "16 pm, 17 pm, 18 pm, 19 pm" << std::endl;
              break;
          default:
              std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
          }


        }
        else if(eleccion==2){
          std::cout << "Lunes a Sabados: de 7 a 20 hs" << std::endl;
        }
        else {
            return 0;
        }


    }

    else if(primera_opcion==2){
        if (esSabado()){
          std::cout << "¡Hoy es Sabado!. Los Domingos no abre nuestro gimnasio. Intente nuevamente otro dia" << std::endl;
        }
        //la lista del lunes se creara cuando ingrese el domingo.
        else {
          //abro archivo clases
         ifstream archivo_clases;
         archivo_clases.open("iriClasesGYM.csv");

          sClase *lista_clases=nullptr;
          unsigned int tamClases=0;

          leerArchivosCSVClase(archivo_clases,lista_clases,tamClases); //leo y creo lista de estructura con datos
          archivo_clases.close();


          //abro archivo clientes
          ifstream archivo_clientes;
          archivo_clientes.open("iriClientesGYM.csv");


          sCliente *lista_clientes=nullptr;
          unsigned int tamClientes=0;

          leerArchivosCSVClientes(archivo_clientes,lista_clientes,tamClientes);//leo y creo lista de estructura con datos
          archivo_clientes.close();

          //creo archivo binario

          sAsistencia *lista_asistencias=nullptr;
          unsigned int tamAsistencias=0;

          std::ofstream archivo("listado_asistencias.dat", std::ios::binary | std::ios::out);

          if (!archivo.is_open()) {
              std::cout << "Error al crear el archivo." << std::endl;
              return 1;  // Salir del programa con un código de error
          }

          const char* encabezado = "Lista de Reservas\n";
          archivo.write(encabezado, strlen(encabezado));


          std::cout<<"Eligio hacer una reserva"<<std::endl<<"Ingrese la opcion de lo que desea reservar"<<std::endl<<"1.Clase"<<std::endl<<"2.Musculacion"<<std::endl;
          std::cin>>segunda_opcion;

          if(segunda_opcion==1){
              std::cout<<"Eligio reservar una clase."<<std::endl;
              std::cout<<"Ingrese el nombre de la clase que desea EN MINUSCULA:"<<std::endl;
              std::cin>>ClaseRequerida;
              std::cout<<"Buscando "<<ClaseRequerida<<"..."<<std::endl;
              //busca

              exitoClase=buscarPorNombre(lista_clases,tamClases,ClaseRequerida);
              if (exitoClase==0){
                  std::cout << "La clase fue encontrada." << std::endl;
                  std::cout << "Ahora necesitaremos el horario que desees."<< std::endl<<"Recorda ingresar de la siguiente manera: Ej.7.0,7.3."<< std::endl;
                  std::cin>>HorarioClase;

                  PosicionClase=buscarPorNombreYHorario(lista_clases,tamClases,ClaseRequerida,HorarioClase);

                  if(PosicionClase!=-1){
                      std::cout << "La clase fue encontrada." << std::endl;
                      std::cout<<"Para continuar vamos a necesitar que ingreses tu id:"<< std::endl;
                      std::cin>>IDCLIENTE;
                      BuscarClientela=BuscarCliente(lista_clientes,tamClientes,IDCLIENTE);

                      if(BuscarClientela==0){
                         //esta y no debe


                          //ahora chequear que no este ya inscripto a esa

                          chequearReserva=chequearSuReserva(lista_asistencias,tamAsistencias,lista_clases[PosicionClase].idClase,IDCLIENTE);
                          if(chequearReserva==0){
                          std::cout<< "Perfecto, usted no esta inscripto aun." << std::endl;

                             chequearCupo=ChequearSuCupo(lista_asistencias,tamAsistencias,lista_clases[PosicionClase].idClase, lista_clases[PosicionClase].cupo);
                             if(chequearCupo==0){
                                  std::cout<< "Todavia queda lugar! Continuamos con tu reserva..." << std::endl;

                                 AgregarReserva=AgregarAsistencia(lista_asistencias,tamAsistencias,IDCLIENTE,lista_clases[PosicionClase].idClase);
                                 if(AgregarReserva==0){


                                     lista_clases[PosicionClase].cupo--;
                                     std::cout<<"Ya esta anotado! Por favor, no falte"<<std::endl;

                                 }else{
                                     std::cout<<"Hubo un problema con su reserva, vuelva a intentarlo mas tarde."<<std::endl;
                                 }

                              }
                             else if(chequearCupo==-1){
                                  std::cout<< "Lo siento, la clase elegida esta llena. Intente con otra!" << std::endl;
                             }


                          }
                          else if(chequearReserva==-1){
                          std::cout<< "Ya tienes una reserva para esa clase." << std::endl;
                          }
                        }
                      else if(BuscarClientela==1){
                         //esta pero debe plata
                         std::cout << "Lo siento, primero debes actualizar tu cuota." << std::endl;
                      }
                      else {
                         //no esta
                         std::cout << "Lo siento, no eres socio del gym." << std::endl;
                      }


                    }
                  else {
                     std::cout << "No se encontro ninguna clase con el horario especificado." << std::endl;
                    }
                }
              else if(exitoClase==1){

                  std::cout << "No se encontro ninguna clase con el nombre especificado." << std::endl;
                }
            }
           else if(segunda_opcion==2){
              std::cout<<"Eligio reservar en musculacion"<<std::endl;
              std::cout<<"Recuerde que se reserva en periodos de 30 minutos"<<endl;
              std::cout<<"Ingrese horario que desee:"<< std::endl<<"Ej.7.0,7.3."<<std::endl;
              std::cin>>HorarioMusculacion;


              string musculacion="musculacion";
              PosicionMusculacion=buscarPorNombreYHorario(lista_clases,tamClases,musculacion,HorarioMusculacion);
              if(PosicionMusculacion>0){
                  std::cout<<"Todo va en orden"<<std::endl<<"Por favor, ingrese su id:"<<std::endl;
                  std::cin>>IdCLIENTEmusculacion;
                  BuscarClientela=BuscarCliente(lista_clientes,tamClientes,IdCLIENTEmusculacion);

                  if(BuscarClientela==0){
                     //esta y no debe


                     chequearReserva=chequearSuReserva(lista_asistencias,tamAsistencias,lista_clases[PosicionMusculacion].idClase,IdCLIENTEmusculacion);
                     if(chequearReserva==0){
                         std::cout<< "Perfecto, usted no esta inscripto aun." << std::endl; //como no hay cupos limitados
                         std::cout<< "Continuamos con tu reserva..." << std::endl;

                         AgregarReserva=AgregarAsistencia(lista_asistencias,tamAsistencias,IdCLIENTEmusculacion,lista_clases[PosicionMusculacion].idClase);
                         if(AgregarReserva==0){
                          std::cout<<"Ya esta anotado! Por favor, no falte"<<std::endl;
                         }
                         else{
                           std::cout<<"Hubo un problema con su reserva, vuelva a intentarlo mas tarde."<<std::endl;
                         }

                        }
                        else if(chequearReserva==-1){
                          std::cout<< "Ya tienes una reserva para ese horario." << std::endl;
                        }

                    }
                  else if(BuscarClientela==1){
                     //esta pero debe plata
                     std::cout << "Lo siento, primero debes actualizar tu cuota." << std::endl;
                    }
                  else {
                     //no esta
                     std::cout << "Lo siento, no eres socio del gym." << std::endl;
                    }
                }
              else if(PosicionMusculacion==-1){
                    std::cout<<"No hay musculacion a ese horario, lo siento."<<std::endl;
                }
            }
            else if (segunda_opcion!=1 && segunda_opcion!=2){
              std::cout<<"Ingreso algo incorrecto"<<std::endl;
            }


           if (lista_clases!=nullptr){
             delete[] lista_clases;
             lista_clases=nullptr;
            }

           if (lista_clientes!=nullptr){
             delete[]lista_clientes;
             lista_clientes=nullptr;
            }
           for (unsigned int i = 0; i < tamAsistencias; ++i) {
             delete[] lista_asistencias[i].CursosInscriptos;
           }
           delete[] lista_asistencias;

           archivo.close();
        }
    }
    else {
       std::cout<<"Ingreso un numero incorrecto, vuelva a ingresar"<<std::endl;
    }

    return 0;
}





