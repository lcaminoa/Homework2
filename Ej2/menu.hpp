#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <memory> // Para smart pointers
#include "curso.hpp"

/**
 * @brief Muestra todos los estudiantes registrados.
 */
void mostrarEstudiantesRegistrados();

/**
 * @brief Crea un nuevo estudiante y lo agrega a la lista de estudiantes registrados.
 */
void crearNuevoEstudiante();

/**
 * @brief Muestra el menú de cursos y devuelve la opción seleccionada.
 * 
 * @param cursos Vector de cursos disponibles.
 * @return int Opción seleccionada por el usuario.
 */
int mostrarMenuCursos(const std::vector<std::shared_ptr<Curso>>& cursos);

/**
 * @brief Maneja las opciones de un curso seleccionado.
 * 
 * @param curso Curso seleccionado.
 */
void manejarCurso(std::shared_ptr<Curso> curso);

/**
 * @brief Maneja la selección de un curso existente.
 * 
 * @param cursos Vector de cursos disponibles.
 */
void manejarCursoExistente(const std::vector<std::shared_ptr<Curso>>& cursos);

/**
 * @brief Crea un nuevo curso y lo agrega a la lista de cursos.
 * 
 * @param cursos Vector de cursos disponibles.
 */
void crearCursoNuevo(std::vector<std::shared_ptr<Curso>>& cursos);

/**
 * @brief Copia un curso existente y permite asignar nuevas notas a los estudiantes.
 * 
 * @param cursos Vector de cursos disponibles.
 */
void copiarCursoExistente(std::vector<std::shared_ptr<Curso>>& cursos);

#endif // MENU_HPP