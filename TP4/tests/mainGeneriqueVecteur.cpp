#include "../src/GeneriqueVector.h"
#include <complex.h>

int main(){
  GeneriqueVector v = GeneriqueVector(2);
  printf("La taille du vecteur v est %i \n ", v.size());
  printf("Je suis v \n");
  v.display(std::cout);
  v.fillRandomly();
  v.display(std::cout);
  GeneriqueVector y = GeneriqueVector(v);
  printf("Je suis y \n");
  y.display(std::cout);
  GeneriqueVector w = GeneriqueVector(3);
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
  complex<double> com = cexp(-I*4);
  complex<double> com2 = cexp(-I*8);
  printf("Mon complexe est %f, %f\n", com);
  GeneriqueVector ffggt = GeneriqueVector(8, com);
  GeneriqueVector ffw = GeneriqueVector(8,com2);
  GeneriqueVector ff = ffggt + ffw;
  printf("%i", ff.size());
  printf("Mon nouveau vecteur ff \n");
  ff.display(std::cout);
  GeneriqueVector ffko = ff.conjugue();
  printf("Mon nouveau vecteur ff \n");
  ffko.display(std::cout);
  GeneriqueVector ffl = ffko.conjugue();
  printf("Mon nouveau vecteur ffL \n");
  ffl.display(std::cout);
  ff.fft();
  printf("J'ai subit une fft \n");
  ff.display(std::cout);
  printf("On a subit une ifft\n");
  GeneriqueVector gjg = ff.ifft();
  gjg.display(std::cout);

}
