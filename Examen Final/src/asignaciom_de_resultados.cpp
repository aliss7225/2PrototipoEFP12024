#include "asignaciom_de_resultados.h"
#include "Entrenador.h"
#include "Equipos.h"
#include "login.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include<iomanip>
#include "Bitacora.h"
#include"Horarios.h"
#include"deporte.h"

using namespace std;
string users;

void asignaciom_de_resultados::Menu()
{
    string usuarioActual = Login::getUsuarioActual();

    Bitacora bitacora;

    bitacora.ingresoBitacora(usuarioActual, "4500", "ADR");
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout<<"\t\t\t+------------------------------------------+"<<endl;
    cout<<"\t\t\t|      BIENVENIDO AL MENU CATEDRATICO      |"<<endl;
    cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|1. Asignacion De resultados               |"<<endl;
	cout<<"\t\t\t|2. Actas                                  |"<<endl;
	cout<<"\t\t\t|3. Imprimir Acta                          |"<<endl;
	cout<<"\t\t\t|4. regresar al menu anterior              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3/4]                |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;

    switch(opcion){
    case 1:

         {
          asignarse_resultado();
            bitacora.ingresoBitacora(usuarioActual,"4002","ASG"); //ASG = Asignación de resultados

            break;
        }


    case 2:
        {
            actas();
           bitacora.ingresoBitacora(usuarioActual,"4002","DAC"); //DAC = Despliega Actas
            break;

        }
    case 3:

        {
          //imprimir_acta();
            //Realiza el proceso de imprimir el acta deseada y luego se registra en la bitacora
           bitacora.ingresoBitacora(usuarioActual,"4002","REA");; //RAC = Read Acta
            //mandamos usuario, codigo de proceso y 3 letras que resumen la accion/proceso realizado


        }            break;
 case 4:


            break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;}
        }while(opcion!= 4);

    }

void asignaciom_de_resultados::asignarse_resultado()
 {
     system("cls");
    char res='S'; //variable que controla la validacion: Pablo Palencia 9959-23-736

//Proceso asignación maestro a curso realizado por Kathia Contreras 9959-23-8246

int num=1;
Asignacion Asigna;



/* **********   DESPLIEGUE Deportes.DAT   ********** */
    cout<<"---------------- Deportes existentes---------------------"<<endl;
    ifstream archivo11("Deportes.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo11) {
        cout << "No hay equipos registradas." << endl;
        return;
    }
    Deporte deporte1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo11.read(reinterpret_cast<char*>(&deporte1), sizeof(Deporte))) {

        cout << num<< ". " << deporte1.id <<"-|- "<<deporte1.nombre<<endl;

        num++;
    }
    archivo11.close(); // Cerrar el archivo

do
{
    string ideporte;
    cout<<"ingrese codigo del deporte : ";
    cin >> ideporte;
    fstream archivo25("Deportes.dat", ios::binary | ios::in | ios::out);
    if (!archivo25) {
        cout << "No hay Deportes registrados." << endl;
        return;
    }
    Deporte deporte1;
    bool encontrada = false;
    while (archivo25.read(reinterpret_cast<char*>(&deporte1), sizeof(Deporte))) {
        if (deporte1.id == ideporte) {
            archivo25.seekp(-static_cast<int>(sizeof(Deporte)), ios::cur);
            strcpy(Asigna.id_deporte,(ideporte).c_str());
             strcpy(Asigna.nombre_deporte,(deporte1.nombre));
            cin.ignore();
            encontrada = true;
             res='N';
            break;
        }
    }
    archivo25.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
            system("cls");


//------------------------------------------------------------------------------------------------
    string idequipo;

/* **********   DESPLIEGUE EQUIPOS.DAT   ********** */
    cout<<"---------------- equipos existentes---------------------"<<endl;
    ifstream archivo55("Equipos.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo55) {
        cout << "No hay equipos registradas." << endl;
        return;
    }
    EquiposC equipoa;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo55.read(reinterpret_cast<char*>(&equipoa), sizeof(EquiposC))) {

        cout << num<< ". " << equipoa.id <<"-|- "<<equipoa.nombre<<endl;

        num++;
    }
    archivo55.close(); // Cerrar el archivo

