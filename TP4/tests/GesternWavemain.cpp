#include "../src/GerstnerWave.h"

int main(){
  GerstnerWave g = GerstnerWave(5.9, 3, Dvector(2), 6);
  printf("phase %f\n", g.getPhase());
}
