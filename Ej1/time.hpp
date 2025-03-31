#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

class Time {
    private:
        int horas;
        int minutos;
        int segundos;
        string periodo; // a.m. o p.m.

        /**
         * @brief Verifica que los valores de hora, minutos, segundos y período sean correctos.
         * 
         * @param horas Hora a validar (0-23).
         * @param minutos Minutos a validar (0-59).
         * @param segundos Segundos a validar (0-59).
         * @param periodo Período a validar ("a.m." o "p.m.").
         * @return true Si los valores son válidos.
         * @return false Si los valores son inválidos.
         */
        bool validarHora(int horas, int minutos, int segundos, const string& periodo);

    public:
        // Constructores

        /**
         * @brief Constructor default. Inicializa la hora a 00:00:00 a.m.
         */
        Time();

        /**
         * @brief Constructor que inicializa solo con hora.
         * 
         * @param h Hora (0-23).
         */
        Time(int h);

        /**
         * @brief Constructor que inicializa con hora y minutos.
         * 
         * @param h Hora (0-23).
         * @param m Minutos (0-59).
         */
        Time(int h, int m);

        /**
         * @brief Constructor que inicializa con hora, minutos y segundos.
         * 
         * @param h Hora (0-23).
         * @param m Minutos (0-59).
         * @param s Segundos (0-59).
         */
        Time(int h, int m, int s);

        /**
         * @brief Constructor que inicializa con hora, minutos, segundos y período.
         * 
         * @param h Hora (0-23).
         * @param m Minutos (0-59).
         * @param s Segundos (0-59).
         * @param p Período ("a.m." o "p.m.").
         */
        Time(int h, int m, int s, const string& p);


        // Métodos para cambiar valores

        /**
         * @brief Cambia la hora.
         * 
         * @param h Nueva hora (0-12).
         * @throws invalid_argument Si la hora no está en el rango válido.
         */
        void setHour(int h);

        /**
         * @brief Cambia los minutos.
         * 
         * @param m Nuevos minutos (0-59).
         * @throws invalid_argument Si los minutos no están en el rango válido.
         */
        void setMinutes(int m);

        /**
         * @brief Cambia los segundos.
         * 
         * @param s Nuevos segundos (0-59).
         * @throws invalid_argument Si los segundos no están en el rango válido.
         */
        void setSeconds(int s);

        /**
         * @brief Cambia el período (a.m. o p.m.).
         * 
         * @param p Nuevo período ("a.m." o "p.m.").
         * @throws invalid_argument Si el período no es válido.
         */
        void setPeriod(const string& p);


        // Métodos para obtener valores

        /**
         * @brief Obtiene la hora actual.
         * 
         * @return int Hora actual.
         */
        int getHoras() const;

        /**
         * @brief Obtiene los minutos actuales.
         * 
         * @return int Minutos actuales.
         */
        int getMinutos() const;

        /**
         * @brief Obtiene los segundos actuales.
         * 
         * @return int Segundos actuales.
         */
        int getSegundos() const;

        /**
         * @brief Obtiene el período actual (a.m. o p.m.).
         * 
         * @return string Período actual.
         */
        string getPeriodo() const;


        // Métodos para mostrar la hora

        /**
         * @brief Muestra la hora completa en formato 12 horas.
         */
        void getFullTime() const;

        /**
         * @brief Muestra la hora completa en formato 24 horas.
         */
        void print24HourFormat() const;
};

#endif // TIME_H