
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
#include "Entrenador.h"

using namespace std;


//Constructor alumnos y sus parametros
Entrenador::Entrenador(string codigo,string nombre,string nombre2, string Apellcodigoo,string Apellcodigoo2,string fechadenacimiento)
{
    // Asignando los valores de los parámetros a los atributos del objeto


    this->codigo = codigo;
    this->nombre = nombre;
   this->nombre2=nombre2;
   this->Apellido=Apellido;
   this->Apellido2=Apellido2;
   this->fechadenacimiento=fechadenacimiento;

}


//Estableciendo la id de los alumnos
string Entrenador::setcodigo(string codigo)
{
    this->codigo = codigo;
    return codigo;
}

//Obteniendo la codigo del alumno
string Entrenador::getcodigo()
{
    return codigo;
}

//Estableciendo el nombre del alumno
string Entrenador::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

//Obteniendo el nombre del alumno
string Entrenador::getnombre()
{
    return nombre;
}
//Estableciendo el nombre del alumno
string Entrenador::setnombre2(string nombre2)
{
    this->nombre2 = nombre2;
    return nombre2;
}

//Obteniendo el nombre del alumno
string Entrenador::getnombre2()
{
    return nombre2;
}

//Estableciendo el telefono del alumno
string Entrenador::setApellido(string Apellido)
{
    this->Apellido = Apellido;
    return Apellido;
}

//Obteniendo el telefono del alumno
string Entrenador::getApellido()
{
    return Apellido;
}

//Estableciendo el telefono del alumno
string Entrenador::setApellido2(string Apellido2)
{
    this->Apellido2 = Apellido2;
    return Apellido2;
}

//Obteniendo el telefono del alumno
string Entrenador::getApellido2()
{
    return Apellido2;
}
//Estableciendo la direccion del alumno
string Entrenador::setFechanaci(string fechadenacimiento)
{
    this->fechadenacimiento= fechadenacimiento;
    return fechadenacimiento;
}


//Obteniendo la direccion del alumno
string Entrenador::getFechanaci()
{
    return fechadenacimiento;
}

//Funcion menu donde muestra el sistema de gestion de alumnos
void Entrenador::menu()
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
		cout<<"+----------------------------------------------------"<<endl;
		cout<<"|                     CRUD Empleados                 |"<<endl;
		cout<<"+-----------------------------------------------------"<<endl;
		cout<<"|            1. Agregar Empleado                     |"<<endl;
		cout<<"|            2. Mostrar Empleado                     |"<<endl;
		cout<<"|            3. Modificar Empleado                   |"<<endl;
		cout<<"|            4. Borrar Empleado                      |"<<endl;
		cout<<"|            5. Regresar al menu                     |"<<endl;
		cout<<"+-----------------------------------------------------"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/]              |"<<endl;
		cout<<"+-----------------------------------------------------"<<endl;
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
					cout<<" -> ¿Deseas ingresar a otro Empleado? (S/N): ";
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
				cout<<"ERROR, OPCION NO VALcodigoA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    //Indica que si el usuario elige 6 finaliza el ciclo
    }while(opcion != 5);
}

//Funcion para insertar un estudiando
void Entrenador::insertar()
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
    cout<<"|                Agregar detalles del Empleado            |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Inicializando un generador de numeros aleatorios
    srand(time(NULL));

    //Constructor
    EntrenadorC entrenador;

    //Estableciendo variable int dando valor de "24"
    int year = 24;
    //Generando un numero aleatorio
    int numAleatorio = (rand() % 9998) + 1;

    //Agregando un codigo aleatorio para cada alumno
    string codigoString = "7575-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < codigoString.length(); ++i) {
        entrenador.codigo[i] = codigoString[i];
    }
    entrenador.codigo[codigoString.length()] = '\0';

    //Mensaje generando carnet
    cout<<"       -> Codigo del Empleado: " << entrenador.codigo<<endl;
    cin.ignore();

    //Mensaje para ingresar el nombre del alumno
    cout<<"       -> Ingrese el nombre del Empleado:  ";
    cin.getline(entrenador.nombre, 50);

//Mensaje para ingresar el segundo nombre
    cout<<"       -> Ingrese el Puesto del Empleado:  ";
    cin.getline(entrenador.puesto, 50);

//Mensaje para ingresar el apellcodigoo
    cout<<"       -> Ingrese el departamento del Empleado:  ";
    cin.getline(entrenador.departamento, 50);
    //Mensaje para ingresar el segundo apellcodigoo
    cout<<"       -> Ingrese el sueldo del empleado:  ";
    cin.getline(entrenador.sueldo, 50);
    //Mensaje para ingresar fecha de naciminto entrenador
    cout<<"       -> Ingrese el estatus del empleado ";
    cin.getline(entrenador.estatus, 50);

    cout<<"+---------------------------------------------------------+"<< endl;

    //Escribiendo los datos del obteto alumno en un archivo binario llamado en modo de escritura binaria, agregando los datos al final del archivo si ya existe.
    ofstream archivo("Entrenadores.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&entrenador), sizeof(entrenador));
    archivo.close();
}

