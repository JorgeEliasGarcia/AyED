// AUTOR: Jorge Elías
// FECHA:
// EMAIL:
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
//

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <math.h>  // fabs, pow

#include <iostream>

#include "sparse_vector_t.h"
#include "vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n){};
  Polynomial(const Polynomial& pol) : vector_t<double>(pol){};  // constructor de copia

  // destructor
  ~Polynomial(){};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n){};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol){};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial(){};

  // E/S
  void Write(std::ostream& = std::cout) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  double SumarCoeficientes() const;
  double ProductoEscalar(const SparsePolynomial& vec) const;

  double ProductoConVectorDenso(const Polynomial& vec) const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i) << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1) os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for (int i{0}; i < get_size(); ++i) {
    result += at(i) * pow(x, i);
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int recorrido = get_size() <= pol.get_size() ? get_size() : pol.get_size();
  for (int i{0}; i < recorrido; ++i) {
    if (fabs(at(i) - pol.at(i)) > eps) {
      return differents;
    }
  }

  if (get_size() > recorrido) {
    for (int i{recorrido}; i < get_size(); ++i) {
      if (fabs(at(i)) > eps) {
        return false;
      }
    }
  }

  if (pol.get_size() > recorrido) {
    for (int i{recorrido}; i < pol.get_size(); ++i) {
      if (fabs(pol.at(i)) > eps) {
        return false;
      }
    }
  }
  return !differents;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;  // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val() << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1) os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i{0}; i < get_nz(); ++i) {
    result += at(i).get_val() * pow(x, at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {
  bool differents = false;
  if (get_nz() != spol.get_nz()) {
    return false;
  }
  for (int i{0}; i < spol.get_nz(); ++i) {
    if (fabs(at(i).get_val() - spol.at(i).get_val()) > eps ||
        at(i).get_inx() != spol.at(i).get_inx()) {
      return differents;
    }
  }

  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // En caso que el vector disperso tenga más elementos nz_ que el polimonio elementos totales ya
  // sabemos que no son iguales.
  if (get_nz() > pol.get_size()) {
    return differents;
  }
  // En caso de que el elemento del vector denso sea igual a cero, el contador del vector disperso
  // no aumentará.
  for (int i{0}, j{0}; i < pol.get_size(); ++i) {
    if (fabs(pol.at(i)) > eps) {
      if (fabs(at(j).get_val() - pol.at(i)) > eps || at(j).get_inx() != i) {
        return differents;
      }
      ++j;
    }
  }
  return !differents;
}

// Esta función calcula la suma de los coeficientes de un polinomio disperso
double SparsePolynomial::SumarCoeficientes() const {
  double suma{0.0};
  for (int i{0}; i < get_nz(); ++i) {
    suma += at(i).get_val();
  }
  return suma;
}

// Función que calcula el producto escalar
double SparsePolynomial::ProductoEscalar(const SparsePolynomial& vec) const {
  assert(vec.get_n() == get_n());  // Aseguramos que tenían el mismo tamaño inicial
  double producto = 0.0;
  bool insertado = false; //Nos ayudará a optimizar el código

  for (int i{0}; i < get_nz(); ++i) {
    int indice = at(i).get_inx();
    insertado = false; 
    for (int j{0}; j < vec.get_nz() && !insertado; ++j) {
      if (vec.at(j).get_inx() == indice) {
        producto += vec.at(j).get_val() * at(i).get_val();
        insertado = true; 
      }
    }
  }

  /*
    // Recorreremos tantas veces como elementos tenga el vector con mayor get_nz(), para de esta
    // manera poder multiplicar todos
    int x = get_nz() >= vec.get_nz() ? get_nz() : vec.get_nz();
    double producto{0.0};
    for (int i{0}, j{0}, k{0}; i <= x; ++i) {
      if (at(j).get_inx() != vec[k].get_inx()) {
        if (at(j).get_inx() < vec[k].get_inx()) {
          ++j;
        } else {
          ++k;
        }

      } else {
        producto += at(j).get_val() * vec.at(k).get_val();
        ++j;
        ++k;
      }
    }
  */
  return producto;
}

double SparsePolynomial::ProductoConVectorDenso(const Polynomial& vec) const {
  double producto{0.0};
  for (int i{0}; i < get_nz(); ++i) {
    if (at(i).get_inx() < vec.get_size()) {
      producto += at(i).get_val() * vec[at(i).get_inx()];
    }
  }
  return producto; 
}

#endif  // POLYNOMIAL_H_
