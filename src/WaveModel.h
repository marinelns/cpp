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
    ~WaveModel();
    //operateur d'affectation
    WaveModel& operator = (const WaveModel& w);
    //accesseurs
    double getDirection();
    double getAlignement();
    double getIntensite();
    double getLongueur();
    double getAjustement();

    //manque le foncteur

};
#endif
