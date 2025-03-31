#include "Ej4.hpp"
#include <iostream>

using namespace std;

CuentaBancaria::CuentaBancaria(string nombreTitular, double saldoInicial) : titularCuenta(nombreTitular), balance(saldoInicial) {}

void CuentaBancaria::depositar(double cantidad) {
    if (cantidad > 0) {
        balance += cantidad;
    }
    else {
        cout << "Error: Introduzca una cantidad válida.";
    }
}

CajaDeAhorro::CajaDeAhorro(string nombreTitular, double saldoInicial) : CuentaBancaria(nombreTitular, saldoInicial), contadorInfo(0) {}

void CajaDeAhorro::retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad;
    }
    else {
        cout << "Error: Fondos insuficientes para retirar.";
    }
}

void CajaDeAhorro::mostrarInfo() {
    cout << "Titular: " << titularCuenta << endl;
    cout << "Tipo de cuenta: Caja de Ahorro" << endl;
    cout << "Balance actual: $" << balance << endl;

    contadorInfo ++;
    if (contadorInfo > 2) {
        if (balance >= 20) {
            balance -= 20;
            cout << "Se descontaron $20 por preguntar mucho." << endl;
            cout << "Balance actualizado: $" << balance << endl;
        } else {
            cout << "No se pudo aplicar el descuento de $20 debido a fondos insuficientes." << endl;
        }
    }
}

CuentaCorriente::CuentaCorriente(string nombreTitular, double saldoInicial, CajaDeAhorro* caja) : CuentaBancaria(nombreTitular, saldoInicial), cajaAhorro(caja) {}

void CuentaCorriente::retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad;
    }
    else {
        double falta = cantidad - balance; // Lo que le falta para poder retirar
        if (cajaAhorro->balance >= falta) {
            cout << "Saldo insuficiente en cuenta corriente. Retirando de caja de ahorro..." << endl;
            cajaAhorro->balance -= falta;
            balance = 0;
        }
        else {
            cout << "Dinero insuficiente para retirar." << endl;
        }
    }
}

void CuentaCorriente::mostrarInfo() {
    cout << "Titular: " << titularCuenta << endl;
    cout << "Tipo de cuenta: Cuenta Corriente" << endl;
    cout << "Balance: $" << balance << endl;
}