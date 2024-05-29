#ifndef ASIGNACION-DE-RESULTADOS _H
#define ASIGNACION-DE-RESULTADOS _H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

struct Asignacion{
char id_deporte[50];
char nombre_deporte[50];

    char codigo_equipo[50];
    char nombre_equipo[50];
      char codigo_equipo2[50];
    char nombre_equipo2[50];

    char id_entrenador[50];
    char nombre_entrenador[50];
    char id_entrenador2[50];
    char nombre_entrenador2[50];


    char id_horario[50];
    char dia[50];
    char jornada[50];
    char horario[50];
    int acta;
};


class asignaciom_de_resultados
{
    public:
        asignacion_de_resultados ();


    void Menu();
    void asignarse_resultado();
    void actas();
    void imprimir_acta();

};

#endif // ASIGNACION-DE-RESULTADOS _H
