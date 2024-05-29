#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include "Bitacora.h"
#include "Login.h"
#include"Entrenador.h"
#include"asignaciom_de_resultados.h"
using namespace std;
void menuGeneral();
void catalogos();
void reportes();
void procesos();
void seguridad();


string codigoPrograma="1";



int main() {
    Login login;
if (login.validacion()) {
    menuGeneral();
} else {
    cout << "Intentelo nuevamente..." << endl;
}

return 0;
}

void menuGeneral()
{

    int choice;

    do
    {

        system("cls");

        cout << "\t\t\t----------------------------------------" << endl;
        cout << "\t\t\t|   Alisson Rocio Abigail López Ortiz   |"<< endl;
        cout << "\t\t\t|             9959-23-7225              |"<< endl;
        cout << "\t\t\t----------------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Informes" << endl;
        cout << "\t\t\t 3. Bitacora" << endl;
        cout << "\t\t\t 4. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            catalogos();
            break;


        case 2:
            {
                Entrenador entrenador;
                entrenador.desplegar();
               break;
            }

        case 3:
            {
                Bitacora bitacora;
                bitacora.mostrarBitacora();
                break;
            }


        case 4:
            {

            string usuarioActual = Login::getUsuarioActual();

            Bitacora bitacora;

            // Registro del ingreso en la bitácora
            bitacora.ingresoBitacora(usuarioActual, "2600", "LGO");
            exit(0);
            }

        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 4);
}


void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|                    CATALOGO              |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Empleado" << endl;
        cout << "\t\t\t 2. Regresar" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2/3/4/5/]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Entrenador Entrenador1;
            Entrenador1.menu();
            break;
        }
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    }while (choice != 5);
}

