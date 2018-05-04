#ifndef WaveModelH
#define WaveModelH

#include "Dvector.h"
#include "Height.h"

//WaveModel est une classe abstraite  qui servira aux différents modèles de vague développés

class WaveModel{
  protected :
    Dvector _direction;   //direction du vent
    Dvector _alignement;  //alignement moyen des vagues
    double _intensite;
    double _longueur; //longueur d'onde moyenne
    double _ajustement; //ajustement de la hauteur des vagues

  public :
    //constructeur par defaut
    WaveModel();
    //constructeur avec valeurs
    WaveModel(Dvector dir, Dvector align, double inte, double longu, double ajust);
    //constructeur par copie
    WaveModel(const WaveModel & w);
    //destructeur
    virtual ~WaveModel();
    //operateur d'affectation
    virtual WaveModel& operator = (const WaveModel& w);
    //accesseurs
    virtual Dvector getDirection() const;
    virtual Dvector getAlignement() const;
    virtual double getIntensite() const;
    virtual double getLongueur() const;
    virtual double getAjustement() const;

    virtual double operateur(double x, double y, double t);
    //manque le foncteur

};
#endif
