#include <iostream>

using namespace std;

// Funcion de sumatoria paso a paso
int calcularSumatoria(int a, int b) {
    // Leer variables
    cout << "Leyendo variables..." << endl;
    // Procesar
    int suma = a + b;
    cout << "Procesando sumatoria..." << endl;
    // Devolver resultado
    return suma;
}

int main() {
    cout << "--- Modelo Secuencial ---" << endl;
    // La ejecucion ocurre linealmente, una despues de otra
    int resultado = calcularSumatoria(10, 5);
    cout << "El resultado devuelto es: " << resultado << endl;
    
    return 0;
}