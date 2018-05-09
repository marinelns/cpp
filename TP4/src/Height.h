/**
* \file Height.h
* \brief mise en place d'un vecteur de GerstnerWave
*/
#include "Dvector.h"
#include <complex.h>
#include <assert.h>
#include <fstream>
#ifndef HeightH
#define HeightH

/**Classe qui contient l'ensemble des hauteurs calculées
  *dans une boite carrée de taille physique (Lx, Ly)
  *discretisee en (nx, ny) elements
 */
class Height{
  private :
    Dvector vect;/*!< vecteur*/
    double lx;/*!< longueur x*/
    double ly;/*!< longueur y*/
    double nx;/*!< nombre x*/
    double ny;/*!< nombre y*/

  public :
    /*!
    * \brief constructeur par defaut
    */
    Height();

    /*!
    * \brief constructeur avec initialisation du tableau
    * \param l_x, l_y, n_x, n_y
    */
    Height(double l_x, double l_y, double n_x, double n_y);

    /*!
    * \brief constructeur par copie
    * \param h
    */
    Height(const Height & h);

    /*!
    * \brief destructeur
    */
    ~Height();

    /*!
    * \brief Accesseur au tableau des vecteurs
    */
    Dvector getVector() const;

    /*!
    * \brief Accesseur a lx
    */
    double getLx() const;

    /*!
    * \brief Accesseur a ly
    */
    double getLy() const;

    /*!
    * \brief Accesseur a nx
    */
    double getNx() const;

    /*!
    * \brief Accesseur a ny
    */
    double getNy() const;

    void setLx(double l_x);
    void setLy(double l_y);
    void setNx(double n_x);
    void setNy(double n_y);
    void setVector(Dvector vect);

    /*!
    * \brief operateur()
    * \param off
    */
    double& operator() (int off) const;

    /*!
    * \brief operateur d'affectation
    * \param h
    */
    Height& operator=(const Height& h);

};

/*!
* \brief operateur <<
* \param ostream out, h
* \return ostream
*/
std::ostream& operator << (std::ostream &out, const Height &H);

#endif
