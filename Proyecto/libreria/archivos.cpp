#include "archivos.h"





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


void resizeInscripcion(sInscripcion *&CursoInscripto, unsigned int &cantInscriptos){
    sInscripcion *aux=new sInscripcion[++cantInscriptos];

    for(unsigned int i=0; i < cantInscriptos-1;i++){
       aux[i]=CursoInscripto[i];
    }

    delete [] CursoInscripto;
    CursoInscripto=aux;


}


void AgregarArchiB2(sAsistencia &nuevaasistencia){
    std:: ofstream archivo_asistencia;
    archivo_asistencia.open("listado_asistencias.dat",std::ios::binary | std::ios::app);
    if(!archivo_asistencia.is_open()){
       return;
    }

    archivo_asistencia.write((char*)&nuevaasistencia,sizeof(sAsistencia));



    archivo_asistencia.close();

    return;

}

void AgregarArchiB1(sAsistencia *&lista_asistencias,unsigned int &tamAsistencias){
    std::ofstream archivo_asistencia;
    archivo_asistencia.open("listado_asistencias.dat",std::ios::binary | std::ios::trunc);
    if(!archivo_asistencia.is_open()){
       return;
    }
    for(unsigned int i=0; i < tamAsistencias; i++) {
       archivo_asistencia.write((char*)&lista_asistencias[i], sizeof(sAsistencia));

    }
    archivo_asistencia.close();
}



int AgregarAsistencia(sAsistencia *&lista_asistencias, unsigned int &tamAsistencias, unsigned int idcliente, unsigned int idcurso){
    unsigned int i;

    for(i=0;i< tamAsistencias;i++){
       if(lista_asistencias[i].idCliente==idcliente){
            //ya esta anotado en alguna clase dist para mañana
            resizeInscripcion(lista_asistencias[i].CursosInscriptos,lista_asistencias[i].cantInscriptos);
            sInscripcion nueva;
            nueva.idCurso=idcurso;
            time_t now = time(0);
            tm *timestamp = localtime(&now);
            nueva.timestamp=*timestamp;

            lista_asistencias[i].CursosInscriptos[lista_asistencias[i].cantInscriptos-1]=nueva;

            AgregarArchiB1(lista_asistencias,tamAsistencias);

            return 0;

       }
    }

    if(i==tamAsistencias){
       //no lo encontro anotado
       resizeLista(lista_asistencias,tamAsistencias);
       sAsistencia nuevo;
       nuevo.idCliente=idcliente;
       nuevo.cantInscriptos=1;
       nuevo.CursosInscriptos= new sInscripcion[nuevo.cantInscriptos];

       nuevo.CursosInscriptos[0].idCurso=idcurso;
       time_t now = time(0);
       tm *timestamp = localtime(&now);
       nuevo.CursosInscriptos[0].timestamp=*timestamp;

       lista_asistencias[tamAsistencias-1]=nuevo;
       AgregarArchiB2(lista_asistencias[tamAsistencias-1]);

    }

    return 0;

}







