#include "Ej3.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    // Crear números de distintos tipos
    shared_ptr<Numero> entero1 = make_shared<Entero>(5);
    shared_ptr<Numero> entero2 = make_shared<Entero>(3);
    shared_ptr<Numero> real1 = make_shared<Real>(2.5);
    shared_ptr<Numero> real2 = make_shared<Real>(-1.5);
    shared_ptr<Numero> complejo1 = make_shared<Complejo>(1.0, 2.0);
    shared_ptr<Numero> complejo2 = make_shared<Complejo>(-3.0, 4.0);

    // Operaciones entre Entero y Entero
    cout << "Operaciones entre Entero y Entero:" << endl;
    auto resultado1 = *entero1 + *entero2; // Suma
    resultado1->toString();
    auto resultado2 = *entero1 - *entero2; // Resta
    resultado2->toString();
    auto resultado3 = *entero1 * *entero2; // Multiplicación
    resultado3->toString();
    auto resultado4 = *entero1 / *entero2; // División
    resultado4->toString();

    // Operaciones entre Entero y Real
    cout << "\nOperaciones entre Entero y Real:" << endl;
    auto resultado5 = *entero1 + *real1; // Suma
    resultado5->toString();
    auto resultado6 = *entero1 - *real1; // Resta
    resultado6->toString();
    auto resultado7 = *entero1 * *real1; // Multiplicación
    resultado7->toString();
    auto resultado8 = *entero1 / *real1; // División
    resultado8->toString();

    // Operaciones entre Entero y Complejo
    cout << "\nOperaciones entre Entero y Complejo:" << endl;
    auto resultado9 = *entero1 + *complejo1; // Suma
    resultado9->toString();
    auto resultado10 = *entero1 - *complejo1; // Resta
    resultado10->toString();
    auto resultado11 = *entero1 * *complejo1; // Multiplicación
    resultado11->toString();
    auto resultado12 = *entero1 / *complejo1; // División
    resultado12->toString();

    // Operaciones entre Real y Real
    cout << "\nOperaciones entre Real y Real:" << endl;
    auto resultado13 = *real1 + *real2; // Suma
    resultado13->toString();
    auto resultado14 = *real1 - *real2; // Resta
    resultado14->toString();
    auto resultado15 = *real1 * *real2; // Multiplicación
    resultado15->toString();
    auto resultado16 = *real1 / *real2; // División
    resultado16->toString();

    // Operaciones entre Real y Complejo
    cout << "\nOperaciones entre Real y Complejo:" << endl;
    auto resultado17 = *real1 + *complejo1; // Suma
    resultado17->toString();
    auto resultado18 = *real1 - *complejo1; // Resta
    resultado18->toString();
    auto resultado19 = *real1 * *complejo1; // Multiplicación
    resultado19->toString();
    auto resultado20 = *real1 / *complejo1; // División
    resultado20->toString();

    // Operaciones entre Complejo y Complejo
    cout << "\nOperaciones entre Complejo y Complejo:" << endl;
    auto resultado21 = *complejo1 + *complejo2; // Suma
    resultado21->toString();
    auto resultado22 = *complejo1 - *complejo2; // Resta
    resultado22->toString();
    auto resultado23 = *complejo1 * *complejo2; // Multiplicación
    resultado23->toString();
    auto resultado24 = *complejo1 / *complejo2; // División
    resultado24->toString();

    return 0;
}