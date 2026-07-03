#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>

using namespace std;

class SalaDeEspera {
private:
    queue<string> colaEspera;
    const int MAX_PERSONAS = 10;

public:
    void registrarPersonas() {
        cout << "Registro de " << MAX_PERSONAS << " personas en espera:\n";

        for (int i = 1; i <= MAX_PERSONAS; i++) {
            string nombre;
            cout << "Nombre de la persona " << i << ": ";
            cin >> nombre;

            if (nombre.empty()) {
                throw invalid_argument("El nombre no puede estar vacio.");
            }

            colaEspera.push(nombre);
        }
    }

    void atenderPersonas() {
        if (colaEspera.empty()) {
            throw runtime_error("No hay personas registradas en la cola.");
        }

        cout << "\n--- Atencion en orden FIFO ---\n";
        int turno = 1;

        while (!colaEspera.empty()) {
            cout << "Atendiendo a: " << colaEspera.front() << " (turno " << turno << ")" << endl;
            colaEspera.pop();
            turno++;
        }

        cout << "Todas las personas han sido atendidas.\n";
    }
};

int main() {
    SalaDeEspera sala;

    try {
        sala.registrarPersonas();
        sala.atenderPersonas();
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << endl;
    }

    return 0;
}
