#include <iostream>
#include <vector>
#include <memory> // Para smart pointers
#include "estudiante.hpp"
#include "curso.hpp"
#include "menu.hpp"

using namespace std;

// Lista de todos los estudiantes registrados
vector<shared_ptr<Estudiante>> estudiantesRegistrados;

int main() {
    // Vector para almacenar los cursos disponibles
    vector<shared_ptr<Curso>> cursos;

    int opcion; // Para guardar la opción seleccionada por el usuario
    do {
        try {
            // Mostrar el menú principal
            cout << "\n--- Menú Principal ---\n";
            cout << "1. Ver todos los estudiantes registrados\n";
            cout << "2. Crear un nuevo estudiante\n";
            cout << "3. Administrar cursos\n";
            cout << "4. Salir\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;

            // Validar entrada del usuario
            if (cin.fail()) {
                cin.clear(); // Limpia el estado de error de `cin`
                cin.ignore(); // Descarta la entrada inválida
                throw runtime_error("Entrada no válida. Por favor, ingrese un número.");
            }

            // Procesar la opción seleccionada
            switch (opcion) {
                case 1:
                    // Mostrar todos los estudiantes registrados
                    mostrarEstudiantesRegistrados();
                    break;

                case 2:
                    // Crear un nuevo estudiante
                    crearNuevoEstudiante();
                    break;

                case 3: {
                    // Administrar cursos
                    try {
                        // Mostrar el menú de cursos y obtener la opción seleccionada
                        int opcionCurso = mostrarMenuCursos(cursos);

                        // Procesar la opción seleccionada en el menú de cursos
                        if (opcionCurso >= 1 && opcionCurso <= cursos.size()) {
                            // Manejar un curso existente
                            manejarCursoExistente(cursos);
                        } else if (opcionCurso == cursos.size() + 1) {
                            // Crear un curso nuevo
                            crearCursoNuevo(cursos);
                        } else if (opcionCurso == cursos.size() + 2) {
                            // Copiar un curso existente
                            copiarCursoExistente(cursos);
                        } else if (opcionCurso == cursos.size() + 3) {
                            // Salir del menú de cursos
                            break;
                        } else {
                            // Opción inválida
                            throw runtime_error("Opción inválida.");
                        }
                    } catch (const runtime_error& e) {
                        // Manejar errores específicos del menú de cursos
                        cerr << "Error: " << e.what() << '\n';
                    }
                    break;
                }

                case 4:
                    // Salir del programa
                    cout << "Saliendo del programa...\n";
                    break;

                default:
                    // Manejar opciones inválidas en el menú principal
                    throw runtime_error("Opción inválida.");
            }
        }
        catch (const runtime_error& e) {
            // Manejar errores generales en el menú principal
            cerr << "Error: " << e.what() << '\n';
        }
    } while (opcion != 4); // Repetir el menú principal hasta que el usuario elija salir

    return 0;
}