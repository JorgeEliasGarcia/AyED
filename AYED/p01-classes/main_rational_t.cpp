/** AUTOR: Jorge Elías García
 FECHA: 24 Febrero 2022
 EMAIL: alu0101472294@ull.edu.es
 VERSION: 1.0
 ASIGNATURA: Algoritmos y Estructuras de Datos
 PRÁCTICA Nº: 1
 COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
*/

// pauta de estilo : comentarios multilínea usando  "/*  COMENTARIOS   */"

#include <cmath>
#include <iostream>

// pauta de estilo: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

using namespace std;

int main() {
  rational_t a(1, 2), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  cout << "x > y? " << (x.is_greater(y) ? "true" : "false") << endl;
  cout << "x < y? " << (x.is_less(y) ? "true" : "false") << endl;

  // FASE III
  cout << "a + b: ";
  a.add(b).write();

  cout << "b - a: ";
  b.substract(a).write();

  cout << "a * b: ";
  a.multiply(b).write();

  cout << "a / b: ";
  a.divide(b).write();

  //FASE IV
  
  rational_t d(4, 2); 
  std::cout << "El número racional: " << std::endl; d.write(); 
  std::cout << (d.is_integrer() ? "Entero" : "No entero") << std::endl; 

  return 0;
}