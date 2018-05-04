#ifndef GerstnerWaveModelH
#define GerstnerWaveModelH

#include "Dvector.h"
#include "WaveModel.h"
#include "GerstnerWave.h"
#include "Dvector.h"

#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>

class GerstnerWaveModel : public WaveModel{
    private:
      int nb_ondes;
      std::vector<Dvector> Ki;  //vecteurs d'ondes
      Dvector Ai; //amplitudes
      Dvector wi; //frequences
      Dvector phii; //phases

    public:
      //constructeur
      GerstnerWaveModel(Dvector _direction, double _intensite);
      //GerstnerWaveModel(const GerstnerWaveModel& g);
      ~GerstnerWaveModel();

      //getter
      int getNb_ondes();
      std::vector<Dvector> getKi() {return Ki;}
      Dvector getAi() {return Ai;}
      Dvector getWi() {return wi;}
      Dvector getPhii() {return phii;}

};

#endif
