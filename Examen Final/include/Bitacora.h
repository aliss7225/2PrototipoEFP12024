//Encabezado de proteccion
#ifndef BITACORA_H
#define BITACORA_H
//Librerias
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>

//Incluyendo encabezados
#include "usuarios.h"
using namespace std; // Uso del espacio de nombres estándar

// Estructura registro bitacora
struct RegistroBitacora {

    char accion[80]; // Acción realizada
    char aplicacion[80]; // Aplicación en la que se realizó la acción
    char nombre[80]; // Nombre del usuario
    char fechaHora[80]; // Fecha y hora de la acción
};

// Clase bitacora
class Bitacora {
//Atributos publicos
public:
    // Función para registrar una entrada en la bitácora
    void ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso);

    // Función para mostrar la bitácora
    void mostrarBitacora();

};

#endif // BITACORA_H

