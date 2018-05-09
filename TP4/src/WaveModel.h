/**
* \file WaveModel.h
* \brief mise en place de la classe Wave model qui permet de
* créer la classe philips et gerstern
*/

#ifndef WaveModelH
#define WaveModelH

#include "Dvector.h"
#include "Height.h"

//WaveModel est une classe abstraite  qui servira aux différents modèles de vague développés

class WaveModel{
  protected :
    Dvector _direction; /*!< direction du vent*/
    Dvector _alignement; /*!< alignement moyen des vagues*/
    double _intensite; /*!< intensite */
    double _longueur; /*!< longueur d'onde moyenne*/
    double _ajustement; /*!< ajustement de la hauteur des vagues*/

  public :
    /*!
    * \brief constructeur par defaut
    */
    WaveModel();

    /*!
    * \brief constructeur avec valeurs
    */
    WaveModel(Dvector dir, Dvector align, double inte, double longu, double ajust);

    /*!
    * \brief constructeur par copie
    * \param w
    */
    WaveModel(const WaveModel & w);

    /*!
    * \brief destructeur
    */
    virtual ~WaveModel();

    /*!
    * \brief operateur d'affectation =
    * \param w
    */
    virtual WaveModel& operator = (const WaveModel& w);

    /*!
    * \brief accesseur direction
    */
    virtual Dvector getDirection() const;

    /*!
    * \brief accesseur alignement
    */
    virtual Dvector getAlignement() const;

    /*!
    * \brief accesseur intensite
    */
    virtual double getIntensite() const;

    /*!
    * \brief accesseur longueur
    */
    virtual double getLongueur() const;

    /*!
    * \brief accesseur ajustement
    */
    virtual double getAjustement() const;

    /*!
    * \brief operateur()
    */
    virtual double operator()(double x, double y, double t)const=0;

    /*!
    * \brief operateur()
    */
    virtual double operator()(double x, double y, double t)=0;

    /*!
    * \brief operateur()
    */
    virtual Dvector operator() (double t)const;
    virtual Dvector operator() (double t);

};
#endif
