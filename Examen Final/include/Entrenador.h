#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

#include<Entrenador.h>
using namespace std;
 struct EntrenadorC {

    char codigo[20];          // Almacena la id de los alumnos ingresados
    char nombre[50];      // Almacena el nombre  del alumno ingresado
    char puesto [50];      // Almacena el género del alumno ingresado
    char departamento[50];         // Almacena el DPI del alumno ingresado
    char sueldo[50];  // Almacena la dirección del alumno ingresado
    char estatus[50];// Almacena la nacionalidad del alumno ingresado

};
class Entrenador{
    private:
    string codigo, nombre, nombre2, DPI, Apellido, Apellido2, fechadenacimiento;


    //Atributos publicos de la clase alumnos
    public:
        //Creando los contructores

        Entrenador() {}
        Entrenador(string codigo,string nombre,string nombre2, string Apellido,string Apellido2,string fechadenacimiento);

        //Estableciendo la id
        string setcodigo(string codigo);
        //obteniendo la id
        string getcodigo();


        //Estableciendo el nombre
        string setnombre(string nombre);
        //obteniendo el nombre
        string getnombre();


         //Estableciendo el nombre
        string setnombre2(string nombre2);
        //obteniendo el nombre
        string getnombre2();


        //Estableciendo el apellido
        string setApellido(string Apellido);
        //Obteniendo el DPI
        string getApellido();


        //Estableciendo el apellido
        string setApellido2(string Apellido2);
        //Obteniendo el DPI
        string getApellido2();



        //Estableciendo el nacimiento
        string setFechanaci(string fechadenacimiento);
        //Obteniendo el genero
        string getFechanaci();




    //Funciones
    void menu(); //Funcion menu para poder mostar el menu de alumnos
    void insertar(); //Funcion para insertar un nuevo alumno
    void desplegar(); //Funcion para poder desplegar los alumnos registrados
    void modificar(); //Funcion para modificar un alumno registrado
    void buscar(); //Funcion para poder buscar un alumno por medio de la id
    void borrar(); //Funcion para poder borrar algun alumno registrado


    //Estructura del alumno

};


#endif // ENTRENADOR_H
