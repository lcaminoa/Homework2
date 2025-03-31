#include <iostream>
#include "time.hpp"

using namespace std;

int main() {
    Time tiempo; // Inicia sin parámetros (1.a)
    int opcion;

    do {
        cout << "\n--- Menú de opciones ---\n";
        cout << "1. Mostrar hora actual (formato 12 horas)\n";
        cout << "2. Mostrar hora actual (formato 24 horas)\n";
        cout << "3. Mostrar solo la hora actual\n";
        cout << "4. Mostrar solo los minutos actuales\n";
        cout << "5. Mostrar solo los segundos actuales\n";
        cout << "6. Mostrar solo el período actual\n";
        cout << "7. Cambiar hora\n";
        cout << "8. Cambiar minutos\n";
        cout << "9. Cambiar segundos\n";
        cout << "10. Cambiar período (a.m./p.m.)\n";
        cout << "11. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Opción inválida, vuelva a introducir." << endl;
            continue;
        }

        switch (opcion) {
            case 1: {
                // Mostrar hora en formato 12 horas
                cout << "Hora en formato 12 horas: ";
                tiempo.getFullTime();
                break;
            }
            case 2: {
                // Mostrar hora en formato 24 horas
                cout << "Hora en formato 24 horas: ";
                tiempo.print24HourFormat();
                break;
            }
            case 3: {
                // Mostrar solo la hora
                cout << "Hora actual: " << tiempo.getHoras() << endl;
                break;
            }
            case 4: {
                // Mostrar solo los minutos
                cout << "Minutos actuales: " << tiempo.getMinutos() << endl;
                break;
            }
            case 5: {
                // Mostrar solo los segundos
                cout << "Segundos actuales: " << tiempo.getSegundos() << endl;
                break;
            }
            case 6: {
                // Mostrar solo el período
                cout << "Período actual: " << tiempo.getPeriodo() << endl;
                break;
            }
            case 7: {
                // Cambiar hora
                int nuevaHora;
                cout << "Ingrese la nueva hora (0-12): ";
                cin >> nuevaHora;
                try {
                    tiempo.setHour(nuevaHora);
                    cout << "Hora actualizada correctamente.\n";
                }
                catch (const invalid_argument& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 8: {
                // Cambiar minutos
                int nuevosMinutos;
                cout << "Ingrese los nuevos minutos (0-59): ";
                cin >> nuevosMinutos;
                try {
                    tiempo.setMinutes(nuevosMinutos);
                    cout << "Minutos actualizados correctamente.\n";
                }
                catch (const invalid_argument& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 9: {
                // Cambiar segundos
                int nuevosSegundos;
                cout << "Ingrese los nuevos segundos (0-59): ";
                cin >> nuevosSegundos;
                try {
                    tiempo.setSeconds(nuevosSegundos);
                    cout << "Segundos actualizados correctamente.\n";
                }
                catch (const invalid_argument& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 10: {
                // Cambiar período
                string nuevoPeriodo;
                cout << "Ingrese el nuevo período (a.m./p.m.): ";
                cin >> nuevoPeriodo;
                try {
                    tiempo.setPeriod(nuevoPeriodo);
                    cout << "Período actualizado correctamente.\n";
                }
                catch (const invalid_argument& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 11: {
                // Salir
                cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
            }
        }
    } while (opcion != 11);


    // Pruebas constructores
    cout << "\n--- Pruebas de constructores ---\n";

    // Constructor con solo hora
    try {
        Time tiempoHora(10);
        cout << "Constructor con solo hora: ";
        tiempoHora.getFullTime();
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Constructor con hora y minutos
    try {
        Time tiempoHoraMinutos(10, 30);
        cout << "\nConstructor con hora y minutos: ";
        tiempoHoraMinutos.getFullTime();
    }
    catch (const invalid_argument& e) {
        cerr << "\nError: " << e.what() << endl;
    }

    // Constructor con hora, minutos y segundos
    try {
        Time tiempoHoraMinutosSegundos(10, 30, 45);
        cout << "\nConstructor con hora, minutos y segundos: ";
        tiempoHoraMinutosSegundos.getFullTime();
    }
    catch (const invalid_argument& e) {
        cerr << "\nError: " << e.what() << endl;
    }

    // Constructor con hora, minutos, segundos y período
    try {
        Time tiempoCompleto(10, 30, 45, "p.m.");
        cout << "\nConstructor con hora, minutos, segundos y período: ";
        tiempoCompleto.getFullTime();
    }
    catch (const invalid_argument& e) {
        cerr << "\nError: " << e.what() << endl;
    }

    return 0;
}