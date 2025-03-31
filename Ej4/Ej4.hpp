#ifndef TP4_H
#define TP4_H

#include <string>

using namespace std;

class CuentaBancaria {
protected:

    string titularCuenta;
    double balance;

    CuentaBancaria(string nombreTitular, double saldoInicial);

public:

    void depositar(double cantidad);
    virtual void retirar(double cantidad) = 0;
    virtual void mostrarInfo() = 0;
};


class CajaDeAhorro : public CuentaBancaria {
private:
    int contadorInfo;

public:
    CajaDeAhorro(string nombreTitular, double saldoInicial);
    void retirar(double cantidad) override;
    void mostrarInfo() override;

    friend class CuentaCorriente; // Para permitir acceso a Cuenta Corriente
};


class CuentaCorriente : public CuentaBancaria {
private:
    CajaDeAhorro* cajaAhorro;
public:
    CuentaCorriente(string nombreTitular, double saldoInicial, CajaDeAhorro* cajaAhorro);

    void retirar(double cantidad) override;
    void mostrarInfo() override;
};

#endif // TP4_H