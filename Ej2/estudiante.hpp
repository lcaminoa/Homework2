#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Estudiante {
    private:
        string nombreCompleto;
        int legajo;
        vector<pair<string, float>> cursosConNotas; // Lista de cursos y sus notas
    
    public:

        /**
         * @brief Constructor que inicializa un estudiante con nombre y legajo.
         * 
         * @param nombre Nombre completo del estudiante.
         * @param legajo Número de legajo del estudiante.
         */
        Estudiante(string n, int l);
    
        // Métodos para obtener los datos

        /**
         * @brief Obtiene el nombre completo del estudiante.
         * 
         * @return std::string Nombre completo del estudiante.
         */
        string getFullName() const;

        /**
         * @brief Obtiene el número de legajo del estudiante.
         * 
         * @return int Número de legajo.
         */
        int getLegajo() const;

        /**
         * @brief Calcula el promedio general con las notas del estudiante.
         * 
         * @return float Promedio general.
         */
        float getPromedioGeneral() const;
    
        /**
         * @brief Agrega un curso y su nota al estudiante.
         * 
         * @param curso Nombre del curso.
         * @param nota Nota obtenida en el curso.
         */
        void agregarCurso(string curso, float nota);

        /**
         * @brief Sobrecarga del operador "<" para ordenar estudiantes alfabéticamente.
         * 
         * @param other Otro estudiante a comparar.
         * @return true Si el nombre del estudiante actual es menor que el del otro.
         * @return false En caso contrario.
         */
        bool operator<(const Estudiante& other) const;
    
        /**
         * @brief Sobrecarga del operador "<<" para imprimir los datos del estudiante.
         * 
         * @param os Flujo de salida.
         * @param estudiante Estudiante a imprimir.
         * @return std::ostream& Flujo de salida modificado.
         */
        friend ostream& operator<<(ostream& os, const Estudiante& estudiante);
    };

#endif // ESTUDIANTE_HPP