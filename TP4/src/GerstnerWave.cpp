#include "GerstnerWave.h"
#include <vector>


GerstnerWave::GerstnerWave(double ampl, double phas, Dvector dir, double freq){
  if(dir.size() != 2) throw Error("la direction doit être un Dvector de dim 2");
  _amplitude = ampl;
  _phase = phas;
  _directionOnde = dir;
  _frequence = freq;
}

GerstnerWave::GerstnerWave(const GerstnerWave& g){
  _amplitude = g.getAmplitude();
  _phase = g.getPhase();
  _directionOnde = Dvector(g.getDirection());
  _frequence = g.getFrequence();
}

GerstnerWave::~GerstnerWave(){}

double GerstnerWave::getAmplitude() const {return _amplitude;}
double GerstnerWave::getPhase() const {return _phase;}
Dvector GerstnerWave::getDirection() const {return _directionOnde;}
double GerstnerWave::getFrequence() const {return _frequence;}

GerstnerWave&GerstnerWave::operator = (const GerstnerWave& g){
  _directionOnde=Dvector();
  memcpy(&_directionOnde, &g.getDirection(), sizeof(Dvector));
  _amplitude = g.getAmplitude();
  _phase = g.getPhase();
  _frequence = g.getFrequence();
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
