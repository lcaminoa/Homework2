#ifndef EJ3_HPP
#define EJ3_HPP

#include <memory>
#include <iostream>
#include <string>

using namespace std;

class Numero{
public:
    virtual shared_ptr<Numero> operator+(const Numero& other) const = 0;
    virtual shared_ptr<Numero> operator-(const Numero& other) const = 0;
    virtual shared_ptr<Numero> operator*(const Numero& other) const = 0;
    virtual shared_ptr<Numero> operator/(const Numero& other) const = 0;
    virtual void toString() const = 0;

};

class Entero : public Numero{
private:
    const int entero;
public:

    /**
     * @brief Constructor para inicializar un número entero.
     * 
     * @param e Valor del número entero.
     */
    Entero(int e) : entero(e) {}

    shared_ptr<Numero> operator+(const Numero& other) const override;
    shared_ptr<Numero> operator-(const Numero& other) const override;
    shared_ptr<Numero> operator*(const Numero& other) const override;
    shared_ptr<Numero> operator/(const Numero& other) const override;
    void toString() const override;

    /**
     * @brief Obtiene el valor del número entero.
     * 
     * @return int Valor del número entero.
     */
    int getEntero() const;
};

class Real : public Numero{
private:
    const double real;
public:

    /**
     * @brief Constructor para inicializar un número real.
     * 
     * @param r Valor del número real.
     */
    Real(double r) : real(r) {}

    shared_ptr<Numero> operator+(const Numero& other) const override;
    shared_ptr<Numero> operator-(const Numero& other) const override;
    shared_ptr<Numero> operator*(const Numero& other) const override;
    shared_ptr<Numero> operator/(const Numero& other) const override;
    void toString() const override;

    /**
     * @brief Obtiene el valor del número real.
     * 
     * @return double Valor del número real.
     */
    double getReal() const;
};

class Complejo : public Numero{
private:
    const double parteReal;
    const double parteImaginaria;
public:

    /**
     * @brief Constructor para inicializar un número complejo.
     * 
     * @param r Parte real del número complejo.
     * @param i Parte imaginaria del número complejo.
     */
    Complejo(double r, double i) : parteReal(r), parteImaginaria(i) {}

    shared_ptr<Numero> operator+(const Numero& other) const override;
    shared_ptr<Numero> operator-(const Numero& other) const override;
    shared_ptr<Numero> operator*(const Numero& other) const override;
    shared_ptr<Numero> operator/(const Numero& other) const override;
    void toString() const override;
    
    /**
     * @brief Obtiene la parte real del número complejo.
     * 
     * @return double Parte real del número complejo.
     */
    double getParteReal() const;

    /**
     * @brief Obtiene la parte imaginaria del número complejo.
     * 
     * @return double Parte imaginaria del número complejo.
     */
    double getParteImaginaria() const;
};

#endif // EJ3_HPP