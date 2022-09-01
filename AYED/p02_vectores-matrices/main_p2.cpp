#include "matrix_t.hpp"
#include "rational_t.hpp"
#include "vector_t.hpp"

using namespace std;

int main() {
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a + b).write();

  cout << "b - a: ";
  (b - a).write();

  cout << "a * b: ";
  (a * b).write();

  cout << "a / b: ";
  (a / b).write();

  cout << endl;

  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();

  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;

  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();

  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl;

  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();

  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();

  vector_t<int> vector_prueba; 
  vector_prueba.read(); 
  vector_prueba.write(); 
  vector_prueba.Cicilico(vector_prueba).write();  

  return 0;
}

/**
1) ¿Para qué se sobrecarga el operator[] en la clase vector_t?
  Sobrecargamos el operador [] para obtener el valor del elemento del vector que se encuentre en la
  posición que se pase como parámetro.

2) ¿Qué hace y cómo funciona la sobrecarga del operator() en la clase matrix_t?
  La sobrecarga del operador () nos permite obtener el valor del elemento de la matriz que se
  encuentre en la posición que pasemos como parámetro. En este caso no podríamos sobrecargar el
  operador [], ya que recibimos dos parámetros (fila, columna). En la sobrecarga de este operador
  llamamos al método at() encargado de devolver el valor del elemento de la matriz en dicha
  posición. Para ello, pasamos como parámetros la fila y la columna y aplicamos la fórmula: (i - 1)
* get_n() + (j - 1), siendo i la fila indicada, get_n() el número total de filas y j la columna.


3) También debemos entender las cabeceras que representan la sobrecarga del operadores operator<< y
   operator>>  en la clase rational_t.
   La sobrecarga del operador << nos permite mostrar un número racional por un flujo de salida,
   mientras que el operador >> nos permite recibir un racional por flujo de entrada.
*/