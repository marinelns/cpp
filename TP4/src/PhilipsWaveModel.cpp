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

  for(int n = -N/2; n< N/2; n++){
    for(int m = -M/2; m< M/2; m++){
      int kx = PIDOUBLE*n/N;
      int ky = PIDOUBLE*m/M;
      complex<double> premiere_part = cexp(sqrt(sqrt(kx*kx+ky*ky)*t)*PIDOUBLE)*(1/sqrt(2));
      premiere_part *= (ksi)*(sqrt(houle(kx, ky)));

      complex<double> seconde_part = cexp(-sqrt(sqrt(kx*kx+ky*ky)*t)*PIDOUBLE)*(1/sqrt(2));
      seconde_part *= conj(ksi)*(sqrt(houle(kx, ky)));

      htilde(l++) = premiere_part + seconde_part;
    }
  }

  GeneriqueVector vect = GeneriqueVector(taille);
  vect = htilde.ifft();
  Dvector vector = Dvector(taille);
  for(int i = 0; i<taille; i++){
    vector(i) = real(vect(i));
  }
  return vector;
}

double PhilipsWaveModel::houle(double kx, double ky){
  double prod_scal = kx*_direction(1) + ky*_direction(2);
  double exponentielle = exp(-1/((kx*kx + ky*ky)*(_intensite*_intensite)));
  double retour = A*exponentielle*prod_scal/(kx*kx+ky*ky);
  return retour;
}

double PhilipsWaveModel::operator()(double x, double y, double t){
  return 0;
}
