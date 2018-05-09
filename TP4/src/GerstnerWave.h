/**
* \file GerstnerWave.h
* \brief mise en place des vecteurs avec la hauteur Gestern
*/

#ifndef GerstnerWaveH
#define GerstnerWaveH
#include "Dvector.h"
#include <cmath>

class GerstnerWave{
  protected :
    double _amplitude;/*!< Amplitude */
    double _phase;/*!< Phase */
    Dvector _directionOnde; /*!< Direction onde */
    double _frequence;/*!< Frequence */

  public :
    /*!
    * \brief constructeur avec initialisation des paramètres
    * \param ampl : amplitude initiale du vecteur
    * \param phas : phase initiale du vecteur
    * \param dir : vecteur initiale
    * \param freq : frequence initiale
    */
    GerstnerWave(double ampl, double phas, Dvector dir, double freq);

    /*!
    * \brief constructeur par copie
    * \param g : GerstnerWave
    */
    GerstnerWave(const GerstnerWave& g);


    /*!
    * \brief destructeur
    */
    ~GerstnerWave();

    /*!
    * \brief accesseur pour l'amplitude
    */
    double getAmplitude() const;

    /*!
    * \brief accesseur pour la phase
    */
    double getPhase() const;

    /*!
    * \brief accesseur pour la direction
    */
    Dvector getDirection() const;

    /*!
    * \brief accesseur pour la fréquence
    */
    double getFrequence() const;


    /*!
    * \brief operateur =
    * \param g
    *\return GerstnerWave
    */
    GerstnerWave& operator = (const GerstnerWave& g);

    /*!
    * \brief operateur permettant d'acceder a la classe comme un foncteur
    * \param x, y, t
    * \return double
    */
    double operator()(double x, double y, double t) const;

    /*!
    * \brief operateur permettant d'acceder a la classe comme un foncteur
    * \param x, y, t
    * \return double
    */
    double operator()(double x, double y, double t);
};
#endif
