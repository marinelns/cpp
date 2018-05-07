#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cassert>
#include "Dvector.h"

using namespace std;

int main(){
  Dvector v = Dvector(2);
  printf("La taille du vecteur v est %i \n ", v.size());
  printf("Je suis v \n");
  v.display(std::cout);
  v.fillRandomly();
  v.display(std::cout);
  Dvector y = Dvector(v);
  printf("Je suis y \n");
  y.display(std::cout);
  Dvector w = Dvector(3);
  printf("Je suis w \n" );
  w.display(std::cout);
  w = y;
  printf("Je suis w après avoir été change en y\n");
  w.display(std::cout);
  w += y;
  printf("Je suis w + y \n");
  w.display(std::cout);
  w += 1;
  printf("On rajoute 1 à  w\n");
  w.display(std::cout);
  w -= 1;
  printf("En fait c'était moche donc on enlève 1\n");
  w.display(std::cout);
  w*=5;
  printf("Il est préférable de le multiplier par 5 plutot\n");
  w.display(std::cout);
  w /= v;
  printf("Oh je viens de me diviser par v\n");
  w.display(std::cout);
  y = 5 + w;
  printf("Oups on m'ajoute 5 \n");
  y.display(std::cout);
  w = w + w;
  printf("Je vais devenir grand \n");
  w.display(std::cout);
  printf("%i\n ", w == y);

}
