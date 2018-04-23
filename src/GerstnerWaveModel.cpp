#include "GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel() : WaveModel() {
  this->nb_ondes = 0;
  this->ondes = nullptr;
}

GerstnerWaveModel::(Dvector dir, Dvector align, double inte, double longu, double ajust, int nb) :
                    WaveModel(Dvector dir, Dvector align, double inte, double longu, double ajust) {
}
