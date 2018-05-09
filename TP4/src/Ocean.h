/**
* \file Ocean.h
* \brief mise en place de l'ocean de vectur
*/

#ifndef OceanH
#define OceanH

#include <iostream>
#include <assert.h>
#include "Height.h"
#include "Dvector.h"
#include "WaveModel.h"
#include "PhilipsWaveModel.h"

class Ocean{
  private:
    double Lx, Ly;/*!< longueur x et longueur y*/
    int Nx, Ny;/*!< n x et n y*/
    double t;/*!< t*/
    Height hauteur;/*!< hauteur*/
    WaveModel *model;/*!< model utilise*/
    Dvector vertices;/*!< vecteur de hauteurs*/

  public:
    /*!
    * \brief destructeur
    */
    ~Ocean();

    /*!
    * \brief constructeur
    * \param lx, ly, nx, ny, t, model
    */
    Ocean(double lx, double ly, int nx, int ny, double t, WaveModel* model);

    /*!
    * \Accesseur à la hauteur
    */
    Height getHauteur()const{
      return hauteur;
    }

    void setVectorHauteur(Dvector vecteur){
      hauteur.setVector(vecteur);
    }

    void setHauteur(double haut);

    /*!
    * \brief Permet d'accéder à la hauteur model
    */
    void compute();

    /*!
    * \brief permet de créer un vecteur de hauteurs
    */
    void gl_vertices(double h_init);

    /*!
    * \brief permet de set un model
    */
    void computeset();
};

#endif
