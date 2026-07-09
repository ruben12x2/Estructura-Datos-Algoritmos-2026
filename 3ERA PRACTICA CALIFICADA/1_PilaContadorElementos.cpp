#include <iostream>
#include <stack>
#include <stdexcept>
#include <limits>

using namespace std;

class GestorPila {
private:
    stack<int> pila;

public:
    void ingresarDatos() {
        int numero;

        cout << "Ingrese numeros (-1 para finalizar):\n";

        while (true) {
            cout << "Numero: ";

            if (!(cin >> numero)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Intente de nuevo.\n";
                continue;
            }

            if (numero == -1) break;

            pila.push(numero);
        }
    }

    void mostrarResultados() const {
        try {
            if (pila.empty()) {
                throw runtime_error("La pila esta vacia, no se ingresaron elementos.");
            }

            cout << "\n--- Resultados ---\n";
            cout << "Cantidad de elementos en la pila: " << pila.size() << endl;
            cout << "Ultimo elemento ingresado: " << pila.top() << endl;
        }
        catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
};

int main() {
    GestorPila gestor;

    try {
        gestor.ingresarDatos();
        gestor.mostrarResultados();
    }
    catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << endl;
    }

    return 0;
}
