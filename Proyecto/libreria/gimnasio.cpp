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
/*
int agregarAsistencia(sAsistencia *listaAsistencia, unsigned int cantAsistencias, sInscripcion *listaInscripciones, int idcliente, int idclase, int hora_act){

//chequeo primero si ya se anoto a alguna clase de mañana

   for(unsigned int i=0;i<cantAsistencias;i++){
      if(listaAsistencia[i].idCliente==idcliente){

      //ya estaba anotada en alguna
      resize(listaInscripciones,listaAsistencia[i].cantInscriptos) //agrega 1 lugar a la lista de inscripciones
      listaAsistencia[i].cantInscriptos++;
      listaAsistencias[i].CursosInscriptos[cantInscriptos-1].idCurso=idclase;
      listaAsistencias[i].CursosInscriptos[canInscriptos-1].timestamp=hora_act; //chequear desp variable si es entero u otra
      return 0;
      }
   }
   if(i==cantAsistencias){
    //no estaba anotada todavia
    resize(listaAsistencia,cantAsistencias);
    listaAsistencia[cantAsistencia-1].idCliente=idcliente;
    listaAsistencia[cantAsistencia-1].cantInscriptos=1;
    listaAsistencia[cantAsistencia-1].CursosInscriptos[cantInscriptos-1].idCurso=idclase;
    listaAsistencia[cantAsistencia-1].CursosInscriptos[cantInscriptos-1].timestamp=hora_act;
    return 0;
    }
    else{
    return -1;
    }

*/
