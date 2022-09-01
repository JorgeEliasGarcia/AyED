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

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>


# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos: primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // pauta de estilo: indentación a 2 espacios
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;
  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;

  rational_t add(const rational_t&) const;
  rational_t substract(const rational_t&) const;
  rational_t multiply(const rational_t&) const;
  rational_t divide(const rational_t&) const;

  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private:
  // pauta de estilo: nombre de los atributos seguido de "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);

