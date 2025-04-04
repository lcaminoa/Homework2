# Homework 1  
## Lautaro Valentín Caminoa  

Este homework contiene cuatro ejercicios implementados en C++. A continuación, se detalla cómo compilar y ejecutar cada uno de ellos.

---

### Ejercicio 1  
**Descripción:**  
Este ejercicio implementa una clase `Time` que permite trabajar con horas en formato de 12 horas (`a.m.`/`p.m.`) y 24 horas. La clase incluye métodos para establecer y obtener la hora, minutos, segundos y período (`a.m.`/`p.m.`), así como para mostrar la hora en ambos formatos. También se valida que los valores ingresados sean correctos, lanzando excepciones en caso de errores.

**Archivos:**  
- `main.cpp`  
- `time.cpp`  
- `time.h`  

**Cómo compilar:**  
```
g++ -o Ej1 time.cpp main.cpp
```
Esto genera un ejecutable llamado `Ej1`

**Cómo ejecutar:**
```
./Ej1
```

---

### Ejercicio 2
**Descripción:**  
Este ejercicio implementa un sistema de gestión de cursos y estudiantes. Incluye las clases `Estudiante` y `Curso`, que permiten registrar estudiantes, inscribirlos en cursos, asignarles notas y calcular promedios. También se incluye un menú interactivo que permite al usuario realizar acciones como:
- Ver la lista de estudiantes registrados.
- Crear nuevos estudiantes.
- Administrar cursos (crear, copiar, inscribir/desinscribir estudiantes, imprimir listas ordenadas alfabéticamente, etc.).

El programa utiliza `shared_ptr` para manejar punteros de manera segura y eficiente, evitando leaks de memoria.

**Relación entre clases Estudiante y Curso**  
La relación entre Curso y Estudiante es de agregación porque:
- Un Curso "tiene" estudiantes, pero estos pueden existir sin el Curso.
- Los Estudiantes pueden estar inscritos en múltiples Cursos.
- Se usa shared_ptr, lo que permite compartir estudiantes entre distintos cursos, por lo que
la vida de un estudiante no depende de un curso específico.


**Archivos:**  
- `estudiante.hpp`
- `curso.hpp`
- `menu.hpp`
- `estudiante.cpp`
- `curso.cpp`
- `menu.cpp`
- `main.cpp`

**Cómo compilar:**  
```
g++ -std=c++17 -o Ej2 main.cpp menu.cpp curso.cpp estudiante.cpp
```
Esto genera un ejecutable llamado `Ej2`

**Cómo ejecutar:**
```
./Ej2
```

---

### Ejercicio 3
**Descripción:**  
Este ejercicio implementa una jerarquía de clases para representar números de diferentes tipos: enteros, reales y complejos. La clase base abstracta `Numero` define las operaciones aritméticas básicas (`+`, `-`, `*`, `/`) y un método para mostrar el número como cadena (`toString`). Las clases derivadas (`Entero`, `Real` y `Complejo`) implementan estas operaciones, permitiendo realizar cálculos entre números de distintos tipos. El programa incluye un menú interactivo para probar las operaciones.

**Archivos:**  
- `Ej3.cpp`
- `Ej3.hpp`
- `main.cpp`

**Cómo compilar:**  
```
g++ -std=c++17 -o Ej3 main.cpp Ej3.cpp
```
Esto genera un ejecutable llamado `Ej3`

**Cómo ejecutar:**
```
./Ej3
```

---

### Ejercicio 4
**Descripción:**    
Este ejercicio implementa un sistema de cuentas bancarias con herencia. La clase base `CuentaBancaria` define las operaciones comunes, como depositar dinero. Las clases derivadas `CajaDeAhorro` y `CuentaCorriente` implementan versiones específicas, como restricciones en retiros o transferencias entre cuentas. Además, se tiene un menú interactivo para gestionar las cuentas, mostrando información, realizando depósitos, retiros, etc.

**Archivos:**  
- `Ej4.cpp`
- `Ej4.hpp`
- `main.cpp`

**Cómo compilar:**  
```
g++ -std=c++17 -o Ej4 Ej4.cpp main.cpp
```
Esto genera un ejecutable llamado `Ej4`

**Cómo ejecutar:**
```
./Ej4
```