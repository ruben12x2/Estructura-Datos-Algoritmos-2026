#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <limits>

using namespace std;

class Banco {
private:
    queue<string> clientes;

public:
    void agregarCliente() {
        string nombre;
        cout << "Ingrese nombre del cliente: ";
        cin >> nombre;

        if (nombre.empty()) {
            throw invalid_argument("El nombre no puede estar vacio.");
        }

        clientes.push(nombre);
        cout << "Cliente agregado: " << nombre << endl;
    }

    void atenderCliente() {
        if (clientes.empty()) {
            throw runtime_error("No hay clientes para atender.");
        }

        cout << "Atendiendo a: " << clientes.front() << endl;
        clientes.pop();
    }

    void mostrarSiguienteCliente() const {
        if (clientes.empty()) {
            throw runtime_error("No hay clientes en espera.");
        }

        cout << "Siguiente cliente: " << clientes.front() << endl;
    }

    void mostrarCantidadClientes() const {
        cout << "Cantidad de clientes en espera: " << clientes.size() << endl;
    }

    void mostrarMenu() const {
        cout << "\n--- Menu Banco ---\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Mostrar siguiente cliente\n";
        cout << "4. Mostrar cantidad de clientes\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
    }
};

int main() {
    Banco banco;
    int opcion;

    do {
        banco.mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        try {
            switch (opcion) {
                case 1:
                    banco.agregarCliente();
                    break;
                case 2:
                    banco.atenderCliente();
                    break;
                case 3:
                    banco.mostrarSiguienteCliente();
                    break;
                case 4:
                    banco.mostrarCantidadClientes();
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
