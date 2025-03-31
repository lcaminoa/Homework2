#include "menu.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Lista de estudiantes registrados en total
extern vector<shared_ptr<Estudiante>> estudiantesRegistrados;

void mostrarEstudiantesRegistrados() {
    if (estudiantesRegistrados.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- Lista de Estudiantes Registrados ---\n";
    for (size_t i = 0; i < estudiantesRegistrados.size(); ++i) {
        // Mostrar el índice, nombre completo y legajo de cada estudiante
        cout << i + 1 << ". " << estudiantesRegistrados[i]->getFullName() << " (Legajo: " << estudiantesRegistrados[i]->getLegajo() << ")\n";
    }

    cout << estudiantesRegistrados.size() + 1 << ". Volver al menú principal\n";
    cout << "Seleccione un estudiante para ver sus detalles: ";
    int opcion;
    cin >> opcion;
    // Por si introducen cualquier cosa menos lo que se pide
    if (cin.fail()) {
        cin.clear(); // Limpia el estado de error
        cin.ignore(); // Descarta la entrada inválida
        cout << "Entrada inválida. Intente nuevamente.\n";
        return;
    }

    if (opcion >= 1 && opcion <= estudiantesRegistrados.size()) {
        // Mostrar detalles del estudiante seleccionado
        auto estudiante = estudiantesRegistrados[opcion - 1];
        cout << "\n--- Detalles del Estudiante ---\n";
        cout << *estudiante << endl;
    }
    else if (opcion == estudiantesRegistrados.size() + 1) {
        // Volver al menú principal
        return;
    }
    else {
        cout << "Opción inválida.\n";
    }
}

void crearNuevoEstudiante() {
    try {
        string nombre;
        int legajo;

        cout << "Ingrese el nombre completo del estudiante: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese el número de legajo del estudiante: ";
        cin >> legajo;

        // Verificar si ya existe un estudiante con el mismo legajo
        for (const auto& estudiante : estudiantesRegistrados) {
            if (estudiante->getLegajo() == legajo) {
                throw runtime_error("Ya existe un estudiante con este legajo.");
            }
        }

        // Crear un nuevo estudiante y agregarlo a la lista
        auto nuevoEstudiante = make_shared<Estudiante>(nombre, legajo);
        estudiantesRegistrados.push_back(nuevoEstudiante);

        cout << "Estudiante registrado exitosamente.\n";
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << '\n';
    }
}

int mostrarMenuCursos(const vector<shared_ptr<Curso>>& cursos) {
    cout << "\n--- Menú de Cursos ---\n";
    for (size_t i = 0; i < cursos.size(); ++i) {
        // Mostrar el índice y el nombre de cada curso
        cout << i + 1 << ". " << cursos[i]->getNombreCurso() << '\n';
    }
    cout << cursos.size() + 1 << ". Crear un curso nuevo desde cero\n";
    cout << cursos.size() + 2 << ". Crear un curso copiando otro curso\n";
    cout << cursos.size() + 3 << ". Salir\n";
    cout << "Seleccione una opción: ";
    int opcion;
    cin >> opcion;

    // Validar entrada del usuario
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Entrada inválida. Intente nuevamente.\n";
        return -1; // Devoler un valor inválido para indicar error
    }
    return opcion;
}

