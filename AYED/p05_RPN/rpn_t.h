// AUTOR: Jorge Elías
// FECHA: 13/05/22
// EMAIL: alu0101472294@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <cctype>
#include <cmath>
#include <iostream>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
public:
  // constructor
  rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char> &);

private:
  T stack_;
  void operate_(const char operador);
};

// operaciones
template <class T> const int rpn_t<T>::evaluate(queue_l_t<char> &q) {
  while (!q.empty()) {
    char c = q.front();

    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';

      std::cout << " (es un dígito) " << std::endl
                << "   Lo metemos en la pila..." << std::endl;
      stack_.push(i);

    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  // Aseguramos que en la pila solo había un elemento restante (resultado)
  const int resultado = stack_.top();
  stack_.pop();
  assert(stack_.empty());
  stack_.push(resultado);
  return stack_.top();
}

template <class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' ||
         c == 'l' || c == 'c');

  // poner código
  std::cout << "   Sacamos de la pila un operando: ";
  const double kPrimerElemento = stack_.top();
  stack_.pop();
  std::cout << kPrimerElemento << std::endl;
  double kSegundoElemento;
  if (c != 'r' && c != 'l' && c != 'c') {
    std::cout << "   Sacamos de la pila otro operando: ";
    kSegundoElemento = stack_.top();
    stack_.pop();
    std::cout << kSegundoElemento << std::endl;
  }

  switch (c) {
  case '+':

    stack_.push(kPrimerElemento + kSegundoElemento);
    break;

  case '*':
    stack_.push(kPrimerElemento * kSegundoElemento);
    break;

  case '-':
    stack_.push(kSegundoElemento - kPrimerElemento);
    break;

  case '/':

    stack_.push(kSegundoElemento / kPrimerElemento);
    break;

  case '^':
    stack_.push(pow(kSegundoElemento, kPrimerElemento));
    break;

  case 'r':

    stack_.push(sqrt(kPrimerElemento));
    break;

  case 'c':

    stack_.push(pow(kPrimerElemento, 2));
    break;

  case 'l':
    stack_.push(log2(kPrimerElemento));
    break;

  default:
    break;
  }

  std::cout << "   Metemos en la pila el resultado: ";
  std::cout << stack_.top() << std::endl;
}

#endif // RPNT_H_
