#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */

#include "window.hxx"

int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */

  double Lx = 5.0f;
  double Ly = 5.0f;
  int nx = 64;
  int ny = 64;

  double t = 0.0f;
  double T = 5.0f;
  double dt = 0.1f;

  Dvector wind_dir(2);
  fill(wind_dir, 0.3);
  double intensity = 0.5f;

  /** @todo Initialiser du modèle*/
  GerstnerWaveModel gerstner(wind_dir, intensity);

  /** @todo Initialiser du champ de hauteur */
  ocean.gl_vertices(4.0);

  /** @todo Initialiser de l'océan */
  Ocean ocean(Lx, Ly, nx, ny, t, &gerstner);
  
  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
