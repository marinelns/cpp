#include "GerstnerWaveModel.h"
#include <math.h>

n = 10;
GerstnerWaveModel::GerstnerWaveModel(Dvector _direction, double _intensite):
  WaveModel(_direction, 0.0f, _intensite, 0.0f, 0.0f), nb_ondes(n), Ai(Dvector(n)), wi(Dvector(n)), phii(Dvector(n))
  {
    for (int i = 0; i < nb_ondes; i++){
      Ki.push_back(Dvector(2));
      Ki[i] = _direction;
      Ai(i) = _intensite;
      wi(i) = sqrt(norm(Ki[i]*9.81));  //w(k)^2=gk
      phii(i) = M_PI;
    }
  }
GerstnerWaveModel::~GerstnerWaveModel(){
}

std::vector<Dvector> getKi() {return Ki;}
Dvector getAi() {return Ai;}
Dvector getWi() {return wi;}
Dvector getPhii() {return phii;}

 // int main(){
 //    GerstnerWaveModel tab = GerstnerWaveModel();
 //   GerstnerWave g = GerstnerWave(5.9, 3, Dvector(2), 6);
 //   printf("phase %f\n", g.getPhase());
 //   printf("phase %f \n", tab.getTab()[0].getPhase());
 //
 //   tab.add(g);
 //   printf("phase de g %f \n", tab.getTab()[1].getPhase());
 //   printf("la taille du vecteur est maintenant %i\n", tab.getSize());
 // }
