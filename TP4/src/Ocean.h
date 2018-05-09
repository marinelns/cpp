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
#include "GerstnerWaveModel.h"
#include "PhilipsWaveModel.h"

class Ocean{
  private:
    double Lx, Ly;/*!< longueur x et longueur y*/
    int Nx, Ny;/*!< n x et n y*/
    double t;/*!< t*/
    Height hauteur;/*!< hauteur*/
    WaveModel *model;/*!< model utilise*/
    double* vertices;/*!< vecteur de hauteurs*/

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

    void setHauteur(double haut);

    void generateHeight(double h);

    /*!
    * \brief Permet d'accéder à la hauteur model
    */
    Height compute(double t);

    /*!
    * \brief permet de créer un vecteur de hauteurs
    */
    void gl_vertices(double h_init);

    /*!
    * \brief permet de set un model
    */
    void computeset();

    double get_lx(); /*!< récupère la taille de l'océan suivant x*/
    double get_ly(); /*!< récupère la taille de l'océan suivant y*/
    double getNx(); /*!< récupère la taille discrétisée de l'océan suivant x*/
    double getNy(); /*!< récupère la taille discrétisée de l'océan suivant y*/


    void main_computation(double t);

    /** Initialise la grille dans la direction x
     *  param[in]   y        abscisse de la colonne à parcourir
     *  param[out]  vertices buffer contenant les coordonnées des noeuds
     */
    void init_gl_VertexArrayX(const int y, double* const vertices) const;

    /** Initialise la grille dans la direction y
     *  param[in]   x        abscisse de la ligne à parcourir
     *  param[out]  vertices buffer contenant les coordonnées des noeuds
     */
    void init_gl_VertexArrayY(const int x, double* const vertices) const;

    /** Convertit le champs de hauteur en tabeau directement utilisable
     *  par OpenGL pour un y donné
     *  param[in]   y        abscisse de la colonne à parcourir
     *  param[out]  vertices buffer contenant les valeurs aux noeuds
     */
    void gl_vertexArrayX(const int y, double* const vertices) const;

    /** Convertit le champs de hauteur en tabeau directement utilisable
     *  par OpenGL pour un x donné
     *  param[in]   x        abscisse de la ligne à parcourir
     *  param[out]  vertices buffer contenant les valeurs aux noeuds
     */
    void gl_vertexArrayY(const int x, double* const vertices) const;
};

#endif
