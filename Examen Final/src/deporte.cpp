#include "deporte.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
#include "Bitacora.h"
#include "Login.h"

using namespace std;


deporte::deporte(string id,string nombre)
{
    // Asignando los valores de los parámetros a los atributos del objeto


    this->id = id;
    this->nombre = nombre;


}


//Estableciendo la id de los alumnos
string deporte::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniendo la id del alumno
string deporte::getid()
{
    return id;
}

//Estableciendo el nombre del alumno
string deporte::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

//Obteniendo el nombre del alumno
string deporte::getnombre()
{
    return nombre;
}

//Funcion menu donde muestra el sistema de gestion de alumnos
void deporte::menudeportes()
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
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"|           BIENVENIDO AL SISTEMA DE DEPORTES          |"<<endl;
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"|                1. Agregar Deportes                   |"<<endl;
		cout<<"|                2. Mostrar Deportes                   |"<<endl;
		cout<<"|                3. Modificar Deportes                 |"<<endl;
		cout<<"|                4. Borrar Deportes                    |"<<endl;
		cout<<"|                5. Regresar al menu                   |"<<endl;
		cout<<"--------------------------------------------------------"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/]                 |"<<endl;
		cout<<"--------------------------------------------------------"<<endl;
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
					cout<<" -> ¿Deseas ingresar a otro Deporte? (S/N): ";
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
void deporte::insertar()
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
    cout<<"|                Agregar detalles del Deporte          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Inicializando un generador de numeros aleatorios
    srand(time(NULL));

    //Constructor
    Deporte deporte1;

    //Estableciendo variable int dando valor de "24"
    int year = 24;
    //Generando un numero aleatorio
    int numAleatorio = (rand() % 9998) + 1;

    //Agregando un id aleatorio para cada alumno
    string idString = "9090-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        deporte1.id[i] = idString[i];
    }
    deporte1.id[idString.length()] = '\0';

    //Mensaje generando carnet
    cout<<"       -> Generando id del Deporte: " << deporte1.id<<endl;
    cin.ignore();

    //Mensaje para ingresar el nombre del alumno
    cout<<"       -> Ingrese el nombre del Deporte:  ";
    cin.getline(deporte1.nombre, 50);

    cout<<"+---------------------------------------------------------+"<< endl;

    //Escribiendo los datos del obteto alumno en un archivo binario llamado en modo de escritura binaria, agregando los datos al final del archivo si ya existe.
    ofstream archivo("Deportes.dat", ios::binary | ios::app);
    /** \brief
     *
     * \param deporte1
     * \return archivo.write(reinterpret_cast<const char*>(&deporte1),
     *
     */
    archivo.write(reinterpret_cast<const char*>(&deporte1), sizeof(deporte1));
    archivo.close();
}

void deporte::desplegar()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2202", "ALMD"); // Parámetros

    //Limpiando pantalla
    system("cls");


    //Mostrando el encabezado de la tabla de detalles del estudiante
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles de Deportes                 +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //Abriendo un archivo binario llamado en modo de lectura binaria y se comprueba si la apertura fue exitosa
  //-> // ifstream archivo("ProcesoAlumnos.dat", ios::binary | ios::in);
    ifstream archivo3("Deportes.dat", ios::binary | ios::in);
  //->  //if (!archivo || !archivo3) {
    if (!archivo3){
            //Si no encuentra informacion muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion..." << endl;
        return;
    }

    // instancia de la clase Alumno llamada alumno
    Deporte deporte1;
    // instancia de la clase Procealumnos llamada procealumnos
 //->   //Procealumnos procealumnos;

    //Ciclo while para leer los datos del archivo binario  y los almacenan en un objeto alumno llamado alumno y repite este procedimiento hasta que se acaben los datos por leer
  while (archivo3.read(reinterpret_cast<char*>(&deporte1), sizeof(Deporte))) //archivo.read(reinterpret_cast<char*>(&procealumnos), sizeof(Procealumnos)) &&
    {

        //Se muestra los detalles del estudiante
        cout << "                        ID del Deporte: " << deporte1.id << endl;
        cout << "                        Nombre del Deporte: " << deporte1.nombre << endl;

        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo3.close(); //cierra el archivo

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion para modificar los alumnos ya registrados
void deporte::modificar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2203", "ALMM"); // Parámetros


    //Limpiando pantalla
	system("cls");
	//Declarando variables tipo fstream y string
    fstream archivo1;
    string idDeporte;

    //Variable bool con valor false
    bool encontrado = false;

    cout << "---------------------------------------------------------------" << endl;
    cout << "|            Modificar Detalles del Deporte                    " << endl;
    cout << "---------------------------------------------------------------" << endl;

    //abre un archivo binario en modo de lectura y escritura
    archivo1.open("Deportes.dat", ios::binary | ios::in | ios::out);
    //verificacion si se abre el archivo
    if (!archivo1) {
        //si no se pudo muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }
    //si se pudo abrir correctament pide la id de la persona
    cout << "Ingrese el ID del Deporte que desea modificar: ";
    cin >> idDeporte;

    Deporte deporte1;
    // Lee cada registro del archivo y busca el ID proporcionado por el usuario
    while (archivo1.read(reinterpret_cast<char*>(&deporte1), sizeof(Deporte))) {
        if (deporte1.id == idDeporte) {
            // Establece el indicador como verdadero si se encuentra el estudiante
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo ID del Deporte: ";
            cin >> deporte1.id;
            cout << "Ingrese el nuevo nombre del Deporte: ";
            cin >> deporte1.nombre;


            // Posiciona el puntero de escritura al inicio del registro que se está modificando
            archivo1.seekp(-static_cast<int>(sizeof(Deporte)), ios::cur);

            // Escribe  nuevos detalles del entrenador en el archivo
            archivo1.write(reinterpret_cast<char*>(&deporte1), sizeof(Deporte));
            break;
        }
    }

    archivo1.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un Deporte con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
//funcion para borrarr a las alumnos registradas
void deporte::borrar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2204", "ALMB"); // Parámetros


    //Limpia pantalla
	system("cls");
	//declara una variable string
	string idDeporte;

	//Muestra el encabezado de la tabla para eliminar un estudiante
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar Deporte                                       +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    // Abre el archivo binario alumnos.dat en modo de lectura
    ifstream archivo("Deportes.dat", ios::binary);

    //verifica si se abrio el archivo
	if(!archivo)
	{
        //si no se abrio imprime el siguiente mensaje
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    // Crea un nuevo archivo binario en modo de escritura
	ofstream archivo2("Deportes2.dat", ios::binary);

	Deporte deporte1;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el ID del deporte que desea eliminar: ";
    cin>>idDeporte;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
		while(archivo.read(reinterpret_cast<char*>(&deporte1), sizeof(Deporte)))
		{
		    // Si el nombre del usuario no coincide con el proporcionado, se escribe en el nuevo archivo
			if(deporte1.id != idDeporte)
			{
				archivo2.write(reinterpret_cast<const char*>(&deporte1), sizeof(Deporte));
			}
			else
			{
			    resta = true;
			}

		}
        //cierra ambos archivos
		archivo.close();
		archivo2.close();

        //remueve el Alumnos.dat
		remove("Deportes.dat");

        //y renombra el Alumnos2.dat a alumnos.dat
		rename("Deportes2.dat","Deportes.dat");

		if (resta)
        {
        //Si se encuentra el alumno muestra el mensaje
        cout << "Deporte eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el alumno muestra el mensaje
        cout << "No se a podido encontrar el codigo del deporte" << endl;
        }
}
//----------------------------------------------------------------------------------------------------------------------------------------------
