#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include "archivos.h"



struct Inscripcion{
   unsigned int idCurso;
    tm timestamp;
};typedef struct Inscripcion sInscripcion;


struct Asistencia{
   unsigned int idCliente;
   unsigned int cantInscriptos;
   Inscripcion *CursosInscriptos;//array dinamico
}; typedef struct Asistencia sAsistencia;

struct Clase {
    unsigned int idClase, cupo;
    std::string NombreClase;
    double horario;
};typedef struct Clase sClase;

struct Cliente{
    unsigned int idCliente, estado;
    std::string NombreCliente, ApellidoCliente, Email,FechaNac,Telefono;
};typedef struct Cliente sCliente;

int buscarPorNombre(sClase* lista_clases,unsigned int tamClases, const std::string &nombre);
int buscarPorNombreYHorario(sClase* lista_clases,unsigned int tamClases,const std::string &nombre,double HorarioClase);
int chequearSuReserva(sAsistencia*& lista_asistencias, unsigned int &tamAsistencias,unsigned int idclase,unsigned int idcliente);
int ChequearSuCupo(sAsistencia*& lista_asistencias, unsigned int &tamAsistencias,unsigned int idclase, unsigned int cupo);
int BuscarCliente(sCliente*lista_clientes,unsigned int tamClientes, unsigned int idcliente );



bool esSabado();


#endif // GIMNASIO_H
