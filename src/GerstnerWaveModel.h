#ifndef GerstnerWaveModelH
#define GerstnerWaveModelH

#include "Dvector.h"
#include "WaveModel.h"
#include "GerstnerWave.h"

#include <list>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>

class GerstnerWaveModel : public WaveModel{
  public :
    int nb_ondes;
    GerstnerWave *ondes;

    //constructeur par defaut
    GerstnerWaveModel();
    //constructeur avec initialisation des parametres
    //GerstnerWaveModel(Dvector dir, Dvector align, double inte, double longu, double ajust, int nb);
    //constructeur par copie
    GerstnerWaveModel(const GerstnerWaveModel& g);
    //destructeur
    ~GerstnerWaveModel();
};

#endif
