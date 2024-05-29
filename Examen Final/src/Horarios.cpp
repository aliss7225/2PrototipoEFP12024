#include "Horarios.h"


//Incluyendo las librerias a utilizar
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

//Incluyendo el encabezado de bitacora
#include "Bitacora.h"
#include "Login.h"

using namespace std;

//Constructor alumnos y sus parametros
Horarios::Horarios(string id, string jornada,string dia,string horario)
{
    // Asignando los valores de los parámetros a los atributos del objeto


    this->id = id;
    this->jornada = jornada;
    this->dia = dia;
    this->horario = horario;


}


//Estableciendo la id de los alumnos
string Horarios::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniendo la id del alumno
string Horarios::getid()
{
    return id;
}

//Estableciendo el nombre del alumno
string Horarios::setjornada(string jornada)
{
    this->jornada = jornada;
    return jornada;
}

//Obteniendo el nombre del alumno
string Horarios::getjornada()
{
    return jornada;
}

//Estableciendo el nombre del alumno
string Horarios::setdia(string dia)
{
    this->dia = dia;
    return dia;
}

//Obteniendo el nombre del alumno
string Horarios::getdia()
{
    return dia;
}

//Funcion menu donde muestra el sistema de gestion de alumnos
void Horarios::menuHorario()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2200", "ALM"); // Parámetros

    //Definiendo Variable int
    int opcion;
    //Definiendo Variable char
	char continuar;

	do
    {
        //Limpiando pantalla
		system("cls");

		//Se muestra el diseño del sistema de gestion de alumnos
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE HORARIOS    |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Horarios                   |"<<endl;
		cout<<"|            2. Mostrar Horarios                    |"<<endl;
		cout<<"|            3. Modificar Horarios                  |"<<endl;
		cout<<"|            4. Borrar Horarios                     |"<<endl;
		cout<<"|            5. Regresar al menu                      |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/]              |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cin>>opcion;

        //Permitiendo que el usuario eliga una opcion
		switch(opcion)
		{
		    //Opcion 1
			case 1:
				do
				{
				    //Funcion para insertar un alumno
					insertar();
					//Luego de ingresar un alumno mostrara el mensaje
					cout<<" -> ¿Deseas ingresar a otro estudiante? (S/N): ";
					cin>>continuar;

                //Si la respuesta es s o S, insertara otro estudiante
				}while(continuar=='S' || continuar=='s');
				break;

            //Opcion 2
			case 2:
			    //Funcion para poder desplegar los alumnos registrados
                desplegar(  );
				break;

            //Opcion 3
			case 3:
			    //Funcion para modificar un alumno registrado
                modificar();
				break;

            //Opcion 4
			case 4:
			    //Funcion para borrar un alumno registrado

                borrar();
                break;

            case 5:
				break;
				//Si no elige una de las 5 opciones, mostrara el siguiente mensaje
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    //Indica que si el usuario elige 6 finaliza el ciclo
    }while(opcion != 5);
}

//Funcion para insertar un estudiando
void Horarios::insertar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2201", "ALMI"); // Parámetros


    //Limpiando pantalla
    system("cls");

    //Encabezado del diseño insertar estudiante
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Entrenador          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;


    srand(time(NULL));

    //Constructor
    HorariosC horario1;

    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;


    string idString = "1010-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        horario1.id[i] = idString[i];
    }
    horario1.id[idString.length()] = '\0';

    cout<<"       -> Generando id del Horario: " << horario1.id<<endl;
    cin.ignore();


    cout<<" Matutina "<< endl;
    cout<<" Vespertina "<< endl;
    cout<<" Nocturna "<< endl;
    cout<<" Ingrese la Jornada: "<<endl;

    cin.getline(horario1.jornada, 20);

    cout<<" Lunes "<< endl;
    cout<<" Martes "<< endl;
    cout<<" Miercoles "<< endl;
    cout<<" Jueves "<< endl;
    cout<<" Viernes "<< endl;
    cout<<" Sabado "<< endl;
    cout<<" Domingo "<< endl;
    cout<<" Ingrese la dia: "<<endl;

    cin.getline(horario1.dia, 15);

    cout<<"5:00 PM"<<endl;
    cout<<"6:00 PM"<<endl;
    cout<<"7:00 PM"<<endl;
    cout<<"8:00 PM"<<endl;
    cout<<"Ingrese la Hora:  ";

    cin.getline(horario1.horario, 20);


    cout<<"+---------------------------------------------------------+"<< endl;


    ofstream archivo("Horarios.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&horario1), sizeof(horario1));
    archivo.close();
}

