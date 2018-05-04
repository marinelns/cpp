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


PhilipsWaveModel::PhilipsWaveModel(Dvector vent_direction, double intensite):
WaveModel(vent_direction, 0.0f, intensite, 10.0f, 10.0f){
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

  for(int n = -N/2; n< N/2; n++){
    for(int m = -M/2; m< M/2; m++){
      int kx = PIDOUBLE*n/N;
      int ky = PIDOUBLE*m/M;
      //complex<double> premiere_part = cexp(sqrt(9.81*sqrt(kx**2+ky**2)*t))*(1/sqrt(2))*ksi*(sqrt(houle(kx, ky)));

      //htilde(k++) =
    }
  }
}
