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
    Entero(int e) : entero(e) {}

    shared_ptr<Numero> operator+(const Numero& other) const override;
    shared_ptr<Numero> operator-(const Numero& other) const override;
    shared_ptr<Numero> operator*(const Numero& other) const override;
    shared_ptr<Numero> operator/(const Numero& other) const override;
    void toString() const override;

    int getEntero() const;
};

class Real : public Numero{
private:
    const double real;
public:
    Real(double r) : real(r) {}

    shared_ptr<Numero> operator+(const Numero& other) const override;
    shared_ptr<Numero> operator-(const Numero& other) const override;
    shared_ptr<Numero> operator*(const Numero& other) const override;
    shared_ptr<Numero> operator/(const Numero& other) const override;
    void toString() const override;

    double getReal() const;
};

class Complejo : public Numero{
private:
    const double parteReal;
    const double parteImaginaria;
public:
    Complejo(double r, double i) : parteReal(r), parteImaginaria(i) {}

    shared_ptr<Numero> operator+(const Numero& other) const override;
    shared_ptr<Numero> operator-(const Numero& other) const override;
    shared_ptr<Numero> operator*(const Numero& other) const override;
    shared_ptr<Numero> operator/(const Numero& other) const override;
    void toString() const override;
    
    double getParteReal() const;
    double getParteImaginaria() const;
};

#endif // EJ3_HPP