#include "archivos.h"
#include <fstream>
#include <sstream>

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
/*
 void resizeLista(Asistencia*& listaAsistencias, unsigned int& capacidad, unsigned int nuevoTam){
Asistencia * nuevaLista= new Asistencia [nuevoTam];

for(unsigned int i =0; i < capacidad; ++i) {
        nuevaLista[i] = listaAsistencias[i];
    }

    // Liberar la memoria de la lista antigua
    delete[] listaAsistencias;

    // Actualizar la lista y la capacidad
    listaAsistencias = nuevaLista;
    capacidad = nuevoTam;

}

void leerArchivoBinario(std::string &nombreArchivo, Asistencia *& listaAsistencias, unsigned int cantAsistencias){
std:: ifstream archivo_binario(nombreArchivo,std::ios::binary);

    if(!archivo_binario.is_open()){
        std::cout<< "No se pudo abrir el archivo binario." << std::endl;
        return;
    }



}
 */
