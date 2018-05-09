/**
* \file GerstnerWaveModel.h
* \brief mise en place d'un vecteur de GerstnerWave
*/
#ifndef GerstnerWaveModelH
#define GerstnerWaveModelH

#include "Dvector.h"
#include "WaveModel.h"
#include "GerstnerWave.h"
#include "Dvector.h"

#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>

class GerstnerWaveModel : public WaveModel{
    private:
      int nb_ondes;
      std::vector<Dvector> Ki;  /*!< vecteurs d'ondes*/
      Dvector Ai; /*!< amplitudes*/
      Dvector wi; /*!< frequences*/
      Dvector phii; /*!< phases*/

    public:
      /*!
      * \brief constructeur
      * \param _direction : Direction
      * \param _intensite : intensite
      */
      GerstnerWaveModel(Dvector _direction, double _intensite);

      /*!
      * \brief Destructeur
      */
      ~GerstnerWaveModel();

      /*
      *\brief Accesseur aux nb d'ondes
      */
      int getNb_ondes();

      /*
      *\brief Accesseur à ki
      */
      std::vector<Dvector> getKi() {return Ki;}

      /*
      *\brief Accesseur à Ai
      */
      Dvector getAi() {return Ai;}

      /*
      *\brief Accesseur à wi
      */
      Dvector getWi() {return wi;}

      /*
      *\brief Accesseur à phii
      */
      Dvector getPhii() {return phii;}

      /*
      * \brief Operatur ()
      * \param x, y, t
      */
      double operator()(double x, double y, double t);
      double operator()(double x, double y, double t)const;

};

#endif
