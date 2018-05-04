#include "GerstnerWaveModel.h"
#include <math.h>
#include <cmath>


int n = 10;
GerstnerWaveModel::GerstnerWaveModel(Dvector _direction, double _intensite):
  WaveModel(_direction, 0.0f, _intensite, 0.0f, 0.0f), nb_ondes(n), Ai(Dvector(n)), wi(Dvector(n)), phii(Dvector(n))
  {
    double f;
    for (int i = 0; i < nb_ondes; i++){
      f = rand()/double(RAND_MAX);
      Ki.push_back(Dvector(2));
      Ki[i] = _direction + f;
      Ai(i) = _intensite;
      wi(i) = sqrt(norm(Ki[i])*9.81);  //w(k)^2=gk
      phii(i) = M_PI;
    }
  }

  double GerstnerWaveModel::operator()(double x, double y, double t){
    GerstnerWave* waves[n];
    double somme = 0;
    for(int i=0; i>n; i++){
      waves[i] = new GerstnerWave(Ai(i), wi(i), Ki[i], phii(i));
      somme += (*waves[i])(x,y,t);
    }
    return somme;
  }

// GerstnerWaveModel::~GerstnerWaveModel(){
// }

 int main(){
   GerstnerWaveModel g = GerstnerWaveModel(Dvector(2), 6);
   printf("phase :\n" );
   g.getPhii().display(std::cout);
   printf("amplitude :\n" );
   g.getAi().display(std::cout);
 }
