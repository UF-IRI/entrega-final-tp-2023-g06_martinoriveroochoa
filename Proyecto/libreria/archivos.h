#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
#include <sstream>
#include "gimnasio.h"

struct Clase;
typedef struct Clase sClase;


void incrementarListaClases(sClase* &lista_clases,unsigned int &tamClases);
void leerArchivosCSV(std::ifstream &archivo_clases,sClase* &lista_clases,unsigned int &tamClases);

/*
void escribirTXT(std::ofstream &archivoTXT);
void leerArchivoBinario(std::string &nombreArchivo, Asistencia *& listaAsistencias, unsigned int &cantAsistencias);
*/
#endif // ARCHIVOS_H
