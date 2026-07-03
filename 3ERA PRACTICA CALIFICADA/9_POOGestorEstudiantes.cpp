#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Estudiante {
private:
    int codigo;
    string nombre;
    int edad;
    string carrera;

public:
    Estudiante(int codigo, const string& nombre, int edad, const string& carrera)
        : codigo(codigo), nombre(nombre), edad(edad), carrera(carrera) {
        if (edad <= 0 || edad > 100) {
            throw invalid_argument("La edad ingresada no es valida.");
        }
        if (nombre.empty() || carrera.empty()) {
            throw invalid_argument("El nombre y la carrera no pueden estar vacios.");
        }
    }

    int getCodigo() const { return codigo; }

    void mostrar() const {
        cout << "Codigo: " << codigo
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Carrera: " << carrera << endl;
    }
};

class GestorEstudiantes {
private:
    vector<Estudiante> estudiantes;

public:
    void registrarEstudiante() {
        int codigo, edad;
        string nombre, carrera;

        cout << "Codigo: ";
        if (!(cin >> codigo)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("El codigo debe ser un numero.");
        }

        for (const auto& e : estudiantes) {
            if (e.getCodigo() == codigo) {
                throw runtime_error("Ya existe un estudiante con ese codigo.");
            }
        }

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Edad: ";
        if (!(cin >> edad)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("La edad debe ser un numero.");
        }

        cout << "Carrera: ";
        cin >> carrera;

        estudiantes.emplace_back(codigo, nombre, edad, carrera);
        cout << "Estudiante registrado correctamente.\n";
    }

    void mostrarTodos() const {
        if (estudiantes.empty()) {
            throw runtime_error("No hay estudiantes registrados.");
        }

        cout << "\n--- Lista de Estudiantes ---\n";
        for (const auto& e : estudiantes) {
            e.mostrar();
        }
    }

    void buscarPorCodigo() const {
        int codigo;
        cout << "Ingrese el codigo a buscar: ";

        if (!(cin >> codigo)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("El codigo debe ser un numero.");
        }

        auto it = find_if(estudiantes.begin(), estudiantes.end(),
            [codigo](const Estudiante& e) { return e.getCodigo() == codigo; });

        if (it == estudiantes.end()) {
            throw runtime_error("No se encontro ningun estudiante con ese codigo.");
        }

        cout << "Estudiante encontrado:\n";
        it->mostrar();
    }

    void mostrarMenu() const {
        cout << "\n--- Menu Gestor de Estudiantes ---\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Buscar por codigo\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
    }
};

int main() {
    GestorEstudiantes gestor;
    int opcion;

    do {
        gestor.mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        try {
            switch (opcion) {
                case 1:
                    gestor.registrarEstudiante();
                    break;
                case 2:
                    gestor.mostrarTodos();
                    break;
                case 3:
                    gestor.buscarPorCodigo();
                    break;
                case 4:
                    cout << "Saliendo...\n";
                    break;
                default:
                    cout << "Opcion no valida.\n";
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (opcion != 4);

    return 0;
}
