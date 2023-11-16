#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
#include <sstream>


struct Clase;
typedef struct Clase sClase;

struct Asistencia;
typedef struct Asistencia sAsistencia;

struct Inscripcion;
typedef struct Inscripcion sInscripcion;


void incrementarListaClases(sClase* &lista_clases,unsigned int &tamClases);
void leerArchivosCSV(std::ifstream &archivo_clases, sClase *& lista_clases,unsigned int &tamClases);
/*
void escribirTXT(std::ofstream &archivoTXT);*/
void resizeLista(Asistencia*& listaAsistencias, unsigned int& tamAsistencias);
void leerArchivoBinario(std::ifstream &archivo_binario,sAsistencia *&lista_asistencias,unsigned int &tamAsistencias);
void resizeInscripcion(sInscripcion *&CursoInscripto, unsigned int &cantInscriptos);
int AgregarAsistencia(sAsistencia *&lista_asistencias, unsigned int &tamAsistencias, unsigned int idcliente, unsigned int idcurso, tm horaact);

#endif // ARCHIVOS_H
