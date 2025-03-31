#include "estudiante.hpp"

using namespace std;

Estudiante::Estudiante(string n, int l) {
    nombreCompleto = n;
    legajo = l;
}

string Estudiante::getFullName() const {
    return nombreCompleto;
}

int Estudiante::getLegajo() const {
    return legajo;
}

float Estudiante::getPromedioGeneral() const {
    if (cursosConNotas.empty()) return 0.0f; // Si no hay cursos, el promedio es 0
    float suma = 0.0f;
    for (const auto& cursoNota : cursosConNotas) {
        suma += cursoNota.second; // Sumar todas las notas
    }
    return suma / cursosConNotas.size(); // Dividir la suma entre la cantidad de cursos (promedio)
}

void Estudiante::agregarCurso(string curso, float nota) {
    cursosConNotas.push_back({curso, nota}); // Añadir el curso y la nota como un par
}

bool Estudiante::operator<(const Estudiante& other) const {
    return nombreCompleto < other.nombreCompleto;
}

ostream& operator<<(ostream& os, const Estudiante& estudiante) {
    os << "Nombre: " << estudiante.nombreCompleto << "\n";
    os << "Legajo: " << estudiante.legajo << "\n";
    os << "Promedio: " << estudiante.getPromedioGeneral();
    return os;
}