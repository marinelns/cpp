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
  double t = 5.0f;

  Dvector direction = Dvector(2);

  Dvector alignement = Dvector(2,0.5);
  double intensite = 0.5f;
<<<<<<< HEAD
  //double longueur = 1;
  //double ajustement = 0.8;

  GerstnerWaveModel *wave = new GerstnerWaveModel(direction,intensite);
  ocean = new Ocean(Lx,Ly,nx,ny,t,wave);

  /** @todo Initialiser du modèle*/
  ocean->generateHeight(Ly);
  ocean->gl_vertices(4.0);

=======
  double longueur = 1;
  double ajustement = 0.8;

  GerstnerWaveModel *wave = new GerstnerWaveModel(direction,intensite);
  ocean = new Ocean(Lx,Ly,nx,ny,t,wave);

  /** @todo Initialiser du modèle*/
  ocean->generateHeight(Ly);
  //ocean->gl_vertices();

  /** @todo Initialiser du champ de hauteur */
  //ocean.gl_vertices(4.0);

  /** @todo Initialiser de l'océan */
  //ocean = new Ocean(Lx, Ly, nx, ny, t, &gerstner);

>>>>>>> 35c63e8184a10959b6c08e3a1b0df623d9f7dcd1
  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;
  return 0;

}
