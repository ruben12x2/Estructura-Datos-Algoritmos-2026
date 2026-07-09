#include <iostream>
#include <string>
using namespace std;

void menu() {
    cout << "Calculadora Simple" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Salir" << endl;
}

int main() {
    float n1, n2;
    int opcion;

    do {
        menu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese el primer numero: ";
            cin >> n1;
            cout << "Ingrese el segundo numero: ";
            cin >> n2;
        }

        switch (opcion) {
            case 1:
                cout << "El resultado es: " << n1 + n2 << endl;
                break;
            case 2:
                cout << "El resultado es: " << n1 - n2 << endl;
                break;
            case 3:
                cout << "El resultado es: " << n1 * n2 << endl;
                break;
            case 4:
                if (n2 != 0) {
                    cout << "El resultado es: " << n1 / n2 << endl;
                } else {
                    cout << "Error: No se puede dividir por cero." << endl;
                }
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}