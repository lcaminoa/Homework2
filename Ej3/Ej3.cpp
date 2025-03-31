#include "Ej3.hpp"

using namespace std;


// Enteros

int Entero::getEntero() const {
    return this->entero; // El valor del entero.
}

shared_ptr<Numero> Entero::operator+(const Numero& other) const {
    // Intentamos convertir el otro número a Entero
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        int res = (this->entero + e->getEntero()); // Suma de dos enteros
        return make_shared<Entero>(res);
    }
    // Intentamos convertir el otro número a Real
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->entero + r->getReal()); // Suma de un entero y un real
        return make_shared<Real>(res);
    }
    // Intentamos convertir el otro número a Complejo
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = (this->entero + c->getParteReal()); // Suma de la parte real
        double resI = c->getParteImaginaria(); // La parte imaginaria queda igual
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr; // Si no es ninguno de los tipos anteriores, devuelve nullptr
}

shared_ptr<Numero> Entero::operator-(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        int res = (this->entero - e->getEntero()); // Resta de dos enteros
        return make_shared<Entero>(res);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->entero - r->getReal()); // Resta de un entero y un real
        return make_shared<Real>(res);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = (this->entero - c->getParteReal()); // Resta de la parte real
        double resI = -c->getParteImaginaria(); // Menos la parte imaginaria
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr;
}

shared_ptr<Numero> Entero::operator*(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        int res = (this->entero * e->getEntero()); // Multiplicación de dos enteros
        return make_shared<Entero>(res);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->entero * r->getReal()); // Multiplicación de un entero y un real
        return make_shared<Real>(res);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = (this->entero * c->getParteReal()); // Multiplicación de la parte real
        double resI = (this->entero * c->getParteImaginaria()); // Multiplicación de la parte imaginaria
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr;
}

shared_ptr<Numero> Entero::operator/(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        if (e->getEntero() != 0) { // Verificamos que no haya división por cero
            double res = static_cast<double>(this->entero) / e->getEntero();
            return make_shared<Real>(res); // El resultado puede ser un número real
        } else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        if (r->getReal() != 0) {
            double res = (this->entero / r->getReal());
            return make_shared<Real>(res);
        }
        else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double denom = c->getParteReal() * c->getParteReal() + c->getParteImaginaria() * c->getParteImaginaria();
        if (denom != 0) { // Verificamos que el denominador no sea cero
            double resR = (this->entero * c->getParteReal()) / denom; // División de la parte real
            double resI = (-this->entero * c->getParteImaginaria()) / denom; // División de la parte imaginaria
            return make_shared<Complejo>(resR, resI);
        } else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    return nullptr;
}

void Entero::toString() const {
    cout << "Entero: " << entero << endl; // Imprime el valor del entero
}


// Reales

double Real::getReal() const {
    return this->real; // Devuelve el valor del número real
}

shared_ptr<Numero> Real::operator+(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        double res = (this->real + e->getEntero()); // Suma de un real y un entero
        return make_shared<Real>(res);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->real + r->getReal()); // Suma de dos reales
        return make_shared<Real>(res);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double res = (this->real + c->getParteReal()); // Suma de la parte real
        return make_shared<Complejo>(res, c->getParteImaginaria()); // La parte imaginaria queda igual
    }
    return nullptr;
}

shared_ptr<Numero> Real::operator-(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        double res = (this->real - e->getEntero());
        return make_shared<Real>(res);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->real - r->getReal());
        return make_shared<Real>(res);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = this->real - c->getParteReal();
        double resI = -c->getParteImaginaria();
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr;
}

shared_ptr<Numero> Real::operator*(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        double res = (this->real * e->getEntero());
        return make_shared<Real>(res);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->real * r->getReal());
        return make_shared<Real>(res);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = (this->real * c->getParteReal());
        double resI = (this->real * c->getParteImaginaria());
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr;
}

