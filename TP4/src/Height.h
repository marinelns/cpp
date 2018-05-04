#include "Dvector.h"
#include <complex.h>
#ifndef HeightH
#define HeightH

/**Classe qui contient l'ensemble des hauteurs calculées
  *dans une boite carrée de taille physique (Lx, Ly)
  *discretisee en (nx, ny) elements
 */
class Height{
  private :
    Dvector vect;
    double lx;
    double ly;
    double nx;
    double ny;

  public :
    //constructeur par defaut
    Height();
    //constructeur avec initialisation du tableau
    Height(double l_x, double l_y, double n_x, double n_y);
    //constructeur par copie
    Height(const Height & h);
    //destructeur
    ~Height();
    //Accesseur au tableau des vecteurs
    Dvector getVector() const;
    //Accesseur a lx
    double getLx() const;
    //Accesseur a ly
    double getLy() const;
    //Accesseur a nx
    double getNx() const;
    //Accesseur a ny
    double getNy() const;

    void setLx(double l_x);
    void setLy(double l_y);
    void setNx(double n_x);
    void setNy(double n_y);
    void setVector(Dvector vect);
    double operator() (int off);
    //operateur d'affectation
    Height& operator=(const Height& h);

};

#endif
