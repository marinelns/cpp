#include "../src/Height.h"

int main(){
  Height h = Height(1,1,1,1);
  Dvector vect = h.getVector();
  double lx  = h.getLx();
  printf("Je suis un vecteur de longeuur %f \n", lx);
  vect.display(std::cout);
  printf("Je veux me transformer en h2 :\n");
  Height h2 = Height(3,2,1,2);
  h = h2;
  h2.getVector().display(std::cout);
}
