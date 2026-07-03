#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <limits>

using namespace std;

class ColaClientes {
private:
    queue<string> clientes;

public:
    void registrarCliente() {
        string nombre;
        cout << "Ingrese nombre del cliente: ";
        cin >> nombre;

        if (nombre.empty()) {
            throw invalid_argument("El nombre no puede estar vacio.");
        }

        clientes.push(nombre);
        cout << "Cliente registrado: " << nombre << endl;
    }

    void atenderCliente() {
        if (clientes.empty()) {
            throw runtime_error("No hay clientes en la cola para atender.");
        }

        string atendido = clientes.front();
        clientes.pop();
        cout << "Cliente atendido: " << atendido << endl;
    }

    void mostrarPendientes() const {
        if (clientes.empty()) {
            cout << "No hay clientes pendientes.\n";
            return;
        }

        queue<string> copia = clientes;
        cout << "Clientes pendientes (" << copia.size() << "): ";

        while (!copia.empty()) {
            cout << copia.front();
            copia.pop();
            if (!copia.empty()) cout << ", ";
        }
        cout << endl;
    }

    void mostrarMenu() const {
        cout << "\n--- Menu Cola de Clientes ---\n";
        cout << "1. Registrar cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Mostrar clientes pendientes\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
    }
};

int main() {
    ColaClientes cola;
    int opcion;

    do {
        cola.mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        try {
            switch (opcion) {
                case 1:
                    cola.registrarCliente();
                    break;
                case 2:
                    cola.atenderCliente();
                    break;
                case 3:
                    cola.mostrarPendientes();
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
