#include "GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel() : WaveModel() {
  this->nb_ondes = 1;
  for(int i = 0; i< nb_ondes; i++){
    ondes.push_back(GerstnerWave(1, 1, Dvector(1),1));
  }
}

vector<GerstnerWave> GerstnerWaveModel::getTab(){
  return this->ondes;
}

int GerstnerWaveModel::getSize() const{
  return nb_ondes;
}

GerstnerWaveModel GerstnerWaveModel::add(GerstnerWave nouveau){
  ondes.push_back(nouveau);
  nb_ondes = nb_ondes +1;
  return *this;
}

GerstnerWaveModel::~GerstnerWaveModel(){
  ondes.clear();
}

int GerstnerWaveModel::size() const{
  return nb_ondes;
}

// int main(){
//   GerstnerWaveModel tab = GerstnerWaveModel();
//   GerstnerWave g = GerstnerWave(5.9, 3, Dvector(2), 6);
//   printf("phase %f\n", g.getPhase());
//   printf("phase %f \n", tab.getTab()[0].getPhase());
//
//   tab.add(g);
//   printf("phase de g %f \n", tab.getTab()[1].getPhase());
//   printf("la taille du vecteur est maintenant %i\n", tab.getSize());
// }