shared_ptr<Numero> Real::operator/(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        if (e->getEntero() != 0) {
            double res = (this->real / e->getEntero());
            return make_shared<Real>(res);
        } else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        if (r->getReal() != 0) {
            double res = (this->real / r->getReal());
            return make_shared<Real>(res);
        } else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double realParte = c->getParteReal();
        double imagParte = c->getParteImaginaria();
        
        // Verificar que el complejo no sea cero
        if (realParte != 0 || imagParte != 0) {
            // Multiplicamos el numerador y el denominador por el conjugado del complejo
            double denominador = realParte * realParte + imagParte * imagParte;
            double numReal = this->real * realParte;
            double numImaginario = -this->real * imagParte;

            // Dividir por el denominador
            double resReal = numReal / denominador;
            double resImaginario = numImaginario / denominador;

            return make_shared<Complejo>(resReal, resImaginario);
        } else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    return nullptr;
}

void Real::toString() const {
    cout << "Real: " << real << endl;
}


// Complejos

double Complejo::getParteReal() const {
    return this->parteReal;
}

double Complejo::getParteImaginaria() const {
    return this->parteImaginaria;
}

shared_ptr<Numero> Complejo::operator+(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        double res = (this->parteReal + e->getEntero());
        return make_shared<Complejo>(res, this->parteImaginaria);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->parteReal + r->getReal());
        return make_shared<Complejo>(res, this->parteImaginaria);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = (this->parteReal + c->getParteReal());
        double resI = (this->parteImaginaria + c->getParteImaginaria());
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr;
}

shared_ptr<Numero> Complejo::operator-(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        double res = (this->parteReal - e->getEntero());
        return make_shared<Complejo>(res, this->parteImaginaria);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double res = (this->parteReal - r->getReal());
        return make_shared<Complejo>(res, this->parteImaginaria);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = (this->parteReal - c->getParteReal());
        double resI = (this->parteImaginaria - c->getParteImaginaria());
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr;
}

shared_ptr<Numero> Complejo::operator*(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        double resR = (this->parteReal * e->getEntero());
        double resI = (this->parteImaginaria * e->getEntero());
        return make_shared<Complejo>(resR, resI);
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        double resR = (this->parteReal * r->getReal());
        double resI = (this->parteImaginaria * r->getReal());
        return make_shared<Complejo>(resR, resI);
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        double resR = (this->parteReal * c->getParteReal() - this->parteImaginaria * c->getParteImaginaria()); 
        double resI = (this->parteReal * c->getParteImaginaria() + this->parteImaginaria * c->getParteReal()); 
        return make_shared<Complejo>(resR, resI);
    }
    return nullptr;
}

shared_ptr<Numero> Complejo::operator/(const Numero& other) const {
    const Entero* e = dynamic_cast<const Entero*>(&other);
    if (e) {
        if (e->getEntero() != 0) {
            double resR = (this->parteReal / e->getEntero());
            double resI = (this->parteImaginaria / e->getEntero());
            return make_shared<Complejo>(resR, resI);
        }
        else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    const Real* r = dynamic_cast<const Real*>(&other);
    if (r) {
        if (r->getReal() != 0) {
            double resR = (this->parteReal / r->getReal());
            double resI = (this->parteImaginaria / r->getReal());
            return make_shared<Complejo>(resR, resI);
        }
        else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    const Complejo* c = dynamic_cast<const Complejo*>(&other);
    if (c) {
        if (c->getParteReal() != 0 || c->getParteImaginaria() != 0) {
            double denom = c->getParteReal() * c->getParteReal() + c->getParteImaginaria() * c->getParteImaginaria();
            double resR = (this->parteReal * c->getParteReal() + this->parteImaginaria * c->getParteImaginaria()) / denom; 
            double resI = (this->parteImaginaria * c->getParteReal() - this->parteReal * c->getParteImaginaria()) / denom; 
            return make_shared<Complejo>(resR, resI);
        } else {
            cout << "Error: División por cero." << endl;
            return nullptr;
        }
    }
    return nullptr;
}

void Complejo::toString() const {
    cout << "Complejo: " << parteReal << " + " << parteImaginaria << "i" << endl;
}