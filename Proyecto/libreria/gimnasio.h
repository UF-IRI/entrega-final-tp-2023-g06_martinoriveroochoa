#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

struct Inscripcion{
    int idCurso;
    unsigned int timestamp;
};typedef struct Inscripcion sInscripcion;


struct Asistencia{
    int idCliente;
    unsigned int cantInscriptos;
    Inscripcion* CursosInscriptos;//array dinamico
}; typedef struct Asistencia sAsistencia;

struct Clase {
    int idClase, cupo;
    std::string NombreClase;
    double horario;
};typedef struct Clase sClase;

int buscarPorNombre(sClase* lista_clases,unsigned int tamClases, const std::string &nombre);
int buscarPorNombreYHorario(sClase* lista_clases,unsigned int tamClases,const std::string &nombre,double HorarioClase);

bool esSabado();
bool esDomingo();

#endif // GIMNASIO_H
