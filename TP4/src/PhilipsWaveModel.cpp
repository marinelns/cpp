/**
* \file PhilipsWaveModel.cpp
* \brief mise en place de vecteurs de philips
*/

#include "PhilipsWaveModel.h"


#define RAND ((double) rand())/((double) RAND_MAX)
#define PIDOUBLE 2*PI
#define RANDN sqrt(-2*log(RAND))*cos(PIDOUBLE*RAND)

double loinormal(double mu, double sigma){
  if(sigma <= 0){
    std::cout<<"Sigme doit etre supérieur à 0"<<"\n";
    throw 0;
  }
  return (mu + sigma*RANDN);
}


PhilipsWaveModel::PhilipsWaveModel(Dvector vent_direction, double intensite){
  this->_direction = vent_direction;
  this->_alignement = 0.0f;
  this->_intensite = intensite;
  this->_longueur = 10.0f;
  this->_ajustement = 10.0f;
  N = 256;
  M = 256;
  double ksi_r = loinormal(0,1);
  double ksi_i = loinormal(0,1);
  ksi = complex<double>(ksi_r, ksi_i);
}

PhilipsWaveModel::~PhilipsWaveModel(){
}

Dvector PhilipsWaveModel::operator() (double t){
  int l = 0;
  int taille  = N*M;
  GeneriqueVector htilde = GeneriqueVector(taille);
  for(int n = -N/2; n < N/2; n++){
    for(int m = -M/2; m < M/2; m++){
      double kx = 9.81*n/N;
      double ky = 9.81*m/M;
      complex<double> premiere_part = exp(sqrt(9.81*sqrt(kx*kx+ky*ky)) * t);
      premiere_part *= sqrt(houle(kx, ky)) * (1/sqrt(2)) * ksi;
      complex<double> seconde_part = exp(-sqrt(9.81*sqrt(kx*kx+ky*ky)) * t) * sqrt(houle(-kx, -ky));
      seconde_part *= (1/sqrt(2)) * (conj(ksi));
      htilde(l++) = premiere_part + seconde_part;
    }
  }
  htilde.ifft();
  Dvector vector = Dvector(taille);
  for(int i=0; i< taille; i++){
      vector(i) = real(htilde(i));
  }
  return vector;
}


double PhilipsWaveModel::houle(double kx, double ky){
    double kcarre = kx*kx + ky*ky;
    double L = _intensite * _intensite / 9.81;
    double scal = kx*_direction(0) + ky * _direction(1);
    return A * exp((-1/(kcarre*L*L))/kcarre) * scal * scal;
}

double PhilipsWaveModel::operator()(double x, double y, double t){
  return 0;
}

double PhilipsWaveModel::operator()(double x, double y, double t)const{
  return 0;
}
