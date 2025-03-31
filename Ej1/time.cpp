#include "time.hpp"

bool Time::validarHora(int horas, int minutos, int segundos, const string& periodo) {
    // Validar rango de horas
    if (horas < 0 || horas > 23) return false;

    // Validar rango de minutos
    if (minutos < 0 || minutos > 59) return false;

    // Validar rango de segundos
    if (segundos < 0 || segundos > 59) return false;

    // Validar período (ver que sea "a.m." o "p.m.")
    if (periodo != "a.m." && periodo != "p.m.") return false;

    return true; // Si todos los valores son válidos
}

Time::Time() {
    horas = 0;
    minutos = 0;
    segundos = 0;
    periodo = "a.m."; // Por default, el período es "a.m."
}

Time::Time(int h) {
    try {
        // Validar la hora con minutos, segundos y período default
        if (!validarHora(h, 0, 0, "a.m.")) {
            throw invalid_argument("Hora no válida");
        }
        horas = h;
        minutos = 0;
        segundos = 0;
        periodo = "a.m.";
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        throw;
    }
}

Time::Time(int h, int m) {
    try {
        // Validar la hora y los minutos, con segundos y período default
        if (!validarHora(h, m, 0, "a.m.")) {
            throw invalid_argument("Hora no válida");
        }
        horas = h;
        minutos = m;
        segundos = 0;
        periodo = "a.m.";
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        throw;
    }
}

Time::Time(int h, int m, int s) {
    try {
        // Validar la hora, los minutos y los segundos, con el período default
        if (!validarHora(h, m, s, "a.m.")) {
            throw invalid_argument("Hora no válida");
        }
        horas = h;
        minutos = m;
        segundos = s;
        periodo = "a.m.";
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        throw;
    }
}

Time::Time(int h, int m, int s, const string& p) {
    try {
        // Validar todos los valores
        if (!validarHora(h, m, s, p)) {
            throw invalid_argument("Hora no válida");
        }
        horas = h;
        minutos = m;
        segundos = s;
        periodo = p;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        throw;
    }
}

void Time::setHour(int h) {
    if (h < 0 || h > 12) throw invalid_argument("Hora inválida");
    horas = h;
}

void Time::setMinutes(int m) {
    if (m < 0 || m > 59) throw invalid_argument("Minutos inválidos");
    minutos = m;
}

void Time::setSeconds(int s) {
    if (s < 0 || s > 59) throw invalid_argument("Segundos inválidos");
    segundos = s;
}

void Time::setPeriod(const string& p) {
    if (p != "a.m." && p != "p.m.") throw invalid_argument("Período inválido");
    periodo = p;
}

int Time::getHoras() const {
    return horas;
}

int Time::getMinutos() const {
    return minutos;
}

int Time::getSegundos() const {
    return segundos;
}

string Time::getPeriodo() const {
    return periodo;
}

void Time::getFullTime() const {
    cout << setfill('0') << setw(2) << horas << "h, "
         << setw(2) << minutos << "m, "
         << setw(2) << segundos << "s "
         << periodo;
}

void Time::print24HourFormat() const {
    int hora24 = horas;

    // Ajustar la hora al formato 24hs
    if (periodo == "p.m." && horas != 12) {
        hora24 += 12; // Convertir a formato 24hs
    }
    else if (periodo == "a.m." && horas == 12) {
        hora24 = 0; // Medianoche es 00:00 en formato 24hs
    }

    // Imprimir la hora en formato 24hs
    cout << setfill('0') << setw(2) << hora24 << ":"
         << setw(2) << minutos << ":"
         << setw(2) << segundos << endl;
}