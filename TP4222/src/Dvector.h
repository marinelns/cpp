#ifndef DvectorH
#define DvectorH
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <fstream>
#include <complex>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <assert.h>
#include <math.h>
#include <complex.h>
#undef I
#define J _Complex_I
#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif


class Dvector{

  public:
    vector< complex<double> > tab;
    int taille;
    Dvector();
    Dvector(int longueur, int valeur);
    //Dvector(int longueur, complex<double> valeur);
    Dvector(int longueur);
    Dvector(Dvector const& autre);
    Dvector(std::string fichier);
    ~Dvector();
    void display(std::ostream& str);
    int size() const;
    void fillRandomly();
    complex<double> & operator()(int i);
    Dvector & operator=(const Dvector & v);
    //Question 3
    Dvector & operator+=(const Dvector &v);
    Dvector & operator+=(const double & c);
    Dvector & operator-=(const Dvector & v);
    Dvector & operator-=(const double & c);
    Dvector & operator*=(const Dvector & v);
    Dvector & operator*=(const double & c);
    Dvector & operator/=(const Dvector & v);
    Dvector & operator/=(double c);
    bool operator ==(const Dvector & v);

    // //question 6
    // void resize(const int & taille, const double & c);

    //calcule le produit scalaire entre 2 vecteurs
    complex<double> pdt_scalaire(Dvector w);

    // // LAB 4 Question 2
    //Permet de caculer FFT
    Dvector FFT();
    void conj();
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
