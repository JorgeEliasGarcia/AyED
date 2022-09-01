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

#include <cassert>
#include <iostream>

#include "rational_t.hpp"

using namespace std;

template <class T> class vector_t {
public:
  vector_t(const int = 0);
  ~vector_t();

  void resize(const int);

  // getters
  T get_val(const int) const;
  int get_size(void) const;

  // setters
  void set_val(const int, const T);

  // getters-setters
  T &at(const int);
  T &operator[](const int);

  // getters constantes
  const T &at(const int) const;
  const T &operator[](const int) const;

  void write(ostream & = cout) const;
  void read(istream & = cin);

  vector_t<T> Cicilico(const vector_t<T> &vector_introducido) const;

private:
  T *v_;
  int sz_;

  void build(void);
  void destroy(void);
};

template <class T> vector_t<T>::vector_t(const int n) {
  sz_ = n;
  build();
}

template <class T> vector_t<T>::~vector_t() { destroy(); }

template <class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template <class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template <class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

template <class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> inline int vector_t<T>::get_size() const { return sz_; }

template <class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template <class T> T &vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> T &vector_t<T>::operator[](const int i) { return at(i); }

template <class T> const T &vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> const T &vector_t<T>::operator[](const int i) const {
  return at(i);
}

template <class T> void vector_t<T>::write(ostream &os) const {
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}

template <class T> void vector_t<T>::read(istream &is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i) {
    is >> at(i);
  }
}

// FASE II: producto escalar

// Esta función calcula el producto vectorial para vectores de tipos básicos.
template <class T> T scal_prod(const vector_t<T> &v, const vector_t<T> &w) {
  T suma;
  int recorrido;
  if (v.get_size() <= w.get_size()) {
    recorrido = v.get_size();
  } else {
    recorrido = w.get_size();
  }

  for (int contador{0}; contador < recorrido; ++contador) {
    suma = suma + v.get_val(contador) * w.get_val(contador);
  }
  return suma;
}

// Esta función calcula el producto vectorial para vectores de tipo rational.
double scal_prod(const vector_t<rational_t> &v, const vector_t<rational_t> &w) {
  double suma;
  int recorrido;
  if (v.get_size() <= w.get_size()) {
    recorrido = v.get_size();
  } else {
    recorrido = w.get_size();
  }
  for (int contador{0}; contador < recorrido; ++contador) {
    suma = suma + (v[contador].value() * w[contador].value());
  }

  return suma;
}

// Esta función devuelve el vector cíclico del vector introducido
template <class T>
vector_t<T> vector_t<T>::Cicilico(const vector_t<T> &vector_introducido) const {
  vector_t<T> vector_retorno;
  vector_retorno.resize(vector_introducido.get_size());
  vector_retorno[0] = vector_introducido[vector_introducido.get_size() - 1];
  for (int i{0}; i < vector_introducido.get_size() - 1; ++i) {
    vector_retorno[i + 1] = vector_introducido[i];
  }

  return vector_retorno;
}