#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Simulacion de validacion de usuario
void validarUsuario() {
    cout << "Validando usuario en el sistema..." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
}

// Simulacion de mostrar saldo
void mostrarSaldo() {
    cout << "Consultando y mostrando saldo..." << endl;
    this_thread::sleep_for(chrono::milliseconds(300));
}

int main() {
    cout << "--- Modelo Concurrente (App Bancaria) ---" << endl;
    
    // Las tareas inician de forma concurrente
    thread t1(validarUsuario);
    thread t2(mostrarSaldo);
    
    // El procesador alterna entre ellas
    t1.join();
    t2.join();
    
    cout << "Acciones registradas exitosamente." << endl;
    return 0;
}