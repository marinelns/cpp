#ifndef OceanH
#define OceanH

#include <iostream>
#include <assert.h>
#include "Height.h"
#include "Dvector.h"
#include "WaveModel.h"
#include "PhilipsWaveModel.h"

class Ocean{
  private:
    double Lx, Ly;
    int Nx, Ny;
    double t;
    Height hauteur;
    WaveModel *model;
    Dvector vertices;

  public:
    ~Ocean();
    Ocean(double lx, double ly, int nx, int ny, double t, WaveModel* model);
    Height getHauteur()const{
      return hauteur;
    }
    void setHauteur(double haut);
    void compute();
    void gl_vertices(double h_init);
};

#endif
