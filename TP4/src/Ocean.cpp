/**
* \file Ocean.cpp
* \brief mise en place de l'ocean de vectur
*/
#include "Ocean.h"

Ocean::~Ocean(){
}

Ocean::Ocean(double lx, double ly, int Nx, int Ny, double t, WaveModel* model){
  this->Lx = lx;
  this->Ly = ly;
  this->Nx = Nx;
  this->Ny = Ny;
  this->t = t;
  this->model = model;
  this->vertices = new double[3*(Ny+Nx)];
  this->hauteur = Height(Nx, Ny, 0.0);
}

void Ocean::setHauteur(double haut){
  this->t = haut;
}

void Ocean::generateHeight(double h)
{
  this->hauteur = Height(this->Nx, this->Ny, h);
}

Height Ocean::compute(double t) {
  Height res = Height(this->Lx, this->Ny, this->Nx, this->Ny);
  for (int i = 0; i < Nx; i++)
    for (int j = 0; j < Ny; j++)
      res(i, j) = (*model)(i*Lx/Nx, j*Ly/Ny, t);
  return res;
}

void Ocean::computeset(){
  hauteur.setVector((*model)(t));
}

void Ocean::gl_vertices(double h_init){
  for(double i =0; i < Nx; i++){
    for(double j=0; j < Ny; j++){
      this->hauteur(i*Ny+j) = h_init;
    }
  }
}

double Ocean::get_lx(){return Lx;}
double Ocean::get_ly(){return Ly;}
double Ocean::getNx(){return Nx;}
double Ocean::getNy(){return Ny;}

void Ocean::main_computation(double t) {
    this->t = t;
    this->hauteur = this->compute(t);
}

void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<Nx ; x++) {
    vertices[3*x]   = (Lx/Nx)*x;
    vertices[3*x+2] = (Ly/Ny)*y;
  }
  vertices[3*Nx]   = Lx;
  vertices[3*Nx+2] = (Ly/Ny)*y;
}


void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<Ny ; y++) {
    vertices[3*y]   = (Lx/Nx)*x;
    vertices[3*y+2] = (Ly/Ny)*y;
  }
  vertices[3*Ny]   = (Lx/Nx)*x;
  vertices[3*Ny+2] = Ly;
}


void Ocean::gl_vertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<Nx ; x++) {
    vertices[3*x+1] = pow(-1, x+y)*hauteur(y,x);
  }
  vertices[3*Nx+1] = pow(-1, Nx+y)*hauteur(y,0);
}


void Ocean::gl_vertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<Ny ; y++) {
    vertices[3*y+1] = hauteur(y,x);
  }
  vertices[3*Ny+1]  = hauteur(0,x);
}
