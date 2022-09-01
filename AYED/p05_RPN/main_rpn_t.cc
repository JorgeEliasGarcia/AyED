//  AUTOR: Jorge Elías
// FECHA: 13/05/22
// EMAIL: alu0101472294@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Programa principal para probar la calculadora de expresiones 
//              en notaión polaca inversa (RPN, Reverse Polish Notation)
// COMPILACIÓN: g++ main_rpn_t.cc -o main_rpn_t
// EJECUCIÓN:
//   ./main_rpn_t < data_rpn_t_1.txt
//   ./main_rpn_t < data_rpn_t_2.txt
//   ./main_rpn_t < data_rpn_t_3.txt

// Compilar con:
// 

#include <iostream>

#include "stack_l_t.h"
#include "queue_l_t.h"
#include "rpn_t.h"

using namespace std;

int main(void) {
  rpn_t<stack_l_t<int>> calculadora;
  queue_l_t<char> cola;
	
  while (!cin.eof()) 	{
    cin >> ws; // lee los espacios en blanco, que dan problemas
    if (!cin.eof()) {
      char c;
      cin >> c;
      cola.push(c);
    }
  }

  cout << "Expresión a evaluar: ";	
  cola.write();

  int r = calculadora.evaluate(cola);
  cout << "Resultado: " << r << endl;

  stack_l_t<int> pila; 
  pila.push(1); 
  pila.push(2); 
  pila.push(3); 
  std::cout << "Sumatorio: " << pila.Sum() << endl; 

  return 0;
}

