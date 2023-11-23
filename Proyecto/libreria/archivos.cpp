#include "archivos.h"
#include <fstream>
#include <sstream>
#include "gimnasio.h"



void incrementarListaClases(sClase *&lista_clases, unsigned int &tamClases){
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


void leerArchivosCSVClase(std::ifstream &archivo_clases, sClase *& lista_clases,unsigned int &tamClases){
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


void incrementarListaClientes(sCliente* &lista_clientes, unsigned int &tamClientes){
    if(lista_clientes==nullptr){
      if(tamClientes==0){
            lista_clientes=new sCliente[++tamClientes];
      }
      return;
    }
    sCliente* aux=new sCliente[++tamClientes];
    for(unsigned int i=0;i<tamClientes-1;i++){
      aux[i]=lista_clientes[i];
    }
    delete[]lista_clientes;
    lista_clientes=aux;
    return;
}

void leerArchivosCSVClientes(std::ifstream &archivo_clientes, sCliente *& lista_clientes,unsigned int &tamClientes){
    std::string linea;
    std::stringstream ss;

    if(!archivo_clientes.is_open()){
      return;
    }

    std::getline(archivo_clientes,linea);//lee encabezado
    while(std::getline(archivo_clientes,linea)){
      ss.clear();
      ss<<linea;

      incrementarListaClientes(lista_clientes,tamClientes);
      char comma=';';

      std::getline(ss,linea,comma);//idCliente
      lista_clientes[tamClientes-1].idCliente=std::stoi(linea);

      std:: getline(ss,lista_clientes[tamClientes-1].NombreCliente,comma);//nombrecliente

      std:: getline(ss,lista_clientes[tamClientes-1].ApellidoCliente,comma);//apellidocliente

      std:: getline(ss,lista_clientes[tamClientes-1].Email,comma);//emailcliente

      std:: getline(ss,lista_clientes[tamClientes-1].Telefono,comma);//telefonocliente

      std:: getline(ss,lista_clientes[tamClientes-1].FechaNac,comma);//fechanaccliente


      std::getline(ss,linea,comma);//estado
      lista_clientes[tamClientes-1].estado=std::stoi(linea);


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
            archivo_binario.read((char*)&lista_asistencias[tamAsistencias-1].CursosInscriptos[i].timestamp,sizeof(tm));


      }
       delete[] lista_asistencias[tamAsistencias-1].CursosInscriptos ;


    }

    delete[] lista_asistencias;
    tamAsistencias = 0;

}
void resizeInscripcion(sInscripcion *&CursoInscripto, unsigned int &cantInscriptos){
    sInscripcion *aux=new sInscripcion[++cantInscriptos];

    for(unsigned int i=0; i < cantInscriptos-1;i++){
       aux[i]=CursoInscripto[i];
    }

    delete [] CursoInscripto;
    CursoInscripto=aux;


}
/*
int AgregarAsistencia(sAsistencia *&lista_asistencias, unsigned int &tamAsistencias, unsigned int idcliente, unsigned int idcurso, std::tm horaact){
    for(unsigned int i=0; i<tamAsistencias;i++){
       if(lista_asistencias[i].idCliente==idcliente){
            //ya esta en la lista
            resizeInscripcion(lista_asistencias[i].CursosInscriptos,lista_asistencias[i].cantInscriptos);
            sInscripcion InscripcionNueva;
            InscripcionNueva.idCurso=idcurso;
            InscripcionNueva.timestamp=horaact;

            lista_asistencias[i].CursosInscriptos[lista_asistencias[i].cantInscriptos-1]=InscripcionNueva;

            std::ofstream archivo_binario;
            archivo_binario.open("asistencias_1697673600000.dat",std::ios::binary);

            if(!archivo_binario){
                std::cout<< "No se pudo abrir el archivo binario" << std::endl;
                std::cout<<"Hubo un problema al guardar su reserva, vuelva a intentarlo mas tarde."<<std::endl;
                return 1;
            }

            archivo_binario.seekp(i); //posicion del cliente

            archivo_binario.write((char*)(&lista_asistencias[i]),sizeof(sAsistencia)); //escribe la asistencia actualizada

            archivo_binario.close();

            return 0;
       }
    }


    //si no esta.
    sAsistencia nuevaAsistencia;
    nuevaAsistencia.idCliente= idcliente;
    nuevaAsistencia.cantInscriptos=1;
    nuevaAsistencia.CursosInscriptos = new sInscripcion[1];

    nuevaAsistencia.CursosInscriptos[0].idCurso=idcurso;
    nuevaAsistencia.CursosInscriptos[0].timestamp=horaact;


    lista_asistencias[tamAsistencias-1]=nuevaAsistencia;


    std::ofstream archivo_binario;
    archivo_binario.open("asistencias_1697673600000.dat",std::ios::binary);

    if(!archivo_binario){
       std::cout<< "No se pudo abrir el archivo binario" << std::endl;
       std::cout<<"Hubo un problema al guardar su reserva, vuelva a intentarlo mas tarde."<<std::endl;
       return 1;
    }

    archivo_binario.seekp(0, std::ios::end); //posicion al final

    archivo_binario.write((char*)(&nuevaAsistencia),sizeof(sAsistencia));

    archivo_binario.close();

    //delete [] nuevaAsistencia.CursosInscriptos;

    return 0; //agregado con exito

}

*/





