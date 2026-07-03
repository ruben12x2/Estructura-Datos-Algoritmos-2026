#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

using namespace std;

class Contacto {
private:
    string nombre;
    string telefono;
    string correo;

public:
    Contacto(const string& nombre, const string& telefono, const string& correo)
        : nombre(nombre), telefono(telefono), correo(correo) {
        if (nombre.empty() || telefono.empty() || correo.empty()) {
            throw invalid_argument("Ningun campo puede estar vacio.");
        }
        if (correo.find('@') == string::npos) {
            throw invalid_argument("El correo electronico no es valido.");
        }
    }

    string getNombre() const { return nombre; }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << " | Telefono: " << telefono
             << " | Correo: " << correo << endl;
    }
};

class Agenda {
private:
    vector<Contacto> contactos;

public:
    void agregarContacto() {
        string nombre, telefono, correo;

        cout << "Nombre: ";
        cin >> nombre;

        for (const auto& c : contactos) {
            if (c.getNombre() == nombre) {
                throw runtime_error("Ya existe un contacto con ese nombre.");
            }
        }

        cout << "Telefono: ";
        cin >> telefono;

        cout << "Correo electronico: ";
        cin >> correo;

        contactos.emplace_back(nombre, telefono, correo);
        cout << "Contacto agregado correctamente.\n";
    }

    void buscarPorNombre() const {
        string nombre;
        cout << "Ingrese el nombre a buscar: ";
        cin >> nombre;

        auto it = find_if(contactos.begin(), contactos.end(),
            [&nombre](const Contacto& c) { return c.getNombre() == nombre; });

        if (it == contactos.end()) {
            throw runtime_error("No se encontro ningun contacto con ese nombre.");
        }

        cout << "Contacto encontrado:\n";
        it->mostrar();
    }

    void eliminarContacto() {
        string nombre;
        cout << "Ingrese el nombre del contacto a eliminar: ";
        cin >> nombre;

        auto it = find_if(contactos.begin(), contactos.end(),
            [&nombre](const Contacto& c) { return c.getNombre() == nombre; });

        if (it == contactos.end()) {
            throw runtime_error("No se encontro ningun contacto con ese nombre.");
        }

        contactos.erase(it);
        cout << "Contacto eliminado correctamente.\n";
    }

    void mostrarTodos() const {
        if (contactos.empty()) {
            throw runtime_error("No hay contactos registrados.");
        }

        cout << "\n--- Lista de Contactos ---\n";
        for (const auto& c : contactos) {
            c.mostrar();
        }
    }

    void mostrarMenu() const {
        cout << "\n--- Menu Agenda de Contactos ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Buscar por nombre\n";
        cout << "3. Eliminar contacto\n";
        cout << "4. Mostrar todos\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
    }
};

int main() {
    Agenda agenda;
    int opcion;

    do {
        agenda.mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        try {
            switch (opcion) {
                case 1:
                    agenda.agregarContacto();
                    break;
                case 2:
                    agenda.buscarPorNombre();
                    break;
                case 3:
                    agenda.eliminarContacto();
                    break;
                case 4:
                    agenda.mostrarTodos();
                    break;
                case 5:
                    cout << "Saliendo...\n";
                    break;
                default:
                    cout << "Opcion no valida.\n";
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (opcion != 5);

    return 0;
}
