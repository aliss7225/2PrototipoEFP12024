#include <cstring>
//Incluyendo encabezados
#include "Bitacora.h"
#include "Login.h"

//Funcion para ingresar a la bitacora
void Bitacora::ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso) {

    // abre el archivo de bitácora en modo de escritura y binario
    ofstream archivo("Bitacora.dat", ios::binary | ios::app);

    // Verifica si el archivo se ha abierto correctamente
    if (archivo.is_open()) {

        //Instancia de RegistroBitacora
        RegistroBitacora registro;

        // Copia el nombre del usuario al registro
        strncpy(registro.nombre, usuario.c_str(), sizeof(registro.nombre) - 1);
        registro.nombre[sizeof(registro.nombre) - 1] = '\0';

        // Copia el código del programa al registro
        strncpy(registro.aplicacion, codigoPrograma.c_str(), sizeof(registro.aplicacion) - 1);
        registro.aplicacion[sizeof(registro.aplicacion) - 1] = '\0';

        // Copia el tipo de ingreso al registro
        strncpy(registro.accion, tipoIngreso.c_str(), sizeof(registro.accion) - 1);
        registro.accion[sizeof(registro.accion) - 1] = '\0';

        // Obteniendo la fecha y hora actual y la guarda en el registro
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string fechaHora = to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday) + " " +
                           to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
        strncpy(registro.fechaHora, fechaHora.c_str(), sizeof(registro.fechaHora) - 1);
        registro.fechaHora[sizeof(registro.fechaHora) - 1] = '\0';

        // Escribe el registro en el archivo
        archivo.write(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora));

        // Cerrar el archivo después de escribir
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de bitácora." << endl;
    }
}



void Bitacora::mostrarBitacora() {

    // Obteniendo el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Registra el ingreso del usuario actual en la bitácora
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2000", "BIT");

    // Limpiando la pantalla
    system("cls");

    // Abre el archivo de bitácora en modo de lectura binaria
    ifstream archivo("Bitacora.dat", ios::binary | ios::in);

    // Verificacion si el archivo se ha abierto correctamente
    if (!archivo) {

        //Si no se ha abierto correctamente muestra lo siguiente
        cout << "No hay información registrada en la bitácora." << endl;
        return;
    }

    //Instancia de RegistroBitacora
    RegistroBitacora registro;
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora))) {
        cout << "Usuario: " << registro.nombre << ", Aplicacion: " << registro.aplicacion << ", Accion: " << registro.accion << ", Fecha y Hora: " << registro.fechaHora << endl;
    }
    //Cerrar archivo
    archivo.close();

    //Mensaje al usuario
    cout << "Presione Enter para continuar";
    cin.ignore();
    cin.get();
}