void Entrenador::desplegar()
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
    cout << "+                            Tabla de Detalles del Empleado                       +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //Abriendo un archivo binario llamado en modo de lectura binaria y se comprueba si la apertura fue exitosa
  //-> // ifstream archivo("ProcesoAlumnos.dat", ios::binary | ios::in);
    ifstream archivo3("Entrenadores.dat", ios::binary | ios::in);
  //->  //if (!archivo || !archivo3) {
    if (!archivo3){
            //Si no encuentra informacion muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion..." << endl;
        return;
    }

    // instancia de la clase Alumno llamada alumno
    EntrenadorC entrenador;
    // instancia de la clase Procealumnos llamada procealumnos
 //->   //Procealumnos procealumnos;

    //Ciclo while para leer los datos del archivo binario  y los almacenan en un objeto alumno llamado alumno y repite este procedimiento hasta que se acaben los datos por leer
  while (archivo3.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC))) //archivo.read(reinterpret_cast<char*>(&procealumnos), sizeof(Procealumnos)) &&
    {

        //Se muestra los detalles del estudiante
        cout << "                        Código Empleado: " << entrenador.codigo << endl;
        cout << "                        Nombre Empleado: " << entrenador.nombre << endl;
        cout << "                        Codigo Puesto " << entrenador.puesto << endl;
         cout << "                       Codigo Departamento " << entrenador.departamento << endl;
        cout << "                        Sueldo Empleado " << entrenador.sueldo << endl;
        cout << "                        Estatus Empleado " << entrenador.estatus << endl;

        cout << "+---------------------------------------------------------------------------------+" << endl;
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
            fprintf(arch, "Codigo Empleado: %d\n", entrenador.codigo);
            fprintf(arch, "Nombre del Empleado:   %d\n", entrenador.nombre);
            fprintf(arch, "Codigo del puesto:   %s\n", entrenador.puesto);
            fprintf(arch, "Codigo del Departamento:     %s\n", entrenador.departamento);
            fprintf(arch, "Sueldo del Empleado:     %s\n", entrenador.sueldo);
            fprintf(arch, "Estatus Empleado:  %s\n", entrenador.estatus);
            fclose(arch);
                        // Se informa al usuario que se creó el archivo de texto con los datos del acta
            cout << "Se imprimio correctamente (Acta_Impresa)" << endl;
            getch();

    archivo3.close(); //cierra el archivo

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion para modificar los alumnos ya registrados
void Entrenador::modificar()
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
    string codigoPersona;

    //Variable bool con valor false
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del Empleado                           +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //abre un archivo binario en modo de lectura y escritura
    archivo1.open("Entrenadores.dat", ios::binary | ios::in | ios::out);
    //verificacion si se abre el archivo
    if (!archivo1) {
        //si no se pudo muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }
    //si se pudo abrir correctament pcodigoe la codigo de la persona
    cout << "Ingrese el codigo de la persona que desea modificar: ";
    cin >> codigoPersona;

    EntrenadorC entrenador;
    // Lee cada registro del archivo y busca el codigo proporcionado por el usuario
    while (archivo1.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC))) {
        if (entrenador.codigo == codigoPersona) {
            // Establece el indicador como verdadero si se encuentra el estudiante
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo codigo del Empleado: ";
            cin >> entrenador.codigo;
            cout << "Ingrese el nuevo nombre del Empleado: ";
            cin >> entrenador.nombre;
            cout << "Ingrese el nuevo puesto del Empleado: ";
            cin >> entrenador.puesto;
            cout << "Ingrese el nuevo departamento del Empleado: ";
            cin >> entrenador.departamento;
            cout << "Ingrese el nuevo sueldo del Empleado: ";
            cin >> entrenador.sueldo;
            cout << "Ingrese el nuevo status del empleado : ";
            cin >> entrenador.estatus;



            // Posiciona el puntero de escritura al inicio del registro que se está modificando
            archivo1.seekp(-static_cast<int>(sizeof(EntrenadorC)), ios::cur);

            // Escribe  nuevos detalles del entrenador en el archivo
            archivo1.write(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC));
            break;
        }
    }

    archivo1.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un Entrenador con el codigo proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
//funcion para borrarr a las alumnos registradas
void Entrenador::borrar()
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
	string codigoPersona;

    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar Empleado                                   +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    // Abre el archivo binario alumnos.dat en modo de lectura
    ifstream archivo("Entrenadores.dat", ios::binary);

    //verifica si se abrio el archivo
	if(!archivo)
	{
        //si no se abrio imprime el siguiente mensaje
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    // Crea un nuevo archivo binario en modo de escritura
	ofstream archivo2("Entrenadores2.dat", ios::binary);

	EntrenadorC entrenador;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el codigo de la persona que desea eliminar: ";
    cin>>codigoPersona;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
		while(archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC)))
		{
		    // Si el nombre del usuario no coinccodigoe con el proporcionado, se escribe en el nuevo archivo
			if(entrenador.codigo != codigoPersona)
			{
				archivo2.write(reinterpret_cast<const char*>(&entrenador), sizeof(EntrenadorC));
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
		remove("Entrenadores.dat");

        //y renombra el Alumnos2.dat a alumnos.dat
		rename("Entrenadores2.dat","Entrenadores.dat");

		if (resta)
        {
        //Si se encuentra el alumno muestra el mensaje
        cout << "Empleado eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el alumno muestra el mensaje
        cout << "No se a podido encontrar el codigo del Empleado" << endl;
        }
}

