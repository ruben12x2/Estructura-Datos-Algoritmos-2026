#include <iostream>
#include <string>
using namespace std;

int main(){
   float n1, n2 ;
    char op;
    cout << "Ingrese el primer numero: ";
    cin >> n1;
    cout << "Ingrese el segundo numero: ";
    cin >> n2;
    cout << "Ingrese la operacion a realizar (+, -, *, /): ";
    cin >> op;
    switch(op){
        case '+':
            cout << "El resultado es: " << n1 + n2 << endl;
            break;
        case '-':
            cout << "El resultado es: " << n1 - n2 << endl;
            break;
        case '*':
            cout << "El resultado es: " << n1 * n2 << endl;
            break;
        case '/':
            if(n2 != 0){
                cout << "El resultado es: " << n1 / n2 << endl;
            } else {
                cout << "Error: No se puede dividir por cero." << endl;
            }
            break;
        default:
            cout << "Operacion no valida." << endl;
    }
    return 0;
}