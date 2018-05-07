#ifndef PhilipsWaveModel_HPP
#define PhilipsWaveModel_HPP

#include "Dvector.h"
#include "WaveModel.h"
#include "GeneriqueVector.h"
#include <complex.h>
#include <assert.h>
#include <complex>


#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <math.h>
#include <cstring>



class PhilipsWaveModel : public WaveModel{
  private:
    double A;
    int N, M;
    complex<double> ksi;

  public:
    ~PhilipsWaveModel();
    PhilipsWaveModel(Dvector vent_direction, double intensite);

    double operator()(double x, double y, double t);
    double operator()(double x, double y, double t)const;

    Dvector operator()(double t);
    double houle(double kx, double ky);
};

#endif
