/**
 AUTOR: Jorge Elías García
 FECHA: 14 marzo 2022
 EMAIL: alu0101472294@ull.edu.es
 VERSION: 1.0
 ASIGNATURA: Algoritmos y Estructuras de Datos
 PRÁCTICA Nº: 2
 COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
             https://geosoft.no/development/cppstyle.html
*/

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
inline int rational_t::get_num() const { return num_; }

inline int rational_t::get_den() const { return den_; }

void rational_t::set_num(const int n) { num_ = n; }

void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

inline double rational_t::value() const { return double(get_num()) / get_den(); }

rational_t rational_t::opposite() const { return rational_t((-1) * get_num(), get_den()); }

rational_t rational_t::reciprocal() const { return rational_t(get_den(), get_num()); }

// comparaciones
bool rational_t::is_equal(const rational_t& r, const double precision) const {
  return fabs(value() - r.value()) < precision;
}

bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}

bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
}

// operaciones
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), get_den() * r.get_den());
}

rational_t rational_t::substract(const rational_t& r) const { return add(r.opposite()); }

rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

rational_t rational_t::divide(const rational_t& r) const { return multiply(r.reciprocal()); }

// FASE I: operadores

//Sobrecarga del operador suma cuando recibimos dos racionales
rational_t operator+(const rational_t& a, const rational_t& b) {
  const rational_t kResultado{a.get_num() * b.get_den() + a.get_den() * b.get_num(),
                              a.get_den() * b.get_den()};
  return kResultado;
}

//Sobrecarga del operador resta cuando recibimos dos racionales
rational_t operator-(const rational_t& a, const rational_t& b) {
  const rational_t kResultado{a.get_num() * b.get_den() - a.get_den() * b.get_num(),
                              a.get_den() * b.get_den()};
  return kResultado;
}

//Sobrecarga del operador multiplicación cuando recibimos dos racionales
rational_t operator*(const rational_t& a, const rational_t& b) {
  const rational_t kResultado{a.get_num() * b.get_num(), a.get_den() * b.get_den()};
  return kResultado;
}

//Sobrecarga del operador división cuando recibimos dos racionales
rational_t operator/(const rational_t& a, const rational_t& b) {
  const rational_t kResultado{a.get_num() * b.get_den(), a.get_den() * b.get_num()};
  return kResultado;
}

// E/S
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}

ostream& operator<<(ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}

istream& operator>>(istream& is, rational_t& r) {
  r.read(is);
  return is;
}