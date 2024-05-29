#ifndef HORARIOS_H
#define HORARIOS_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;
 //Estructura del alumno
    struct HorariosC {

    char id[20];
    char jornada[20];
    char dia[15];
    char horario[20] ;    // Almacena el nombre  del alumno ingresado
};

class Horarios
{
    private:
        string  id,jornada,dia,horario;


    public:
        Horarios(){}
        Horarios(string id, string jornada,string dia,string horario);
        //Estableciendo la id
        string setid(string id);
        //obteniendo la id
        string getid();


        //Estableciendo el nombre
        string setjornada(string jornada);
        //obteniendo el nombre
        string getjornada();


        //Estableciendo el nombre
        string setdia(string dia);
        //obteniendo el nombre
        string getdia();


        //Estableciendo el nombre
        string sethorario(string horario);
        //obteniendo el nombre
        string gethorario();


         //

 //Funciones

    void menuHorario(); //Funcion menu para poder mostar el menu de alumnos

    void insertar(); //Funcion para insertar un nuevo alumno
    void desplegar(); //Funcion para poder desplegar los alumnos registrados
    void modificar(); //Funcion para modificar un alumno registrado
    void buscar(); //Funcion para poder buscar un alumno por medio de la id
    void borrar(); //Funcion para poder borrar algun alumno


};

#endif // HORARIOS_H
