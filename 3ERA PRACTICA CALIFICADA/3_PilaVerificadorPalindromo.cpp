#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class VerificadorPalindromo {
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

    bool esPalindromo() {
        string normalizada = palabra;
        transform(normalizada.begin(), normalizada.end(), normalizada.begin(),
                  [](unsigned char c) { return tolower(c); });

        for (char c : normalizada) {
            pila.push(c);
        }

        for (char c : normalizada) {
            if (pila.empty()) {
                throw runtime_error("Error inesperado: pila vacia durante la verificacion.");
            }

            if (c != pila.top()) {
                return false;
            }
            pila.pop();
        }

        return true;
    }

    void mostrarResultado() {
        cout << "Palabra: " << palabra << endl;
        cout << (esPalindromo() ? "Es palindromo." : "No es palindromo.") << endl;
    }
};

int main() {
    VerificadorPalindromo verificador;

    try {
        verificador.ingresarPalabra();
        verificador.mostrarResultado();
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << endl;
    }

    return 0;
}
