#ifndef TP4_H
#define TP4_H

#include <string>

using namespace std;

class CuentaBancaria {
protected:

    string titularCuenta;
    double balance;

    /**
     * @brief Constructor para inicializar una cuenta bancaria.
     * 
     * @param nombreTitular Nombre del titular de la cuenta.
     * @param saldoInicial Balance inicial de la cuenta.
     */
    CuentaBancaria(string nombreTitular, double saldoInicial);

public:

    /**
     * @brief Deposita una cantidad en la cuenta.
     * 
     * @param cantidad Cantidad a depositar.
     */
    void depositar(double cantidad);

    /**
     * @brief Retira una cantidad de la cuenta.
     * 
     * @param cantidad Cantidad a retirar.
     */
    virtual void retirar(double cantidad) = 0;

    /**
     * @brief Muestra la información de la cuenta.
     */
    virtual void mostrarInfo() = 0;
};


class CajaDeAhorro : public CuentaBancaria {
private:
    int contadorInfo;

public:

    /**
     * @brief Constructor para inicializar una caja de ahorro.
     * 
     * @param nombreTitular Nombre del titular de la cuenta.
     * @param saldoInicial Balance inicial de la cuenta.
     */
    CajaDeAhorro(string nombreTitular, double saldoInicial);

    /**
     * @brief Retira una cantidad de la caja de ahorro.
     * 
     * @param cantidad Cantidad a retirar.
     */
    void retirar(double cantidad) override;

    /**
     * @brief Muestra la información de la caja de ahorro.
     */
    void mostrarInfo() override;

    friend class CuentaCorriente; // Para permitir acceso a Cuenta Corriente
};


class CuentaCorriente : public CuentaBancaria {
private:
    CajaDeAhorro* cajaAhorro;
public:

    /**
     * @brief Constructor para inicializar una cuenta corriente.
     * 
     * @param nombreTitular Nombre del titular de la cuenta.
     * @param saldoInicial Balance inicial de la cuenta.
     * @param cajaAhorro Puntero a la caja de ahorro asociada.
     */
    CuentaCorriente(string nombreTitular, double saldoInicial, CajaDeAhorro* cajaAhorro);

    /**
     * @brief Retira una cantidad de la cuenta corriente.
     * 
     * @param cantidad Cantidad a retirar.
     */
    void retirar(double cantidad) override;

    /**
     * @brief Muestra la información de la cuenta corriente.
     */
    void mostrarInfo() override;
};

#endif // TP4_H