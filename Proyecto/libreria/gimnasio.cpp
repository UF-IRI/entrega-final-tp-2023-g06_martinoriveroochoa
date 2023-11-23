#include "gimnasio.h"
#include <ctime>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

bool esSabado(){
    std::time_t tiempo_actual;
    std::tm* fecha_actual;

    std::time(&tiempo_actual);
    fecha_actual = std::localtime(&tiempo_actual);

    // El valor de fecha_actual->tm_wday es 0 para domingo, 1 para lunes, 2 para martes, etc.
    // Por lo tanto, si es 6, es sábado.
    return fecha_actual->tm_wday == 6;
}

bool esDomingo(){
    std::time_t tiempo_actual;
    std::tm* fecha_actual;

    std::time(&tiempo_actual);
    fecha_actual = std::localtime(&tiempo_actual);

    // El valor de fecha_actual->tm_wday es 0 para domingo, 1 para lunes, 2 para martes, etc.

    return fecha_actual->tm_wday == 0;
}


int buscarPorNombre(sClase* lista_clases,unsigned int tamClases, const std::string &nombre){
    for (unsigned int i=0;i< tamClases; ++i) {
      if(lista_clases[i].NombreClase==nombre){
            return 0;// encontro la clase
      }
    }
    return 1;
}

int buscarPorNombreYHorario(sClase* lista_clases,unsigned int tamClases,const std::string &nombre,double HorarioClase){
    for(unsigned int i=0;i< tamClases; ++i) {
         if(lista_clases[i].NombreClase==nombre && lista_clases[i].horario==HorarioClase){
           return i;
        }
    }

    return -1;
}

int chequearSuReserva(sAsistencia *&lista_asistencia,unsigned int &tamAsistencias, int idclase, int idcliente){
  for(unsigned int i=0;i<tamAsistencias;i++){
      if(lista_asistencia[i].idCliente==idcliente){
         for(unsigned j=0;j<lista_asistencia[i].cantInscriptos;j++){
            if(lista_asistencia[i].CursosInscriptos[j].idCurso==idclase){
                 std::cout<<"Ya esta anotado"<<std::endl;
              return -1;
            }
            else{
              return 0;
            }
        }
    }
    return 0;
  }

}

int ChequearSuCupo(sAsistencia*& lista_asistencias, unsigned int &tamAsistencias,int idclase, int cupo){
int cont=0;
  for (unsigned int i=0;i<tamAsistencias;i++){
     for(unsigned int j=0;j<lista_asistencias[i].cantInscriptos;j++){

        if(lista_asistencias[i].CursosInscriptos[j].idCurso==idclase){

        cont++;
       }
    }

    if (cont==cupo){

     return -1;//no hay mas lugar
    }

    else if(cont<cupo){

     return 0; //queda lugar
     //restar UN CUPO EN MAIN
    }

   }
}

std::tm obtenerHoraActual(){
   std:: time_t tiempo_actual=std::time(nullptr);
   std:: tm* hora_actual= std::localtime(&tiempo_actual);

   return *hora_actual;
}


int BuscarCliente(sCliente*lista_clientes,unsigned int tamClientes, int idcliente ){
   for(unsigned int i=0;i<tamClientes;i++){
      if(lista_clientes[i].idCliente==idcliente){
          if(lista_clientes[i].estado!=0){
            return 1;
          }
          else if (lista_clientes[i].estado==0){
          return 0;
          }
        }
    }

   return -1;

}
