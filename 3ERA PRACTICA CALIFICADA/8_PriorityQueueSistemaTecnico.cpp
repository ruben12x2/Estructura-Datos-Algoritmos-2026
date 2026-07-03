#include <iostream>
#include <queue>
#include <vector>
#include <stdexcept>
#include <string>
#include <limits>

using namespace std;

class Ticket {
private:
    int codigo;
    string cliente;
    int prioridad;

public:
    Ticket(int codigo, const string& cliente, int prioridad)
        : codigo(codigo), cliente(cliente), prioridad(prioridad) {
        if (prioridad < 1 || prioridad > 5) {
            throw invalid_argument("La prioridad debe estar entre 1 y 5.");
        }
    }

    int getPrioridad() const { return prioridad; }
    int getCodigo() const { return codigo; }
    string getCliente() const { return cliente; }

    bool operator<(const Ticket& otro) const {
        return prioridad < otro.prioridad;
    }
};

class SistemaTecnico {
private:
    priority_queue<Ticket> tickets;
    int contadorCodigo = 1;

public:
    void crearTicket() {
        string cliente;
        int prioridad;

        cout << "Nombre del cliente: ";
        cin >> cliente;

        cout << "Prioridad (1=baja, 5=critica): ";
        if (!(cin >> prioridad)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("La prioridad debe ser un numero.");
        }

        Ticket nuevo(contadorCodigo, cliente, prioridad);
        tickets.push(nuevo);
        cout << "Ticket #" << contadorCodigo << " creado para " << cliente << endl;
        contadorCodigo++;
    }

    void mostrarOrdenAtencion() {
        if (tickets.empty()) {
            throw runtime_error("No hay tickets registrados.");
        }

        cout << "\n--- Orden de atencion ---\n";
        priority_queue<Ticket> copia = tickets;

        int orden = 1;
        while (!copia.empty()) {
            Ticket t = copia.top();
            cout << orden << ". Codigo: " << t.getCodigo()
                 << " | Cliente: " << t.getCliente()
                 << " | Prioridad: " << t.getPrioridad() << endl;
            copia.pop();
            orden++;
        }
    }

    void mostrarMenu() const {
        cout << "\n--- Menu Sistema Tecnico ---\n";
        cout << "1. Crear ticket\n";
        cout << "2. Mostrar orden de atencion\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
    }
};

int main() {
    SistemaTecnico sistema;
    int opcion;

    do {
        sistema.mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        try {
            switch (opcion) {
                case 1:
                    sistema.crearTicket();
                    break;
                case 2:
                    sistema.mostrarOrdenAtencion();
                    break;
                case 3:
                    cout << "Saliendo...\n";
                    break;
                default:
                    cout << "Opcion no valida.\n";
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (opcion != 3);

    return 0;
}
