/**
* \file PhilipsWaveModel.h
* \brief mise en place de vecteurs de philips
*/

#ifndef PhilipsWaveModel_HPP
#define PhilipsWaveModel_HPP

#include "Dvector.h"
#include "WaveModel.h"
#include "GeneriqueVector.h"
#include <complex.h>
#include <assert.h>
#include <complex>
#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <math.h>
#include <cstring>



class PhilipsWaveModel : public WaveModel{
  private:
    double A;/*!< A*/
    int N, M;/*!< N, M*/
    complex<double> ksi;/*!< ksi*/

  public:
    /*!
    * \brief destructeur
    */
    ~PhilipsWaveModel();

    /*!
    * \brief constructeur
    * \param direction du vent, intensité
    */
    PhilipsWaveModel(Dvector vent_direction, double intensite);

    /*!
    * \brief operator ();
    */
    double operator()(double x, double y, double t);
    double operator()(double x, double y, double t)const;
    Dvector operator()(double t);

    /*!
    * \brief permet de calculer la houle
    * \param kx, ky
    */
    double houle(double kx, double ky);
};

#endif
