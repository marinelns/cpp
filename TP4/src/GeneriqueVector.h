#ifndef DvectorH
#define DvectorH
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
#include <fstream>



class Dvector{
  private:
    int taille;

  public:
    complex<double> *tab;
    Dvector();
    Dvector(int longueur, complex<double> valeur);
    Dvector(int longueur);
    Dvector(Dvector const& autre);
    Dvector(std::string fichier);
    ~Dvector();
    void display(std::ostream& str);
    int size() const;
    void fillRandomly();
    complex<double> & operator()(int i)const;
    Dvector & operator=(const Dvector & v);
    //Question 3
    Dvector & operator+=(const Dvector &v);
    Dvector & operator+=(const double & c);
    Dvector & operator-=(const Dvector & v);
    Dvector & operator-=(const double & c);
    Dvector & operator*=(const Dvector & v);
    Dvector & operator*=(const double & c);
    Dvector & operator/=(const Dvector & v);
    Dvector & operator/=(const double & c);
    bool operator ==(const Dvector & v);

    //question 6
    void resize(const int & taille, const double & c);

    //calcule le produit scalaire entre 2 vecteurs
    complex<double> pdt_scalaire(Dvector w);

    //LAB4
    Dvector fft();
    Dvector conjugue();
    Dvector conjuguedivise();
    Dvector ifft();
  };
//Quesion 4
Dvector operator+(const Dvector & v, const double & c);
Dvector operator+(const Dvector & v, const Dvector & w);
Dvector operator+(const double & c, const Dvector & v);
Dvector operator-(const Dvector & v, const double & c);
Dvector operator-(const Dvector & v, const Dvector & w);
Dvector operator-(const double & c, const Dvector & v);
Dvector operator/(const Dvector & v, const double & c);
Dvector operator/(const double & c, const Dvector & v);
Dvector operator*(const Dvector & v, const double & c);
Dvector operator*(const double & c, const Dvector & v);
Dvector operator-(const Dvector & v);
//quesion 5
std::ostream & operator << (std::ostream & Out, const Dvector & v);
std::ostream & operator >> (std::ostream & Out, const Dvector & v);
#endif