void Horarios::desplegar()
{

    string usuarioActual = Login::getUsuarioActual();


    Bitacora bitacora;


    bitacora.ingresoBitacora(usuarioActual, "2202", "ALMD"); // Parámetros


    system("cls");


    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Horarios                 +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    ifstream archivo3("Horarios.dat", ios::binary | ios::in);
    if (!archivo3){
        cout << "Error, no se encuentra informacion..." << endl;
        return;
    }


    HorariosC horario1;

  while (archivo3.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC)))
    {

        cout << "ID del Horario: " << horario1.id << endl;
        cout << "Jornada: " << horario1.jornada << endl;
        cout << "Dia: " << horario1.dia << endl;
        cout << "Hora: " << horario1.horario << endl;



        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo3.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}


void Horarios::modificar()
{

    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;

    bitacora.ingresoBitacora(usuarioActual, "2203", "ALMM");

	system("cls");
    fstream archivo1;
    string idhorario;

    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del Equipo                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;


    archivo1.open("Horarios.dat", ios::binary | ios::in | ios::out);
    if (!archivo1) {

        cout << "Error, no se encuentra informacion...";
        return;
    }

    cout << "Ingrese el ID del Horario que desea modificar: ";
    cin >> idhorario;

    HorariosC horario1;
  while (archivo1.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC))) {
        if (horario1.id == idhorario) {
            encontrado = true;


            cout << "Ingrese el nuevo ID del horario: ";
            cin >> horario1.id;
            system("cls");





            cout<<" Matutina "<< endl;
            cout<<" Vespertina "<< endl;
            cout<<" Nocturna "<< endl;

            cout << "Ingrese la nueva jornada  : ";
            cin >> horario1.jornada;

            system("cls");
    cout<<" Lunes "<< endl;
    cout<<" Martes "<< endl;
    cout<<" Miercoles "<< endl;
    cout<<" Jueves "<< endl;
    cout<<" Viernes "<< endl;
    cout<<" Sabado "<< endl;
    cout<<" Domingo "<< endl;
    cout<<" Ingrese el nuevo dia:  ";

            system("cls");

    cout<<"5:00 PM"<<endl;
    cout<<"6:00 PM"<<endl;
    cout<<"7:00 PM"<<endl;
    cout<<"8:00 PM"<<endl;

        cout<<"  Ingrese la nueva hora:  ";
    cin.getline(horario1.horario, 20);



            archivo1.seekp(-static_cast<int>(sizeof(HorariosC)), ios::cur);

            archivo1.write(reinterpret_cast<char*>(&horario1), sizeof(HorariosC));
            break;
        }
    }

    archivo1.close();

    if (!encontrado) {
        cout << "No se encontró un Equipo con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void Horarios::borrar()
{

    string usuarioActual = Login::getUsuarioActual();

    Bitacora bitacora;


    bitacora.ingresoBitacora(usuarioActual, "2204", "ALMB");


	system("cls");
	string idhorario;

    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar Horario                                +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    ifstream archivo("Horarios.dat", ios::binary);

	if(!archivo)
	{

		cout<<"Error, no se encuentra informacion...";
		return;
	}

	ofstream archivo2("Horarios2.dat", ios::binary);

	HorariosC horario1;


    cout<<"-> Ingrese el ID del Horario que desea eliminar: ";
    cin>>idhorario;


    bool resta = false;


		while(archivo.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC)))
		{
			if(horario1.id != idhorario)
			{
				archivo2.write(reinterpret_cast<const char*>(&horario1), sizeof(HorariosC));
			}
			else
			{
			    resta = true;
			}

		}

		archivo.close();
		archivo2.close();


		remove("Horarios.dat");

		rename("Horarios2.dat","horarios.dat");

		if (resta)
        {

        cout << "horario eliminado con exito." << endl;
        }
        else
        {

        cout << "No se a podido encontrar el codigo del horario" << endl;
        }
}

