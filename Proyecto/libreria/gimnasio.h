#ifndef GIMNASIO_H
#define GIMNASIO_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

struct Inscripcion{
    int idCurso;
    tm timestamp;
};typedef struct Inscripcion sInscripcion;


struct Asistencia{
   unsigned int idCliente;
    unsigned int cantInscriptos;
    Inscripcion *CursosInscriptos;//array dinamico
}; typedef struct Asistencia sAsistencia;

struct Clase {
    int idClase, cupo;
    std::string NombreClase;
    double horario;
};typedef struct Clase sClase;

struct Cliente{
    int idCliente, estado;
    std::string NombreCliente, ApellidoCliente, Email,FechaNac,Telefono;
};typedef struct Cliente sCliente;

int buscarPorNombre(sClase* lista_clases,unsigned int tamClases, const std::string &nombre);
int buscarPorNombreYHorario(sClase* lista_clases,unsigned int tamClases,const std::string &nombre,double HorarioClase);
int chequearSuReserva(sAsistencia*& lista_asistencias, unsigned int &tamAsistencias,int idclase, int idcliente);
int ChequearSuCupo(sAsistencia*& lista_asistencias, unsigned int &tamAsistencias,int idclase, int cupo);
int BuscarCliente(sCliente*lista_clientes,unsigned int tamClientes, int idcliente );

std::tm obtenerHoraActual();

bool esSabado();
bool esDomingo();

#endif // GIMNASIO_H
