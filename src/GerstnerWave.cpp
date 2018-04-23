#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(){
  this->_amplitude = 0;
  this->_phase = 0;
  this->_directionOnde = Dvector();
  this->_frequence = 0;
}

GerstnerWave::GerstnerWave(double ampl, double phas, Dvector dir, double freq){
  this->_amplitude = ampl;
  this->_phase = phas;
  this->_directionOnde = dir;
  this->_frequence = freq;
}

GerstnerWave::GerstnerWave(const GerstnerWave& g){
  this->_amplitude = g._amplitude;
  this->_phase = g._phase;
  this->_directionOnde = Dvector(g._directionOnde);
  this->_frequence = g._frequence;
}

GerstnerWave::~GerstnerWave(){}

double GerstnerWave::getAmplitude() const {return this->_amplitude;}
double GerstnerWave::getPhase() const {return this->_phase;}
Dvector GerstnerWave::getDirection() const {return this->_directionOnde;}
double GerstnerWave::getFrequence() const {return this->_frequence;}

GerstnerWave&GerstnerWave::operator = (const GerstnerWave& g){
  this->_directionOnde=Dvector();
  memcpy(&this->_directionOnde, &g._directionOnde, sizeof(Dvector));
  this->_amplitude = g._amplitude;
  this->_phase = g._phase;
  this->_frequence = g._frequence;
  return *this;
}

double GerstnerWave::operator()(Dvector point, double t){
  double hauteur_vague = _amplitude * cos(_directionOnde.pdt_scalaire(point) - _frequence*t + _phase);
  return hauteur_vague;
}


// int main(){
//   GerstnerWave g = GerstnerWave(5.9, 3, Dvector(2), 6);
//   printf("phase %f\n", g.getPhase());
// }
