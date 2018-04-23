#include "GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel() : WaveModel() {
  this->nb_ondes = 0;
  this->ondes = new GerstnerWave[1];
}

int main(){
  GerstnerWaveModel tab = GerstnerWaveModel();
  //tab.add(GerstnerWave());

}
