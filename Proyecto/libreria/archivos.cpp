#include "archivos.h"
#include <fstream>
#include <sstream>
#include "gimnasio.h"



void incrementarListaClases(sClase* &lista_clases, unsigned int &tamClases){
    if(lista_clases==nullptr){
        if(tamClases==0){
            lista_clases=new sClase[++tamClases];
        }
        return;
    }
    sClase* aux=new sClase[++tamClases];
    for(unsigned int i=0;i<tamClases-1;i++){
        aux[i]=lista_clases[i];
    }
    delete[]lista_clases;
    lista_clases=aux;
    return;
}


void leerArchivosCSV(std::ifstream &archivo_clases, sClase *& lista_clases,unsigned int &tamClases){
    std::string linea;
    std::stringstream ss;

    if(!archivo_clases.is_open()){
        return;
    }

    std::getline(archivo_clases,linea);//lee encabezado
    while(std::getline(archivo_clases,linea)){
      ss.clear();
      ss<<linea;

      incrementarListaClases(lista_clases,tamClases);
      char comma=';';

      std::getline(ss,linea,comma);//idClase
      lista_clases[tamClases-1].idClase=std::stoi(linea);
      std:: getline(ss,lista_clases[tamClases-1].NombreClase,comma);//nombreclase
      std::getline(ss,linea,comma);//horario
      lista_clases[tamClases-1].horario=std::stod(linea);
      std::getline(ss,linea,comma);//cupo
      lista_clases[tamClases-1].cupo=std::stoi(linea);

    }
}

void resizeLista(Asistencia*& lista_asistencias, unsigned int& tamAsistencias){
    sAsistencia * aux= new sAsistencia [++tamAsistencias];

    for(unsigned int i =0; i < tamAsistencias-1; ++i) {
      aux[i] = lista_asistencias[i];
    }

    // Liberar la memoria de la lista antigua
    delete[] lista_asistencias;

    // Actualizar la lista y la capacidad
    lista_asistencias = aux;
}

void leerArchivoBinario(std::ifstream &archivo_binario,sAsistencia *&lista_asistencias,unsigned int &tamAsistencias){


    if(!archivo_binario.is_open()){
      std::cout<<"Error al abrir el archivo"<<std::endl;
      return;
    }

    unsigned int idCliente_aux=0, cantInscritos_aux=0;

    while(archivo_binario){
      resizeLista(lista_asistencias,tamAsistencias);
      archivo_binario.read((char *)&idCliente_aux,sizeof(unsigned int));
      archivo_binario.read((char *)&cantInscritos_aux,sizeof(unsigned int));

      lista_asistencias[tamAsistencias-1].CursosInscriptos = new sInscripcion[cantInscritos_aux];

      for(unsigned int i=0;i<cantInscritos_aux;i++){
            archivo_binario.read((char*)&lista_asistencias[tamAsistencias-1].CursosInscriptos[i].idCurso,sizeof(unsigned int));
            archivo_binario.read((char*)&lista_asistencias[tamAsistencias-1].CursosInscriptos[i].timestamp,sizeof(time_t));


      }
       delete[] lista_asistencias[tamAsistencias-1].CursosInscriptos ;


    }

    delete[] lista_asistencias;
    tamAsistencias = 0;

}






