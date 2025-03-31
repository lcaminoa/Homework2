#ifndef CURSO_HPP
#define CURSO_HPP

#include <string>
#include <vector>
#include <memory> // Para smart pointers
#include "estudiante.hpp"

class Curso {
private:
    string nombreCurso; // Nombre del curso
    vector<shared_ptr<Estudiante>> estudiantes; // Lista de estudiantes del curso
    const int capacidadMaxima = 20; // Capacidad máxima del curso

    /**
     * @brief Función de comparación para ordenar estudiantes por order alfabético.
     * 
     * @param a Primer estudiante a comparar.
     * @param b Segundo estudiante a comparar.
     * @return true Si el nombre del estudiante `a` es menor que el de `b`.
     * @return false En caso contrario.
     */
    static bool compararEstudiantes(const shared_ptr<Estudiante>& a, const shared_ptr<Estudiante>& b);

public:
    /**
     * @brief Constructor que inicializa un curso con un nombre.
     * 
     * @param nombre Nombre del curso.
     */
    Curso(const string& nombre);


    // Métodos

    /**
     * @brief Obtiene el nombre del curso.
     * 
     * @return string Nombre del curso.
     */
    string getNombreCurso() const;

    /**
     * @brief Inscribe un estudiante en el curso.
     * 
     * @param estudiante Puntero al estudiante a inscribir.
     * @throws runtime_error Si el curso está lleno o el estudiante ya está inscrito.
     */
    void inscribirEstudiante(shared_ptr<Estudiante> estudiante);

    /**
     * @brief Desinscribe un estudiante del curso.
     * 
     * @param legajo Número de legajo del estudiante a desinscribir.
     * @throws runtime_error Si el estudiante no está inscrito.
     */
    void desinscribirEstudiante(int legajo);

    /**
     * @brief Verifica si un estudiante está inscrito en el curso.
     * 
     * @param legajo Número de legajo del estudiante.
     * @return true Si el estudiante está inscripto.
     * @return false Si el estudiante no está inscripto.
     */
    bool estaInscripto(int legajo) const;

    /**
     * @brief Verifica si el curso está lleno.
     * 
     * @return true Si el curso alcanzó su capacidad máxima.
     * @return false Si hay espacio disponible.
     */
    bool estaCompleto() const;

    /**
     * @brief Imprime la lista de estudiantes inscriptos en orden alfabético.
     */
    void imprimirEstudiantesOrdenados();

    /**
     * @brief Cambia el nombre del curso.
     * 
     * @param nuevoNombre Nuevo nombre del curso.
     */
    void setNombreCurso(const string& nuevoNombre);

    /**
     * @brief Obtiene la lista de estudiantes inscriptos en el curso.
     * 
     * @return const vector<shared_ptr<Estudiante>>& Referencia a la lista de estudiantes.
     */
    const vector<shared_ptr<Estudiante>>& getEstudiantes() const;

    /**
     * @brief Operador de asignación para copiar cursos.
     * 
     * @param other Curso a copiar.
     * @return Curso& Referencia al curso actual.
     */
    Curso& operator=(const Curso& other);

    /**
     * @brief Constructor de copia.
     * 
     * @param other Curso a copiar.
     */
    Curso(const Curso& other);
};

#endif // CURSO_HPP