do
{
    cout<<"ingrese codigo de equipo 1: ";
    cin >> idequipo;
    fstream archivo15("Equipos.dat", ios::binary | ios::in | ios::out);
    if (!archivo15) {
        cout << "No hay Equipos registrados." << endl;
        return;
    }
    EquiposC equipo;
    bool encontrada = false;
    while (archivo15.read(reinterpret_cast<char*>(&equipo), sizeof(EquiposC))) {
        if (equipo.id == idequipo) {
            archivo15.seekp(-static_cast<int>(sizeof(EquiposC)), ios::cur);
            strcpy(Asigna.codigo_equipo,(idequipo).c_str());
             strcpy(Asigna.nombre_equipo,(equipo.nombre));
            cin.ignore();
            encontrada = true;
             res='N';
            break;
        }
    }
    archivo15.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
            system("cls");

 // Inicializar el generador de números aleatorios con una semilla
    srand(time(0)); // Establece la semilla basada en el tiempo actual
    int numero = rand() % 9000 + 1000; // Genera un número aleatorio
    // Generar un número aleatorio para el campo acta
    Asigna.acta = numero;
    //-----------------------------------------------------------------------------------------------------------------------------


/* **********   DESPLIEGUE Entrenadores.DAT   ********** */
    cout<<"---------------- entrenadores existentes---------------------"<<endl;
    ifstream archivo7("Entrenadores.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo7) {
        cout << "No hay aulas registradas." << endl;
        return;
    }
    EntrenadorC entrenador1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo7.read(reinterpret_cast<char*>(&entrenador1), sizeof(EntrenadorC))) {

        cout << num<< ". " << entrenador1.codigo <<"-|- "<<entrenador1.nombre<<"-|-"<<entrenador1.departamento<< endl;

        num++;
    }
    archivo7.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string identre="";
