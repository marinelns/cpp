/**
* \file main.cpp
* \brief programme test
*/
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>
#include <complex>
#include <string>
#include <sstream>

#include "../src/Ocean.h"
#include "../src/Dvector.h"
#include "../src/Height.h"
#include "../src/WaveModel.h"
#include "../src/GerstnerWaveModel.h"


int main(int argc, char** argv)
{
    // Initialisation des parametres
    fprintf(stderr, "## Initialisation des parametres\n");
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

    // Initialisation du modele de houle
    fprintf(stderr, "## Initialisation du modele de houle\n");
    GerstnerWaveModel gerstner(wind_dir, intensity);

    // Initialisation de l'Ocean
    fprintf(stderr, "## Initialisation de l'ocean\n");
    Ocean ocean(Lx, Ly, nx, ny, t, &gerstner);

    // Initialisation du champ de hauteur
    fprintf(stderr, "## Initialisation du champ de hauteur\n");
    ocean.gl_vertices(4.0);

    // Boucle
    fprintf(stderr, "## Boucle\n");

    int i = 0;

    for (t = 0.0f; t < T; t += dt) {
        ocean.setHauteur(t);
        ocean.compute();

        std::ofstream file("file.txt");
        file << ocean.getHauteur() << endl;
        file.close();
        i++;
    }


    return 0;
}
