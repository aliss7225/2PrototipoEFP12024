#ifndef DEPORTE_H
#define DEPORTE_H

#include "deporte.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

//Estructura del alumno
    struct Deporte {

    char id[20];

    char nombre[50];      // Almacena el nombre  del alumno ingresado
};
class deporte
{
    private:
        string  id,nombre;


    public:
        deporte(){}
        deporte(string id, string nombre);
        //Estableciendo la id
        string setid(string id);
        //obteniendo la id
        string getid();


        //Estableciendo el nombre
        string setnombre(string nombre);
        //obteniendo el nombre
        string getnombre();

         //

 //Funciones

    void menudeportes(); //Funcion menu para poder mostar el menu de alumnos

    void insertar(); //Funcion para insertar un nuevo alumno
    void desplegar(); //Funcion para poder desplegar los alumnos registrados
    void modificar(); //Funcion para modificar un alumno registrado
    void buscar(); //Funcion para poder buscar un alumno por medio de la id
    void borrar(); //Funcion para poder borrar algun alumno


};

#endif // DEPORTE_H
