#include "Ej4.hpp"
#include <iostream>
#include <memory>

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menú de Opciones ---\n";
    cout << "1. Mostrar información de la Caja de Ahorro\n";
    cout << "2. Mostrar información de la Cuenta Corriente\n";
    cout << "3. Depositar en la Caja de Ahorro\n";
    cout << "4. Depositar en la Cuenta Corriente\n";
    cout << "5. Retirar de la Caja de Ahorro\n";
    cout << "6. Retirar de la Cuenta Corriente\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    // Solicitar el nombre del titular
    string titular;
    cout << "Ingrese el nombre del titular de las cuentas: ";
    getline(cin, titular);

    // Crear una Caja de Ahorro y una Cuenta Corriente para el mismo titular
    auto caja = make_shared<CajaDeAhorro>(titular, 500);
    CuentaCorriente corriente(titular, 200, caja.get());

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Opción inválida. Intente nuevamente.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                // Mostrar información de la Caja de Ahorro
                caja->mostrarInfo();
                break;
            }
            case 2: {
                // Mostrar información de la Cuenta Corriente
                corriente.mostrarInfo();
                break;
            }
            case 3: {
                // Depositar en la Caja de Ahorro
                double cantidad;
                cout << "Ingrese la cantidad a depositar en la Caja de Ahorro: ";
                cin >> cantidad;
                if (cantidad > 0) {
                    caja->depositar(cantidad);
                } else {
                    cout << "Cantidad inválida. Intente nuevamente.\n";
                }
                break;
            }
            case 4: {
                // Depositar en la Cuenta Corriente
                double cantidad;
                cout << "Ingrese la cantidad a depositar en la Cuenta Corriente: ";
                cin >> cantidad;
                if (cantidad > 0) {
                    corriente.depositar(cantidad);
                } else {
                    cout << "Cantidad inválida. Intente nuevamente.\n";
                }
                break;
            }
            case 5: {
                // Retirar de la Caja de Ahorro
                double cantidad;
                cout << "Ingrese la cantidad a retirar de la Caja de Ahorro: ";
                cin >> cantidad;
                if (cantidad > 0) {
                    caja->retirar(cantidad);
                } else {
                    cout << "Cantidad inválida. Intente nuevamente.\n";
                }
                break;
            }
            case 6: {
                // Retirar de la Cuenta Corriente
                double cantidad;
                cout << "Ingrese la cantidad a retirar de la Cuenta Corriente: ";
                cin >> cantidad;
                if (cantidad > 0) {
                    corriente.retirar(cantidad);
                } else {
                    cout << "Cantidad inválida. Intente nuevamente.\n";
                }
                break;
            }
            case 7: {
                // Salir
                cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
            }
        }
    } while (opcion != 7);

    return 0;
}