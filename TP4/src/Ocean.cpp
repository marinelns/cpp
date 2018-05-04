#include "Ocean.h"

Ocean::~Ocean(){
}

Ocean::Ocean(double lx, double ly, int nx, int ny, double t, WaveModel* model){
  this->Lx = lx;
  this->Ly = ly;
  this->Nx = nx;
  this->Ny = ny;
  this->t = t;
  this->model = model;
  this->vertices = Dvector(nx*ny);
  this->hauteur = Height(Lx, Ly, Nx, Ny);
}

Height Ocean::getHauteur(){

}

void Ocean::setHauteur(double haut){
  this->t = t;
}

void Ocean::compute(){
  for(int i =0; i < Nx; i++){
    for(int j=0; j < Ny; j++){

    }
  }
}
void gl_vertices(double hauteur_initiale);
