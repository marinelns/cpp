#ifndef GerstnerWaveH
#define GerstnerWaveH

#include "Dvector.h"
#include <cmath>

//classe dont chaque instance contient la definition d'une onde differente

class GerstnerWave{
  private :
    double _amplitude;
    double _phase;
    Dvector _directionOnde;
    double _frequence;

  public :
    /*constructeur par défaut*/
    GerstnerWave();
    /*constructeur avec initialisation des paramètres*/
    GerstnerWave(double ampl, double phas, Dvector dir, double freq);
    /*constructeur par copie*/
    GerstnerWave(const GerstnerWave& g);
    /*destructeur*/
    ~GerstnerWave();
    /*accesseurs*/
    double getAmplitude() const;
    double getPhase() const;
    Dvector getDirection() const;
    double getFrequence() const;
    /*operateur d'affectation*/
    GerstnerWave& operator = (const GerstnerWave& g);
    /*operateur permettant d'acceder a la classe comme un foncteur*/
    double operator()(Dvector point, double t);
};
#endif
