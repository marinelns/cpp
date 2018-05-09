/**
* \file WaveModel.cpp
* \brief mise en place de la classe Wave model qui permet de
* créer la classe philips et gerstern
*/
#include "WaveModel.h"

WaveModel::WaveModel(){
  this->_direction = Dvector();
  this->_alignement = Dvector();
  this->_intensite = 0;
  this->_longueur = 0;
  this->_ajustement = 0;
}

WaveModel::WaveModel(Dvector dir, Dvector align, double inte, double longu, double ajust){
  this->_direction = dir;
  this->_alignement = align;
  this->_intensite = inte;
  this->_longueur = longu;
  this->_ajustement = ajust;
}

WaveModel::WaveModel(const WaveModel & w){
  this->_direction = Dvector(w._direction);
  this->_alignement = Dvector(w._alignement);
  this->_intensite = w._intensite;
  this->_longueur = w._longueur;
  this->_ajustement = w._longueur;
}

WaveModel::~WaveModel(){

}

WaveModel& WaveModel::operator = (const WaveModel& w){
  this->_direction = Dvector();
  this->_alignement = Dvector();
  memcpy(&this->_direction, &w._direction, sizeof(Dvector));
  memcpy(&this->_alignement, &w._alignement, sizeof(Dvector));
  this->_intensite = w._intensite;
  this->_longueur = w._longueur;
  this->_ajustement = w._ajustement;
}

Dvector WaveModel::getDirection() const {return _direction;}
Dvector WaveModel::getAlignement() const {return _alignement;}
double WaveModel::getIntensite() const {return _intensite;}
double WaveModel::getLongueur() const {return _longueur;}
double WaveModel::getAjustement() const {return _ajustement;}

Dvector WaveModel::operator () (double t){
}
