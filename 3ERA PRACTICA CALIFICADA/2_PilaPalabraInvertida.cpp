#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

class InversorPalabra {
private:
    stack<char> pila;
    string palabra;

public:
    void ingresarPalabra() {
        cout << "Ingrese una palabra: ";
        cin >> palabra;

        if (palabra.empty()) {
            throw invalid_argument("No se ingreso ninguna palabra.");
        }
    }

    void apilarCaracteres() {
        for (char c : palabra) {
            pila.push(c);
        }
    }

    string obtenerInvertida() {
        string invertida;

        while (!pila.empty()) {
            invertida += pila.top();
            pila.pop();
        }

        return invertida;
    }

    void mostrarResultado() {
        cout << "Palabra original: " << palabra << endl;
        cout << "Palabra invertida: " << obtenerInvertida() << endl;
    }
};

int main() {
    InversorPalabra inversor;

    try {
        inversor.ingresarPalabra();
        inversor.apilarCaracteres();
        inversor.mostrarResultado();
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << endl;
    }

    return 0;
}
