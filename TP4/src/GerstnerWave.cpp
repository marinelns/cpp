/**
* \file GerstnerWave.c
* \brief mise en place des vecteurs avec la hauteur Gestern
*/
#include "GerstnerWave.h"
#include <vector>
#include "Dvector.h"


GerstnerWave::GerstnerWave(double ampl, double phas, Dvector dir, double freq){
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
  _amplitude = g.getAmplitude();
  _phase = g.getPhase();
  _frequence = g.getFrequence();
  return *this;
}


double GerstnerWave::operator()(double x, double y, double t) const{
  Dvector x_h = Dvector(2);
  x_h(1) = x;
  x_h(1) = y;
  double prod = x_h.pdt_scalaire(_directionOnde);
  double hauteur_vague = _amplitude * cos(prod - _frequence*t + _phase);
  return hauteur_vague;
}

double GerstnerWave::operator()(double x, double y, double t){
  Dvector x_h = Dvector(2);
  x_h(1) = x;
  x_h(1) = y;
  double prod = _directionOnde.pdt_scalaire(x_h);
  double hauteur_vague = _amplitude * cos(prod - _frequence*t + _phase);
  return hauteur_vague;
}
