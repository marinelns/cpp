/**
* \file Ocean.cpp
* \brief mise en place de l'ocean de vectur
*/
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

void Ocean::setHauteur(double haut){
  this->t = haut;
}

void Ocean::compute(){
  for(double i =0; i < Nx; i++){
    for(double j=0; j < Ny; j++){
      this->hauteur(i*Ny+j) = (*model)(i,j,t);
    }
  }
}

void Ocean::computeset(){
  setVectorHauteur((*model)(t));
}

void Ocean::gl_vertices(double h_init){
  for(double i =0; i < Nx; i++){
    for(double j=0; j < Ny; j++){
      this->hauteur(i*Ny+j) = h_init;
    }
  }
}
