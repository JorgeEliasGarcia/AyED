// AUTOR: Jorge Elías García
// FECHA: 18 abril 2022
// EMAIL: alu0101472294@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <math.h> // fabs, pow

#include <iostream>

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;          // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode; // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
public:
  // constructores
  SllPolynomial(void) : sll_t(){};
  SllPolynomial(const vector_t<double> &, const double = EPS);

  // destructor
  ~SllPolynomial(){};

  // E/S
  void Write(std::ostream & = std::cout) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial &, const double = EPS) const;
  void Sum(const SllPolynomial &, SllPolynomial &, const double = EPS);

  void EliminarElemento(const double, const double = EPS);
};

bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II

// constructor
SllPolynomial::SllPolynomial(const vector_t<double> &v, const double eps) {
  for (int i{v.get_size() - 1}; i >= 0; --i) {
    if (fabs(v[i]) > eps) {
      pair_double_t pareja{v[i], i};
      push_front(new SllPolyNode{pareja});
    }
  }
}

// E/S
void SllPolynomial::Write(std::ostream &os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode *aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const SllPolynomial &p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  assert(!empty());
  SllPolyNode *aux;
  aux = get_head();
  while (aux != NULL) {
    result += aux->get_data().get_val() * pow(x, aux->get_data().get_inx());
    aux = aux->get_next();
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial &sllpol,
                            const double eps) const {
  bool differents = false;
  if (empty() != sllpol.empty()) {
    return differents;
  }
  SllPolyNode *primer_auxiliar = get_head();
  SllPolyNode *segundo_auxiliar = sllpol.get_head();
  while (primer_auxiliar != NULL) {
    // Al solo almacenar valores distintos de cero, si un polinomio tiene un
    // valor más son distintos.
    if ((primer_auxiliar->get_next() == NULL &&
         segundo_auxiliar->get_next() != NULL) ||
        (primer_auxiliar->get_next() != NULL &&
         segundo_auxiliar->get_next() == NULL)) {
      return differents;
    }
    if (fabs(primer_auxiliar->get_data().get_val() -
             segundo_auxiliar->get_data().get_val()) > 0 ||
        primer_auxiliar->get_data().get_inx() !=
            segundo_auxiliar->get_data().get_inx()) {
      return differents;
    }
    primer_auxiliar = primer_auxiliar->get_next();
    segundo_auxiliar = segundo_auxiliar->get_next();
  }

  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial &sllpol, SllPolynomial &sllpolsum,
                        const double eps) {
  // Nos aseguramos que al menos uno de los dos polinomios no esté vacio
  assert(!sllpol.empty() || !empty());
  SllPolyNode *primer_auxiliar = sllpol.get_head();
  SllPolyNode *segundo_auxiliar = get_head();
  pair_double_t primer_monomio;
  // Realizamos la primera iteración fuera, para obtener la cabeza de la lista y
  // evitar hacer un if para comprobar si está vacía en cada iteración del bucle
  if (primer_auxiliar->get_data().get_inx() !=
      segundo_auxiliar->get_data().get_inx()) {
    if ((primer_auxiliar->get_data().get_inx() <
             segundo_auxiliar->get_data().get_inx() &&
         primer_auxiliar != NULL)) {
      primer_monomio.set(primer_auxiliar->get_data().get_val(),
                         primer_auxiliar->get_data().get_inx());
      primer_auxiliar = primer_auxiliar->get_next();
    } else {
      primer_monomio.set(segundo_auxiliar->get_data().get_val(),
                         segundo_auxiliar->get_data().get_inx());
      segundo_auxiliar = segundo_auxiliar->get_next();
    }

  } else {
    primer_monomio.set(primer_auxiliar->get_data().get_val() +
                           segundo_auxiliar->get_data().get_val(),
                       primer_auxiliar->get_data().get_inx());
    primer_auxiliar = primer_auxiliar->get_next();
    segundo_auxiliar = segundo_auxiliar->get_next();
  }

  sllpolsum.push_front(new SllPolyNode{primer_monomio});
  SllPolyNode *aux = sllpolsum.get_head();
  bool nulo{false};

  while (primer_auxiliar != NULL || segundo_auxiliar != NULL) {
    pair_double_t Monomio;

    if (primer_auxiliar == NULL) {
      Monomio.set(segundo_auxiliar->get_data().get_val(),
                  segundo_auxiliar->get_data().get_inx());
      segundo_auxiliar = segundo_auxiliar->get_next();
      nulo = true;
    }
    if (segundo_auxiliar == NULL) {
      Monomio.set(primer_auxiliar->get_data().get_val(),
                  primer_auxiliar->get_data().get_inx());
      primer_auxiliar = primer_auxiliar->get_next();
      nulo = true;
    }

    if (!nulo) {
      if (primer_auxiliar->get_data().get_inx() !=
          segundo_auxiliar->get_data().get_inx()) {
        if ((primer_auxiliar->get_data().get_inx() <
                 segundo_auxiliar->get_data().get_inx() &&
             primer_auxiliar != NULL)) {
          Monomio.set(primer_auxiliar->get_data().get_val(),
                      primer_auxiliar->get_data().get_inx());
          primer_auxiliar = primer_auxiliar->get_next();
        } else {
          Monomio.set(segundo_auxiliar->get_data().get_val(),
                      segundo_auxiliar->get_data().get_inx());
          segundo_auxiliar = segundo_auxiliar->get_next();
        }

      } else {
        Monomio.set(primer_auxiliar->get_data().get_val() +
                        segundo_auxiliar->get_data().get_val(),
                    primer_auxiliar->get_data().get_inx());
        primer_auxiliar = primer_auxiliar->get_next();
        segundo_auxiliar = segundo_auxiliar->get_next();
      }
    }
    // Encontramos el último elemento para insertar los monomios en orden.

    while (aux != NULL) {
      if (aux->get_next() == NULL) {
        if (fabs(Monomio.get_val()) > eps) {
          sllpolsum.insert_after(aux, new SllPolyNode{Monomio});
        }
        break;
      }
      aux = aux->get_next();
    }
  }
}

void SllPolynomial::EliminarElemento(const double coeficiente,
                                     const double eps) {
  assert(!empty());
  SllPolyNode *aux = get_head();
  if (fabs(aux->get_data().get_val() - coeficiente) < eps) {
    //En este caso, era el primer elemento 
    pop_front(); 
    aux = NULL; 
  }
  while(aux != NULL) {
    if (aux->get_next()->get_data().get_val() == coeficiente) {
      erase_after(aux); 
      aux = NULL; 
    } else {
      aux = aux->get_next(); 
    }
  }
}


/* 
void SllPolynomial::EliminarElemento(const double coeficiente,
                                     const double eps) {
  assert(!empty());
  SllPolyNode *aux = get_head();
  SllPolyNode *segundo_aux = get_head();
  bool encontrado = false;
  while (aux != NULL || encontrado) {
    // Identificamos que el próximo elemento es aquel que queremos eliminar
    if (fabs(aux->get_next()->get_data().get_val() - coeficiente) < eps) {
      // El nodo anterior al que queremos eliminar, apuntará al nodo que
      // apuntaba el nodo que vamos a eliminar. 
      encontrado = true;
      segundo_aux->set_next(segundo_aux->get_next()->get_next());
      
      aux = aux->get_next(); 
      aux = NULL; 
      break;
    } else {
      aux = aux->get_next();
      segundo_aux = segundo_aux->get_next();
    }
  }
}
*/
#endif // SLLPOLYNOMIAL_H_
