#include "stack_l_t.h"
#include "queue_l_t.h"
#include <iostream>

int main() {

  stack_l_t<int> pila; 
  pila.push(1); 
  pila.push(2); 
  pila.push(3); 
  pila.push(4); 
  pila.push(5); 
  std::cout << "Pila original: " << std::endl; 
  pila.write(); 
  std::cout << std::endl; 
  pila.Invertir(); 
  std::cout <<"Pila invertida: " << std::endl; 
  pila.write(); 
  std::cout << std::endl; 

  return 0; 
}