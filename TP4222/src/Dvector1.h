#ifndef DvectorH
#define DvectorH
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <fstream>
#include <complex>
#include <sstream>
#include <assert.h>
#include <math.h>
#include <ctype.h>

typedef union complexe_flottant complexe_flottant;
typedef struct multi_type mult;

class Dvector{
  private:
    mult *tab;
    int taille;

  public:
    Dvector();
    Dvector(int longueur, int valeur);
    Dvector(int longueur);
//     Dvector(Dvector const& autre);
//     Dvector(std::string fichier);
//     ~Dvector();
//     void display(std::ostream& str);
//     int size() const;
//     void fillRandomly();
//     complexe_flottant & operator()(int i)const;
//     Dvector & operator=(const Dvector & v);
//     //Question 3
//     Dvector & operator+=(const Dvector &v);
//     Dvector & operator+=(const double & c);
//     Dvector & operator-=(const Dvector & v);
//     Dvector & operator-=(const double & c);
//     Dvector & operator*=(const Dvector & v);
//     Dvector & operator*=(const double & c);
//     Dvector & operator/=(const Dvector & v);
//     Dvector & operator/=(const double & c);
//     bool operator ==(const Dvector & v);
//
//     //question 6
//     void resize(const int & taille, const double & c);
//
//     //calcule le produit scalaire entre 2 vecteurs
//     double pdt_scalaire(Dvector w);
};

union complexe_flottant{
  double decimal;
  complex<double> complexe;
};

struct multi_type{
  union complexe_flottant comflot;
};

// //Quesion 4
// Dvector operator+(const Dvector & v, const complexe_flottant & c);
// Dvector operator+(const Dvector & v, const Dvector & w);
// Dvector operator+(const double & c, const Dvector & v);
// Dvector operator-(const Dvector & v, const double & c);
// Dvector operator-(const Dvector & v, const Dvector & w);
// Dvector operator-(const double & c, const Dvector & v);
// Dvector operator/(const Dvector & v, const double & c);
// Dvector operator/(const double & c, const Dvector & v);
// Dvector operator*(const Dvector & v, const double & c);
// Dvector operator*(const double & c, const Dvector & v);
// Dvector operator-(const Dvector & v);
//
// //quesion 5
// std::ostream & operator << (std::ostream & Out, const Dvector & v);
// std::ostream & operator >> (std::ostream & Out, const Dvector & v);
//
//
#endif
