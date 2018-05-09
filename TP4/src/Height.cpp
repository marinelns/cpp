/**
* \file Height.cpp
* \brief mise en place de la hauteur
*/
#include "Height.h"

Height::Height(){
  vect = Dvector();
  lx = 0;
  ly = 0;
  nx = 0;
  ny = 0;
}

Height::Height(double l_x, double l_y, double n_x, double n_y){
  vect = Dvector(n_x*n_y);
  lx = l_x;
  ly = l_y;
  nx = n_x;
  ny = n_y;
  assert(lx >= 0 && ly >=0 && nx>=0 && ny>=0);
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

void Height::setLx(double l_x){
  assert(l_x >= 0);
  this->lx = l_x;
}

void Height::setLy(double l_y){
  assert(l_y >= 0);
  this->ly = l_y;
}

void Height::setNx(double n_x){
  assert(n_x >= 0);
  this->nx = n_x;
}

void Height::setNy(double n_y){
  assert(n_y >= 0);
  this->ny = n_y;
}

void Height::setVector(Dvector vect){
  this->vect = vect;
}

Height& Height::operator = (const Height& h){
    vect = h.getVector();
    lx = h.getLx();
    ly = h.getLy();
    nx = h.getNx();
    ny = h.getNy();
    return *this;
}


double& Height::operator() (int off) const{
    assert(off>=0 && off < vect.size());
    return vect(off);
}

std::ostream& operator << (std::ostream &out, const Height &h){
  for(int j = 0; j < h.getNy()-1; j++){
    for(int i = 0; i < h.getNx(); i++){
      out << i*h.getLx()/(h.getNx()-1) << "," << j*h.getLy()/(h.getNy()-1) << "," << h(h.getNy()*i + j) << std::endl;
    }
    out << std::endl;
  }
  for(int i = 0; i < h.getNx();i++){
    out << i*h.getLx()/(h.getNx()-1) << "," << (h.getNy()-1)*h.getLy()/(h.getNy()-1) << "," << h(h.getNy()*i + h.getNy()- 1) << std::endl;
  }
  return out;
}
