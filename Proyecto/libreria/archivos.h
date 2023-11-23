#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
#include <sstream>
#include <ctime>


struct Clase;
typedef struct Clase sClase;

struct Asistencia;
typedef struct Asistencia sAsistencia;

struct Inscripcion;
typedef struct Inscripcion sInscripcion;

struct Cliente;
typedef struct Cliente sCliente;


void incrementarListaClases(sClase* &lista_clases,unsigned int &tamClases);
void leerArchivosCSVClase(std::ifstream &archivo_clases, sClase *& lista_clases,unsigned int &tamClases);
void incrementarListaClientes(sCliente* &lista_clientes,unsigned int &tamClientes);
void leerArchivosCSVClientes(std::ifstream &archivo_clientes, sCliente *& lista_clientes,unsigned int &tamClientes);


void resizeLista(Asistencia*& listaAsistencias, unsigned int& tamAsistencias);
void leerArchivoBinario(std::ifstream &archivo_binario,sAsistencia *&lista_asistencias,unsigned int &tamAsistencias);
void resizeInscripcion(sInscripcion *&CursoInscripto, unsigned int &cantInscriptos);
int AgregarAsistencia(sAsistencia *&lista_asistencias, unsigned int &tamAsistencias, unsigned int idcliente, unsigned int idcurso, tm horaact);

#endif // ARCHIVOS_H
