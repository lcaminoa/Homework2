#include "curso.hpp"
#include <algorithm> // Para la operadores y sort
#include <iostream>

using namespace std;

Curso::Curso(const string& nombre) {
    nombreCurso = nombre;
    estudiantes = {}; // Inicializar la lista de estudiantes vacía
}

bool Curso::compararEstudiantes(const shared_ptr<Estudiante>& a, const shared_ptr<Estudiante>& b) {
    return a->getFullName() < b->getFullName(); // Comparar nombres alfabéticamente
}

string Curso::getNombreCurso() const {
    return nombreCurso;
}

void Curso::inscribirEstudiante(shared_ptr<Estudiante> estudiante) {
    try {
        // Verificar si el curso está lleno
        if (estaCompleto()) {
            throw runtime_error("El curso está lleno. No se puede inscribir.");
        }
        // Verificar si el estudiante ya está inscripto
        if (estaInscripto(estudiante->getLegajo())) {
            throw runtime_error("El estudiante ya está inscripto.");
        }
        // Agregar el estudiante a la lista
        estudiantes.push_back(estudiante);
        cout << "Estudiante inscripto exitosamente.\n";
    }
    catch (const runtime_error& e) {
        // Manejar errores de inscripción
        cerr << "Error: " << e.what() << '\n';
    }
}

void Curso::desinscribirEstudiante(int legajo) {
    try {
        // Buscar al estudiante por su legajo
        for (auto iter = estudiantes.begin(); iter != estudiantes.end(); ++iter) {
            if ((*iter)->getLegajo() == legajo) {
                // Eliminar al estudiante de la lista
                estudiantes.erase(iter);
                cout << "Estudiante desinscripto correctamente.\n";
                return;
            }
        }
        // Lanzar un error si el estudiante no está inscripto
        throw runtime_error("El estudiante no está inscripto.");
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << '\n';
    }
}

bool Curso::estaInscripto(int legajo) const {
    for (const auto& estudiante : estudiantes) {
        if (estudiante->getLegajo() == legajo) {
            return true; // El estudiante está inscripto
        }
    }
    return false; // El estudiante no está inscripto
}

bool Curso::estaCompleto() const {
    return estudiantes.size() >= capacidadMaxima; // Comparar el tamaño actual con la capacidad máxima
}

void Curso::imprimirEstudiantesOrdenados() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes inscriptos en el curso.\n";
        return;
    }

    // Ordenar la lista de estudiantes usando la función de comparación
    sort(estudiantes.begin(), estudiantes.end(), compararEstudiantes);

    // Imprimir la lista de estudiantes
    cout << "Lista de estudiantes en orden alfabético:\n";
    cout << "------------------------\n";
    for (const auto& estudiante : estudiantes) {
        cout << *estudiante << endl; // Usar la sobrecarga del operador << para imprimir los datos del estudiante
        cout << "------------------------\n";
    }
}

void Curso::setNombreCurso(const string& nuevoNombre) {
    nombreCurso = nuevoNombre;
}

const vector<shared_ptr<Estudiante>>& Curso::getEstudiantes() const {
    return estudiantes;
}

Curso& Curso::operator=(const Curso& other) {
    if (this == &other) {
        // Verificar autoasignación
        return *this;
    }

    // Copiar los punteros compartidos del otro curso
    estudiantes = other.estudiantes;

    // La capacidad máxima no la copia porque es constante
    return *this;
}

Curso::Curso(const Curso& other) {
    // Shallow Copy: se copian los punteros compartidos, pero no se duplican los objetos.
    estudiantes = other.estudiantes;
}
/*
EXPLICACIÓN
Se hace una Shallow Copy del Curso.
- Se copian los shared pointers en el vector estudiantes, lo que incrementa el
  use_count() de cada shared pointer.
- Los objetos apuntados por los shared pointers no se duplican, por lo que los
  cursos comparten los mismos estudiantes. Esto es más eficiente en cuanto a la
  memoria y permite que los cambios hechos en un estudiante se reflejen en todos
  los cursos a los que pertenece.
- La capacidad máxima no necesita copiarse, ya que es una constante.
- Como utilizamos Shallow Copy, cualquier modificación a un estudiante a través
  de un curso afectará a todos los cursos que tienen a ese estudiante.
*/