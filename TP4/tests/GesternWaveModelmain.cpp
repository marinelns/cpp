#include "../src/GerstnerWaveModel.h"

int main(){
  GerstnerWaveModel g = GerstnerWaveModel(Dvector(2), 6);
  printf("phase :\n" );
  g.getPhii().display(std::cout);
  printf("amplitude :\n" );
  g.getAi().display(std::cout);
}
