#include "Ej4.hpp"
#include <iostream>

using namespace std;

// Constructor clase base CuentaBancaria
CuentaBancaria::CuentaBancaria(string nombreTitular, double saldoInicial) : titularCuenta(nombreTitular), balance(saldoInicial) {}

// Método para depositar dinero en la cuenta
void CuentaBancaria::depositar(double cantidad) {
    if (cantidad > 0) {
        balance += cantidad; // Incrementa el balance si la cantidad es válida
    }
    else {
        cout << "Error: Introduzca una cantidad válida."; // Mensaje de error si la cantidad es negativa o cero
    }
}

// Constructor de la clase CajaDeAhorro
CajaDeAhorro::CajaDeAhorro(string nombreTitular, double saldoInicial) : CuentaBancaria(nombreTitular, saldoInicial), contadorInfo(0) {}

// Método para retirar dinero de la caja de ahorro
void CajaDeAhorro::retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad; // Resta la cantidad del balance si hay fondos suficientes
    }
    else {
        cout << "Error: Fondos insuficientes para retirar."; // Mensaje de error si no hay fondos suficientes
    }
}

// Método para mostrar la información de la caja de ahorro
void CajaDeAhorro::mostrarInfo() {
    cout << "Titular: " << titularCuenta << endl;
    cout << "Tipo de cuenta: Caja de Ahorro" << endl;
    cout << "Balance actual: $" << balance << endl;

    contadorInfo++; // Incrementa el contador de consultas de información
    if (contadorInfo > 2) { // Si se consulta más de dos veces
        if (balance >= 20) {
            balance -= 20; // Descuenta $20 si hay fondos suficientes
            cout << "Se descontaron $20 por preguntar mucho." << endl;
            cout << "Balance actualizado: $" << balance << endl;
        } else {
            cout << "No se pudo aplicar el descuento de $20 debido a fondos insuficientes." << endl;
        }
    }
}

// Constructor de la clase CuentaCorriente
CuentaCorriente::CuentaCorriente(string nombreTitular, double saldoInicial, CajaDeAhorro* caja) : CuentaBancaria(nombreTitular, saldoInicial), cajaAhorro(caja) {}

// Método para retirar dinero de la cuenta corriente
void CuentaCorriente::retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad; // Resta la cantidad del balance si hay fondos suficientes
    }
    else {
        double falta = cantidad - balance; // Calcula cuánto falta para completar el retiro
        if (cajaAhorro->balance >= falta) {
            cout << "Saldo insuficiente en cuenta corriente. Retirando de caja de ahorro..." << endl;
            cajaAhorro->balance -= falta; // Resta la cantidad faltante de la caja de ahorro
            balance = 0; // Deja el balance de la cuenta corriente en cero
        }
        else {
            cout << "Dinero insuficiente para retirar." << endl; // Mensaje de error si no hay fondos suficientes en ambas cuentas
        }
    }
}

// Método para mostrar la información de la cuenta corriente
void CuentaCorriente::mostrarInfo() {
    cout << "Titular: " << titularCuenta << endl;
    cout << "Tipo de cuenta: Cuenta Corriente" << endl;
    cout << "Balance: $" << balance << endl;
}