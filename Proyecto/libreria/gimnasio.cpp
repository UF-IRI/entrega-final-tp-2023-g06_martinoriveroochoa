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
/*
int chequearReserva(sAsistencia *listaAsistencia,unsigned int cantAsistencias, int idclase, int idcliente){
  for(unsigned int i=0;i..){
      if(listaAsistencia[i].idCliente==idcliente){
         for(unsigned j=0;...){
            if(listaAsistencia[i].Inscripcion[j].idClase==idclase){
              std::cout"Ya esta anotado"
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
*/
