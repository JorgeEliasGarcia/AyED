#include "sll_node_t.h"
#include "sll_t.h"

int main() {
  sll_t<int> lista; 
  sll_node_t<int>* nodo; 
  std::cout << lista.empty() << std::endl; 
  lista.push_front(nodo); 
  std::cout << lista.empty() << std::endl; 
  return 0; 
}