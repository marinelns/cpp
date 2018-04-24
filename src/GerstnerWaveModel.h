#ifndef GerstnerWaveModelH
#define GerstnerWaveModelH

#include "Dvector.h"
#include "WaveModel.h"
#include "GerstnerWave.h"

#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>

class GerstnerWaveModel : public WaveModel{
    protected :
      int nb_ondes;
      vector<GerstnerWave> ondes;

    public :
      //constructeur par defaut
      GerstnerWaveModel();

      //constructeur par copie
      //GerstnerWaveModel(const GerstnerWaveModel& g);

      ~GerstnerWaveModel();

      int size() const;

      vector<GerstnerWave> getTab();

      int getSize() const;

      GerstnerWaveModel add(GerstnerWave nouveau);
};

#endif
