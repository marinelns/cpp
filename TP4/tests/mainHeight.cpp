#include "../src/Height.h"

int main(){
  Height h = Height(2,2,2,2);
  std::ofstream file("file.txt");
  file << h << endl;
}
