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

#include "rational_t.hpp"

// Constructor de la clase
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo: No usar más de 1 o 2 líneas de separación entre métodos

// pauta de estilo: Tipo retornado un espacio antes del nombre de la función

// getter del numerador
int rational_t::get_num() const { return num_; }

// getter del denominador
int rational_t::get_den() const { return den_; }

// setter del numerador
void rational_t::set_num(const int n) { num_ = n; }

// setter del denominador
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

// Retorna el valor de un número racional, diviendo numerador entre denominador.
double rational_t::value() const { return double(get_num()) / get_den(); }

// comparaciones

// Esta función determina si dos números racionles son iguales o no.
bool rational_t::is_equal(const rational_t &r, const double precision) const {
  const double kResultado{(value()) - (r.value())};
  if (fabs(kResultado) < precision) {
    return true;
  }
  return false;
}

// Esta función determinará si un número racional es mayor que otro.
bool rational_t::is_greater(const rational_t &r, const double precision) const {
  if ((value() - r.value()) > precision) {
    return true;
  }
  return false;
}

// Esta función determinará si un número racional es menor que otro.
bool rational_t::is_less(const rational_t &r, const double precision) const {
  if ((r.value() - value()) > precision) {
    return true;
  }
  return false;
}

// operaciones

// Esta función nos permite sumar dos número racionales.
rational_t rational_t::add(const rational_t &r) const {
  const rational_t kResultado{get_num() * r.get_den() + get_den() * r.get_num(),
                              get_den() * r.get_den()};
  return kResultado;
}

// Esta función nos permite restar dos número racionales.
rational_t rational_t::substract(const rational_t &r) const {
  const rational_t kResultado{get_num() * r.get_den() - get_den() * r.get_num(),
                              get_den() * r.get_den()};
  return kResultado;
}

// Esta función nos permite multiplicar dos números racionales.
rational_t rational_t::multiply(const rational_t &r) const {
  const rational_t kResultado{get_num() * r.get_num(), get_den() * r.get_den()};
  return kResultado;
}

// Esta función nos permite dividir dos número racionales
rational_t rational_t::divide(const rational_t &r) const {
  const rational_t kResultado{get_num() * r.get_den(), get_den() * r.get_num()};
  return kResultado;
}

// Esta función permite determinar si un número es realmente entero
bool rational_t::is_integrer(void) const {
  if (get_num() % get_den() == 0) {
    return true;
  }
  return false;
}

// E/S

// Permite insertar un número racional en un flujo de salida.
void rational_t::write(ostream &os) const {
  os << get_num() << "/" << get_den() << " = " << value() << endl;
}

// Permite la extracción de un número racional desde un flujo de entrada.
void rational_t::read(istream &is) {
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}