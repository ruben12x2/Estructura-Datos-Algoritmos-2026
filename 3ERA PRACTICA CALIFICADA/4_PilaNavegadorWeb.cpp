#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <limits>

using namespace std;

class NavegadorWeb {
private:
    stack<string> historial;

public:
    void visitarPagina() {
        string url;
        cout << "Ingrese la URL a visitar: ";
        cin >> url;

        if (url.empty()) {
            throw invalid_argument("La URL no puede estar vacia.");
        }

        historial.push(url);
        cout << "Pagina visitada: " << url << endl;
    }

    void retroceder() {
        if (historial.empty()) {
            throw runtime_error("No hay paginas en el historial para retroceder.");
        }

        string paginaActual = historial.top();
        historial.pop();
        cout << "Retrocediendo desde: " << paginaActual << endl;

        if (!historial.empty()) {
            cout << "Ahora estas en: " << historial.top() << endl;
        } else {
            cout << "No hay mas paginas en el historial.\n";
        }
    }

    void mostrarPaginaActual() const {
        if (historial.empty()) {
            throw runtime_error("No hay ninguna pagina visitada aun.");
        }

        cout << "Pagina actual: " << historial.top() << endl;
    }

    void mostrarMenu() const {
        cout << "\n--- Menu Navegador ---\n";
        cout << "1. Visitar pagina\n";
        cout << "2. Retroceder\n";
        cout << "3. Mostrar pagina actual\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
    }
};

int main() {
    NavegadorWeb navegador;
    int opcion;

    do {
        navegador.mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        try {
            switch (opcion) {
                case 1:
                    navegador.visitarPagina();
                    break;
                case 2:
                    navegador.retroceder();
                    break;
                case 3:
                    navegador.mostrarPaginaActual();
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
