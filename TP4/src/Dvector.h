/**
* \file Dvector.h
* \brief mise en place des vecteurs
*/

#ifndef DvectorH
#define DvectorH
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <assert.h>
#include <math.h>
#include "GeneriqueVector.h"


class Dvector{
  private:
    double *tab;
    int taille;

  public:
    /*!
    * \brief Constructeur
    */
    Dvector();

    /*!
    * \brief Constructeur
    * \param longueur : longueur initiale du vecteur
    * \param valeur : valeur initiale du vecteur
    */
    Dvector(int longueur, double valeur);

    /*!
    * \brief Constructeur
    * \param longueur : longueur initiale du vecteur
    */
    Dvector(int longueur);

    /*!
    * \brief Constructeur
    * \param autre : Dvecteur initiale
    */
    Dvector(Dvector const& autre);

    /*!
    * \brief Permet d'écrire dans un dvecteur dans un fichier
    * \param fichier : fichier dans lequel on écrit
    */
    Dvector(std::string fichier);

    /*!
    * \brief Destructeur
    */
    ~Dvector();

    /*!
    *\brief Permet de sortir le Dvector
    * \param str : zone d'ecriture
    */
    void display(std::ostream& str);

    /*!
    * \brief Permet d'accéder à la longueur d'un vecteur
    */
    int size() const;

    /*!
    * \brief Permet de remplir le vecteur de manière random
    */
    void fillRandomly();

    /*!
    * \brief Operator ()
    * \param i, un entier qui ne doit pas etre plus grand que la taille du vecteur
    */
    double & operator()(int i)const;

    /*!
    * \brief Operator =
    * \param v
    * \return Dvector
    */
    Dvector & operator=(const Dvector & v);

    /*!
    * \brief Operator +=
    * \param v
    * \return Dvector
    */
    Dvector & operator+=(const Dvector &v);

    /*!
    * \brief Operator +=
    * \param c
    * \return Dvector
    */
    Dvector & operator+=(const double & c);

    /*!
    * \brief Operator -=
    * \param v
    * \return Dvector
    */
    Dvector & operator-=(const Dvector & v);

    /*!
    * \brief Operator -=
    * \param c
    * \return Dvector
    */
    Dvector & operator-=(const double & c);

    /*!
    * \brief Operator *=
    * \param v
    * \return Dvector
    */
    Dvector & operator*=(const Dvector & v);

    /*!
    * \brief Operator *=
    * \param c
    * \return Dvector
    */
    Dvector & operator*=(const double & c);

    /*!
    * \brief Operator /=
    * \param v
    * \return Dvector
    */
    Dvector & operator/=(const Dvector & v);

    /*!
    * \brief Operator /=
    * \param c
    * \return Dvector
    */
    Dvector & operator/=(const double & c);

    /*!
    * \brief Operator ==
    * \param v
    * \return bool
    */
    bool operator ==(const Dvector & v);

    /*!
    * \brief Permet de redimensionner notre vecteur avec une constante
    * \param taille : taille du nouveau vecteur
    * \param c : constante a ajouter à la fin du vecteur
    */
    void resize(const int & taille, const double & c);

    /*!
    * \brief permet de faire le produit scalaire de deux vecteurs
    * \param w
    * \return double
    */
    double pdt_scalaire(Dvector w);


};

/*!
* \brief Operator + entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator+(const Dvector & v, const double & c);

/*!
* \brief Operator + entre deux vecteurs
* \param v, w
* \return Dvector
*/
Dvector operator+(const Dvector & v, const Dvector & w);

/*!
* \brief Operator + entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator+(const double & c, const Dvector & v);

/*!
* \brief Operator - entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator-(const Dvector & v, const double & c);

/*!
* \brief Operator - entre deux vecteurs
* \param v, w
* \return Dvector
*/
Dvector operator-(const Dvector & v, const Dvector & w);

/*!
* \brief Operator - entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator-(const double & c, const Dvector & v);

/*!
* \brief Operator / entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator/(const Dvector & v, const double & c);

/*!
* \brief Operator / entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator/(const double & c, const Dvector & v);

/*!
* \brief Operator * entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator*(const Dvector & v, const double & c);

/*!
* \brief Operator * entre un vecteur et une constante
* \param v, c
* \return Dvector
*/
Dvector operator*(const double & c, const Dvector & v);

/*!
* \brief Operator -
* \param v
* \return Dvector
*/
Dvector operator-(const Dvector & v);

/*!
* \brief Permet d'écrire un vecteur
* \param ostream, v
* \return ostream
*/
std::ostream & operator << (std::ostream & Out, const Dvector & v);

/*!
* \brief Permet d'écrire un vecteur sur un ostream
* \param ostream, v
* \return ostream
*/
std::ostream & operator >> (std::ostream & Out, const Dvector & v);

/*!
* \brief Permet de calculer la norme d'un vecteur
* \param v
* \return double
*/
double norm(const Dvector &v);

/*!
* \brief Permet de remplir un vecteur
* \param v, vec
* \return Dvector
*/
Dvector& fill(Dvector& vec, double v);


#endif