void manejarCurso(shared_ptr<Curso> curso) {
    int opcion;
    do {
        cout << "\n--- Menú del Curso ---\n";
        cout << curso->getNombreCurso() << '\n';
        cout << "1. Inscribir estudiante\n";
        cout << "2. Desinscribir estudiante\n";
        cout << "3. Verificar si un estudiante está inscripto\n";
        cout << "4. Imprimir lista de estudiantes en orden alfabético\n";
        cout << "5. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Entrada inválida. Intente nuevamente.\n";
            continue;
        }
        
        switch (opcion) {
            case 1: {
                // Inscribir un estudiante en el curso
                if (estudiantesRegistrados.empty()) {
                    cout << "No hay estudiantes registrados. Cree uno primero.\n";
                    break;
                }

                cout << "Lista de estudiantes para inscribir:\n";
                for (size_t i = 0; i < estudiantesRegistrados.size(); ++i) {
                    // Mostrar el índice, nombre completo y legajo de cada estudiante
                    cout << i + 1 << ". " << estudiantesRegistrados[i]->getFullName() << " (Legajo: " << estudiantesRegistrados[i]->getLegajo() << ")\n";
                }
                int opcionEstudiante;
                cout << "Seleccione un estudiante para inscribir: ";
                cin >> opcionEstudiante;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Entrada inválida. Intente nuevamente.\n";
                    break;
                }

                if (opcionEstudiante < 1 || opcionEstudiante > estudiantesRegistrados.size()) {
                    cout << "Opción inválida.\n";
                    break;
                }

                auto estudiante = estudiantesRegistrados[opcionEstudiante - 1];
                float nota;
                cout << "Ingrese la nota del estudiante: ";
                cin >> nota;

                // Validar entrada de la nota
                if (cin.fail() || nota < 0 || nota > 10) {
                    cin.clear();
                    cin.ignore();
                    cout << "Nota inválida. Debe estar entre 0 y 10.\n";
                    break;
                }

                // Inscribir al estudiante en el curso
                curso->inscribirEstudiante(estudiante);
                estudiante->agregarCurso(curso->getNombreCurso(), nota);
                cout << "Estudiante inscripto exitosamente.\n";
                break;
            }
            case 2: {
                // Desinscribir un estudiante del curso
                int legajo;
                cout << "Ingrese el legajo del estudiante a desinscribir: ";
                cin >> legajo;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Entrada inválida. Intente nuevamente.\n";
                    break;
                }
                curso->desinscribirEstudiante(legajo);
                break;
            }
            case 3: {
                // Verificar si un estudiante está inscripto en el curso
                int legajo;
                cout << "Ingrese el legajo del estudiante: ";
                cin >> legajo;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Entrada inválida. Intente nuevamente.\n";
                    break;
                }
                if (curso->estaInscripto(legajo)) {
                    cout << "El estudiante está inscripto en el curso.\n";
                }
                else {
                    cout << "El estudiante no está inscripto en el curso.\n";
                }
                break;
            }
            case 4: {
                // Imprimir la lista de estudiantes en orden alfabético
                curso->imprimirEstudiantesOrdenados();
                break;
            }
            case 5: {
                // Volver al menú principal
                cout << "Volviendo al menú principal...\n";
                break;
            }
            default: {
                cout << "Opción inválida.\n";
                break;
            }
        }
    } while (opcion != 5);
}

void manejarCursoExistente(const vector<shared_ptr<Curso>>& cursos) {
    int opcionCurso = mostrarMenuCursos(cursos);
    if (opcionCurso >= 1 && opcionCurso <= cursos.size()) {
        manejarCurso(cursos[opcionCurso - 1]);
    }
    else {
        throw runtime_error("Opción inválida.");
    }
}

void crearCursoNuevo(vector<shared_ptr<Curso>>& cursos) {
    string nombreCurso;
    cout << "Ingrese el nombre del nuevo curso: ";
    cin.ignore();
    getline(cin, nombreCurso);

    // Crear un nuevo curso y agregarlo a la lista
    auto nuevoCurso = make_shared<Curso>(nombreCurso);
    cursos.push_back(nuevoCurso);
    cout << "Curso creado exitosamente.\n";
}

void copiarCursoExistente(vector<shared_ptr<Curso>>& cursos) {
    if (cursos.empty()) {
        cout << "No hay cursos disponibles para copiar.\n";
        return;
    }

    cout << "Seleccione el curso que desea copiar:\n";
    for (size_t i = 0; i < cursos.size(); ++i) {
        // Mostrar el índice y el nombre de cada curso
        cout << i + 1 << ". " << cursos[i]->getNombreCurso() << '\n';
    }
    int cursoACopiar;
    cin >> cursoACopiar;

    // Validar entrada del usuario
    if (cursoACopiar < 1 || cursoACopiar > cursos.size()) {
        cout << "Opción inválida.\n";
        return;
    }

    string nuevoNombre;
    cout << "Ingrese el nombre del nuevo curso: ";
    cin.ignore();
    getline(cin, nuevoNombre);

    // Crear una copia del curso seleccionado
    auto cursoCopiado = make_shared<Curso>(*cursos[cursoACopiar - 1]);
    cursoCopiado->setNombreCurso(nuevoNombre);

    // Asignar nuevas notas a los estudiantes del curso copiado
    for (const auto& estudiante : cursos[cursoACopiar - 1]->getEstudiantes()) {
        float nuevaNota;
        cout << "Ingrese la nueva nota para el estudiante " << estudiante->getFullName() << " (Legajo: " << estudiante->getLegajo() << "): ";
        cin >> nuevaNota;

        // Validar entrada de la nota
        if (cin.fail() || nuevaNota < 0 || nuevaNota > 10) {
            cin.clear();
            cin.ignore();
            cout << "Nota inválida. Debe estar entre 0 y 10.\n";
            return;
        }

        estudiante->agregarCurso(nuevoNombre, nuevaNota);
        cursoCopiado->inscribirEstudiante(estudiante);
    }

    // Agregar el curso copiado a la lista de cursos
    cursos.push_back(cursoCopiado);
    cout << "Curso '" << nuevoNombre << "' creado exitosamente a partir de '" << cursos[cursoACopiar - 1]->getNombreCurso() << "'.\n";
}