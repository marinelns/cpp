#include "Height.h"

Height::Height(){
  vect = Dvector(0);
  lx = 0;
  ly = 0;
  nx = 0;
  ny = 0;
}

Height::Height(double l_x, double l_y, double n_x, double n_y){
  vect = Dvector(n_x*n_y, 1);
  lx = l_x;
  ly = l_y;
  nx = n_x;
  ny = n_y;
}

Height::Height(const Height & h){
  *this = h;
}

Height::~Height(){}

Dvector Height::getVector() const{
  return vect;
}

double Height::getLx() const{
  return lx;
}

double Height::getLy() const{
  return ly;
}

double Height::getNx() const{
  return nx;
}

double Height::getNy() const{
  return ny;
}

Height& Height::operator = (const Height& h){
  if (h.getVector().size()==0){
    delete this;
    *this = Height(h);
  }
  else{
    vect = h.getVector();
    lx = h.getLx();
    ly = h.getLy();
    nx = h.getNx();
    ny = h.getNy();
  }
  return *this;
}

double& Height::operator() (double i, double j) const {
    if (i <= nx && j <= ny) {
        return vect(i*nx + j);
    }
    throw "La case n'existe pas";
}

// int main(){
//   Height h = Height(1,1,1,1);
//   Dvector vect = h.getVector();
//   double lx  = h.getLx();
//   printf("Je suis un vecteur de longeuur %f \n", lx);
//   vect.display(std::cout);
//   printf("Je veux me transformer en h2 :\n");
//   Height h2 = Height(3,2,1,2);
//   h = h2;
//   h2.getVector().display(std::cout);
// }
