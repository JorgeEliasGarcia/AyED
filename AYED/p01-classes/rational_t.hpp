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

#pragma once

#include <cassert>
#include <cmath>
#include <iostream>

// pauta de estilo: Las constantes empiezan por k, seguidas de una letra mayúscula
#define kEpsilon 1e-6

using namespace std;

class rational_t {

  // pautas de estilos: primero "public" y después "private"

  // Miembros públicos
 public:

  // constructor de la clase
  rational_t(const int = 0, const int = 1);

  // destructor de la clase
  ~rational_t() {}

  // pauta de estilo: indentación a 2 espacios

  // getters

  // getter del numerador
  int get_num() const;

  // getter del denominador
  int get_den() const;

  // setters

  // setter del numerador
  void set_num(const int);

  // setter del denominador
  void set_den(const int);
  
  //retorna del valor del número racional
  double value(void) const;

  // FASE II
  bool is_equal(const rational_t &, const double precision = kEpsilon) const;
  bool is_greater(const rational_t &, const double precision = kEpsilon) const;
  bool is_less(const rational_t &, const double precision = kEpsilon) const;

  // FASE III
  rational_t add(const rational_t &) const;
  rational_t substract(const rational_t &) const;
  rational_t multiply(const rational_t &) const;
  rational_t divide(const rational_t &) const;

  //FASE IV   
  bool is_integrer(void) const; 

  // método de escritura a pantalla
  void write(ostream & = cout) const;

  // método de lectura del teclado
  void read(istream & = cin);

  // Miembros privados:
 private:
 
  // pauta de estilo: nombre de los atributos seguido de "_"
  int num_, den_;
};