cout <<"ingrese el ide del entrenador que dirige al equipo :";
    cin >> identre;
    fstream archivo70("Entrenadores.dat", ios::binary | ios::in | ios::out);
    if (!archivo70) {
        cout << "No hay Sedes registradas." << endl;
        return;
    }
   EntrenadorC entrenador1;
    bool encontrada = false;
    while (archivo70.read(reinterpret_cast<char*>(&entrenador1), sizeof(EntrenadorC))) {
        if (entrenador1.codigo == identre) {
            archivo70.seekp(-static_cast<int>(sizeof(EntrenadorC)), ios::cur);
            strcpy(Asigna.id_entrenador,(identre).c_str());
             strcpy(Asigna.nombre_entrenador,(entrenador1.nombre));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo70.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//--------------------------------------------------------------------------------------------------------------


/* **********   DESPLIEGUE EQUIPOS.DAT   ********** */
    cout<<"---------------- equipos existentes---------------------"<<endl;
    ifstream archivo74("Equipos.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo74) {
        cout << "No hay equipos registradas." << endl;
        return;
    }
    EquiposC equipo2;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo74.read(reinterpret_cast<char*>(&equipo2), sizeof(EquiposC))) {

        cout << num<< ". " << equipo2.id <<"-|- "<<equipo2.nombre<<endl;

        num++;
    }
    archivo74.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;


do
{ //repite----------------------------------------------------------------------------------PR
string idequipo2;
    cout<<"ingrese codigo de equipo 2: ";
    cin >> idequipo2;
    fstream archivo87("Equipos.dat", ios::binary | ios::in | ios::out);
    if (!archivo87) {
        cout << "No hay Equipos registrados." << endl;
        return;
    }
    EquiposC equipo2;
    bool encontrada = false;
    while (archivo87.read(reinterpret_cast<char*>(&equipo2), sizeof(EquiposC))) {
        if (equipo2.id == idequipo2) {
            archivo87.seekp(-static_cast<int>(sizeof(EquiposC)), ios::cur);
            strcpy(Asigna.codigo_equipo2,(idequipo2).c_str());
             strcpy(Asigna.nombre_equipo2,(equipo2.nombre));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo87.close();
    if (!encontrada) {
        cout << "No se encontro un equipo con el ID proporcionado, intente de nuevo" << endl;
     res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");

//--------------------------------------------------------------------------------------------------------------

/* **********   DESPLIEGUE Entrenadores.DAT   ********** */
    cout<<"---------------- entrenadores existentes---------------------"<<endl;
    ifstream archivo54("Entrenadores.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo54) {
        cout << "No hay aulas registradas." << endl;
        return;
    }
    EntrenadorC entrenador2;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo54.read(reinterpret_cast<char*>(&entrenador2), sizeof(EntrenadorC))) {

        cout << num<< ". " << entrenador2.codigo <<"-|- "<<entrenador2.nombre<<"-|-"<<entrenador2.departamento<< endl;

        num++;
    }
    archivo54.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string identre2="";
cout <<"ingrese el ide del entrenador que dirige al equipo :";
    cin >> identre2;
    fstream archivo10("Entrenadores.dat", ios::binary | ios::in | ios::out);
    if (!archivo10) {
        cout << "No hay entrenadores 2 registradas." << endl;
        return;
    }
   EntrenadorC entrenador2;
    bool encontrada = false;
    while (archivo10.read(reinterpret_cast<char*>(&entrenador2), sizeof(EntrenadorC))) {
        if (entrenador2.codigo == identre2) {
            archivo10.seekp(-static_cast<int>(sizeof(EntrenadorC)), ios::cur);
            strcpy(Asigna.id_entrenador2,(identre2).c_str());
             strcpy(Asigna.nombre_entrenador2,(entrenador2.nombre));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo10.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//--------------------------------------------------------------------------------------------------------------

/* **********   DESPLIEGUE HORARIOS.DAT   ********** */
    cout<<"---------------- Horarios existentes---------------------"<<endl;
    ifstream archivo77("horarios.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo77) {
        cout << "No hay horarios registradas." << endl;
        return;
    }
    HorariosC horario1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo77.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC))) {

        cout << num<< ". " << horario1.id <<"-|- "<<horario1.jornada<<"-|-"<<horario1.dia<<"-1-"<<horario1.horario <<endl;

        num++;
    }
    archivo77.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string idhorario="";
cout <<"ingrese el ID del horario que se jugara el partido :";
    cin >> idhorario;
    fstream archivo78("horarios.dat", ios::binary | ios::in | ios::out);
    if (!archivo78) {
        cout << "No hay Horarios registradas." << endl;
        return;
    }
   HorariosC horario1;
    bool encontrada = false;
    while (archivo78.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC))) {
        if (horario1.id == idhorario) {
            archivo78.seekp(-static_cast<int>(sizeof(HorariosC)), ios::cur);
            strcpy(Asigna.id_horario,(idhorario).c_str());
             strcpy(Asigna.jornada,(horario1.jornada));
              strcpy(Asigna.dia,(horario1.dia));
               strcpy(Asigna.horario,(horario1.horario));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo78.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//--------------------------------------------------------------------------------------------------------------




    ofstream archivo8("asignaciones.dat", ios::binary | ios::app);
    archivo8.write(reinterpret_cast<const char*>(&Asigna), sizeof(Asignacion));
    archivo8.close();
    cout << "Asignacion ingresada exitosamente!" << endl;
    cout << "------------------------------------------------" << endl;

    // Mostrar el número de acta
    cout<<"Numero de Acta: " <<Asigna.acta<<endl;
    cin.ignore();

         system("cls");


}

void asignaciom_de_resultados::actas()
{
    system("cls");
    cout<<"------------------ ASIGNACIONES PARTIDOS --------------------"<<endl<< endl;

    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("asignaciones.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay asignaciones registradas." << endl;
        return;
    }

    Asignacion asign1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo.read(reinterpret_cast<char*>(&asign1), sizeof(Asignacion))) {
cout << "NO. Acta: "<<   asign1.acta<< endl;
cout<<"DEPORTE: "<< asign1.nombre_deporte<<endl;
cout<<"                                                                                     "<<endl;
cout<<"------------------------------Informacion Equipo 1------------------------------------"<<endl;
cout<<"|"<<"Codigo de equipo:   "<< asign1.codigo_equipo<<endl;
cout<<"|"<<"Nombre del equipo:   "<< asign1.nombre_equipo<<endl;
cout<<"|"<<"codigo del entrenador del equipo:   "<< asign1.id_entrenador<<endl;
cout<<"|"<<"nombre del entrenador del equipo:   "<< asign1.nombre_entrenador<<endl;
cout<<"                                                                                     "<<endl;
cout<<"-----------------------------Información Equipo 2------------------------------------"<<endl;
cout<<"|"<<"Codigode equipo:   "<< asign1.codigo_equipo2<< endl;
cout<<"|"<<"Nombre de equipo2:   "<< asign1.nombre_equipo2<< endl ;
cout<<"|"<<"codigo del entrenador del equipo:   "<< asign1.id_entrenador2<<endl;
cout<<"|"<<"nombre del entrenador del equipo:   "<< asign1.nombre_entrenador2<<endl;
cout<<"                                                                                     "<<endl;
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"|"<<"ID Horario:   "<< asign1.id_horario<< endl ;
cout<<"|"<<"Jornada :   "<< asign1.jornada<< endl ;
cout<<"|"<<"Dia :   "<< asign1.dia<< endl ;
cout<<"|"<<"Hora :   "<< asign1.horario<< endl ;
cout<<"--------------------------------------------------------------------------------------"<<endl;

	}

			// Se abre el archivo de texto en modo escritura
            FILE *arch = fopen("Acta_Impresa.txt", "wt");
			// Se verifica si se abrió correctamente el archivo de texto
            if (arch == NULL) {
                cerr << "Error al imprimir acta." << endl;
                // Si hay un error, se termina la ejecución del programa
                exit(1);
            }
			// Se escriben los datos del acta en el archivo de texto
            fprintf(arch, "No. Acta: %d\n", asign1.acta);
            fprintf(arch, "Deporte:   %d\n", asign1.nombre_deporte);
            fprintf(arch, "Codigo del equipo 1:   %s\n", asign1.codigo_equipo);
            fprintf(arch, "Nombre del equipo 1:     %s\n", asign1.nombre_equipo);
            fprintf(arch, "Codigo del entrenador:     %s\n", asign1.id_entrenador);
            fprintf(arch, "Nombre del entrenador:  %s\n", asign1.nombre_entrenador);

            fprintf(arch, "Codigo del equipo 2:   %s\n", asign1.codigo_equipo2);
            fprintf(arch, "Nombre del equipo 2:     %s\n", asign1.nombre_equipo2);
            fprintf(arch, "Codigo del entrenador:     %s\n", asign1.id_entrenador2);
            fprintf(arch, "Nombre del entrenador:  %s\n", asign1.nombre_entrenador2);

            fprintf(arch, "ID horario: %s\n",  asign1.id_horario);
            fprintf(arch, "Jornada:  %s\n", asign1.jornada);
            fprintf(arch, "Dia:    %s\n", asign1.dia);
            fprintf(arch, "Hora:  %s\n", asign1.horario);
            // Se cierra el archivo de texto.
            fclose(arch);
                        // Se informa al usuario que se creó el archivo de texto con los datos del acta
            cout << "Se imprimio correctamente (Acta_Impresa)" << endl;
            getch();


    archivo.close();
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}


