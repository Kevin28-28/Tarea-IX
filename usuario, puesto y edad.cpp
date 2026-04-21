#include <iostream>
#include <fstream> // Libreria para archivos
#include <string>
#include <vector>

using namespace std;

// --- ESTRUCTURA ---
struct Usuario {
    string nombreCompleto;
    string posicion;
    int edad;
};

// --- PROTOTIPOS DE FUNCIONES ---
void guardarUsuario();
void mostrarUsuarios();
void mostrarMenu();

// --- FUNCION PRINCIPAL ---
int main() {
    // Requisito: Nombre del creador
    cout << "========================================" << endl;
    cout << "Programa creado por: Kevin Andres Rivas Velasquez" << endl;
    cout << "========================================" << endl;

    int opcion;
    // Ciclo para mantener el menu activo
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer despues de leer un numero

        // Condicionales para las opciones
        switch (opcion) {
            case 1:
                guardarUsuario();
                break;
            case 2:
                mostrarUsuarios();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida, intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}

// --- DESARROLLO DE FUNCIONES ---

void mostrarMenu() {
    cout << "\n--- MENU ---" << endl;
    cout << "1. Guardar usuario" << endl;
    cout << "2. Mostrar usuarios" << endl;
    cout << "3. Salir" << endl;
}

void guardarUsuario() {
    Usuario nuevoUser;
    ofstream archivo;
    // Abrir archivo en modo append (para no borrar lo anterior)
    archivo.open("usuarios.txt", ios::app);

    if (archivo.is_open()) {
        cout << "--- Registro de Usuario ---" << endl;
        cout << "Nombre completo: ";
        getline(cin, nuevoUser.nombreCompleto);
        cout << "Posicion en la empresa: ";
        getline(cin, nuevoUser.posicion);
        cout << "Edad: ";
        cin >> nuevoUser.edad;
        cin.ignore();

        // Guardar datos en archivo
        archivo << "Nombre: " << nuevoUser.nombreCompleto << " | "
                << "Posicion: " << nuevoUser.posicion << " | "
                << "Edad: " << nuevoUser.edad << endl;
        
        archivo.close();
        cout << "Confirmacion: Usuario guardado exitosamente." << endl;
    } else {
        cout << "Error: No se pudo abrir el archivo." << endl;
    }
}

void mostrarUsuarios() {
    ifstream archivo;
    string linea;
    archivo.open("usuarios.txt", ios::in);

    if (archivo.is_open()) {
        cout << "\n--- Lista de Usuarios ---" << endl;
        bool vacio = true;
        while (getline(archivo, linea)) {
            cout << linea << endl;
            vacio = false;
        }
        if (vacio) {
            cout << "El archivo esta vacio." << endl;
        }
        archivo.close();
    } else {
        cout << "No hay registros guardados aun." << endl;
    }
}
