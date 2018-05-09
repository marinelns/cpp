/**
* \file GeneriqueVector.h
* \brief mise en place de vecteurs complex
*/

#ifndef GeneriqueVectorH
#define GeneriqueVectorH
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <fstream>
#include <complex>
#include <valarray>
#include <math.h>
#include <complex.h>
#include <sstream>
#include <assert.h>
const double PI = 3.14159265359;



class GeneriqueVector{
  private:
    int taille;

  public:
    complex<double> *tab;
    GeneriqueVector();
    GeneriqueVector(int longueur, complex<double> valeur);
    GeneriqueVector(int longueur);
    GeneriqueVector(GeneriqueVector const& autre);
    GeneriqueVector(std::string fichier);
    ~GeneriqueVector();
    void display(std::ostream& str);
    int size() const;
    void fillRandomly();
    complex<double> & operator()(int i)const;
    GeneriqueVector & operator=(const GeneriqueVector & v);
    //Question 3
    GeneriqueVector & operator+=(const GeneriqueVector &v);
    GeneriqueVector & operator+=(const double & c);
    GeneriqueVector & operator-=(const GeneriqueVector & v);
    GeneriqueVector & operator-=(const double & c);
    GeneriqueVector & operator*=(const GeneriqueVector & v);
    GeneriqueVector & operator*=(const double & c);
    GeneriqueVector & operator/=(const GeneriqueVector & v);
    GeneriqueVector & operator/=(const double & c);
    bool operator ==(const GeneriqueVector & v);

    //question 6
    void resize(const int & taille, const double & c);

    //calcule le produit scalaire entre 2 vecteurs
    complex<double> pdt_scalaire(GeneriqueVector w);

    //LAB4
    GeneriqueVector fft();
    GeneriqueVector conjugue();
    GeneriqueVector conjuguedivise();
    GeneriqueVector ifft();
  };
//Quesion 4
GeneriqueVector operator+(const GeneriqueVector & v, const double & c);
GeneriqueVector operator+(const GeneriqueVector & v, const GeneriqueVector & w);
GeneriqueVector operator+(const double & c, const GeneriqueVector & v);
GeneriqueVector operator-(const GeneriqueVector & v, const double & c);
GeneriqueVector operator-(const GeneriqueVector & v, const GeneriqueVector & w);
GeneriqueVector operator-(const double & c, const GeneriqueVector & v);
GeneriqueVector operator/(const GeneriqueVector & v, const double & c);
GeneriqueVector operator/(const double & c, const GeneriqueVector & v);
GeneriqueVector operator*(const GeneriqueVector & v, const double & c);
GeneriqueVector operator*(const double & c, const GeneriqueVector & v);
GeneriqueVector operator-(const GeneriqueVector & v);
//quesion 5
std::ostream & operator << (std::ostream & Out, const GeneriqueVector & v);
std::ostream & operator >> (std::ostream & Out, const GeneriqueVector & v);
#endif
