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
    fprintf(stdout, "Initialisation des parametres\n");
    double Lx = 5.0f;
    double Ly = 5.0f;
    int nx = 64;
    int ny = 64;

    double t = 0.0f;
    double T = 6.0f;
    double dt = 0.1f;

    Dvector wind(2);
    fill(wind, 0.8);
    double intensity = 0.9f;

    // Initialisation du modele de houle
    fprintf(stdout, "Initialisation du modele de houle\n");
    PhilipsWaveModel philips(wind, intensity);

    // Initialisation de l'Ocean
    fprintf(stdout, "Initialisation de l'ocean\n");
    Ocean ocean(Lx, Ly, nx, ny, t, &philips);

    // Initialisation du champ de hauteur
    fprintf(stdout, "Initialisation du champ de hauteur\n");
    ocean.gl_vertices(4.0);

    // Boucle
    fprintf(stdout, "Boucle\n");

    int i = 0;

    for (t = 0.0f; t < T; t += dt) {
        ocean.setHauteur(t);
        ocean.compute(t);

        std::ofstream file("file.txt");
        file << ocean.getHauteur() << endl;
        file.close();
        i++;
    }


    return 0;
}
