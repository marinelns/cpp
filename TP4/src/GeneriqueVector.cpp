#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <fstream>
#include "GeneriqueVector.h"
#include <sstream>
#include <assert.h>
const double PI = 3.14159265359;

GeneriqueVector::GeneriqueVector(GeneriqueVector const& autre){
  int taillAutre = autre.taille;
  tab = new complex<double>[taillAutre];
  taille = taillAutre;
  for(int i = 0; i< taille; i++){
    tab[i] = autre.tab[i];
  }
}

GeneriqueVector::GeneriqueVector()
{
  int longueur = 0;
  (complex<double>) *tab;
  tab = ((complex<double>*) malloc(longueur * sizeof(complex<double>)));
  this->tab = tab;
  this->taille = longueur;
}

GeneriqueVector::GeneriqueVector(int longueur, complex<double> valeur)
{
  (complex<double>) *tab;
  tab = ((complex<double>*) malloc(longueur * sizeof(complex<double>)));
  for(int i = 0; i < longueur; i++){
    tab[i] = valeur;
  }
  this->taille = longueur;
  this->tab = tab;
}

GeneriqueVector::GeneriqueVector(int longueur)
{
  (complex<double>) *tab;
  tab = ((complex<double>*) malloc(longueur * sizeof(complex<double>)));
  this->taille = longueur;
  this->tab = tab;
}

GeneriqueVector::~GeneriqueVector(){
  if(tab != NULL){
    delete[] tab;
  }
}

void GeneriqueVector::display(std::ostream& str){
  for(int i=0; i< taille ; i++){
    str << tab[i];
    str << "\n";
  }
}

int GeneriqueVector::size() const{
  return this->taille;
}

void GeneriqueVector::fillRandomly(){
  for(int i = 0; i<taille; i++){
    tab[i] = rand()/(float)RAND_MAX;
  }
}

//Question 3
GeneriqueVector::GeneriqueVector(std::string fichier){
  std::ifstream Fichier(fichier.c_str());
  if(Fichier.fail()){
    *this = GeneriqueVector();
    return;
  }
}

//////////////////////////////
//LAB 2
//////////////////////////////

//Question 1
//operateur d'accession a un element du vecteur
complex<double>& GeneriqueVector::operator()(int i)const{
  if (i <= taille){
    return tab[i];
  }
  else{
    std::cout <<"Erreur : index invalide";
    throw 0;
  }
}

//Question 2
//operateur d'affectation = avec la fonction memcpy
GeneriqueVector &GeneriqueVector::operator=(const GeneriqueVector &v){
  if (this==&v){
    return *this;
  }
  else{
    delete[] tab;
    taille = v.taille;
    tab = new complex<double>[taille];
    memcpy(tab, v.tab, taille*sizeof(double));
    return *this;
  }
}

// GeneriqueVector &GeneriqueVector::operator=(const GeneriqueVector &v){
//   int dimension = v.taille;
//   GeneriqueVector &Vecteur = *this;
//   Vecteur.taille = dimension;
//   for(int i = 0; i< dimension; i++){
//     Vecteur.tab = &v.tab[i];
//   }
//   return *this;
// }

//Question 3

//operateur += avec un vecteur
GeneriqueVector & GeneriqueVector::operator+=(const GeneriqueVector & v){
  GeneriqueVector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) + v(i);
  }
  return res;
}

//operateur += avec un reel
GeneriqueVector & GeneriqueVector::operator+=(const double & c){
  GeneriqueVector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) + c;
  }
  return res;
}

//operateur -= avec un vecteur
GeneriqueVector & GeneriqueVector::operator-=(const GeneriqueVector & v){
  GeneriqueVector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) - v(i);
  }
  return res;
}
//operateur -= avec un reel
GeneriqueVector & GeneriqueVector::operator-=(const double & c){
  GeneriqueVector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) - c;
  }
  return res;
}

//operateur *= avec un vecteur
GeneriqueVector & GeneriqueVector::operator*=(const GeneriqueVector & v){
  GeneriqueVector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) * v(i);
  }
  return res;
}
//operateur *= avec un reel
GeneriqueVector & GeneriqueVector::operator*=(const double & c){
  GeneriqueVector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) * c;
  }
  return res;
}

//operateur /= avec un vecteur
GeneriqueVector & GeneriqueVector::operator/=(const GeneriqueVector & v){
  GeneriqueVector &res = *this;
  for(int i = 0; i < taille; i++){
    if (v(i)==((complex<double>)0)){
      std::cout<<"Erreur : division par 0"<<"\n";
      throw 0;
    }
    else{
      res(i) = res(i) / v(i);
    }
  }
  return res;
}

//operateur /= avec un reel
GeneriqueVector & GeneriqueVector::operator/=(const double & c){
  GeneriqueVector &res = *this;
  if (c==0){
    std::cout<<"Erreur : division par 0"<<"\n";
    throw 0;
  }
  else{
    for(int i = 0; i < taille; i++){
      res(i) = res(i) * c;
    }
    return res;
  }
}

//question 4:
//operateur + externe avec un reel
GeneriqueVector operator+(const GeneriqueVector & v, const double & c){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) + c;
  }
  return v1;
}

GeneriqueVector operator+(const double & c, const GeneriqueVector & v){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) + c;
  }
  return v1;
}

//operateur + externe avec un vecteur
GeneriqueVector operator+(const GeneriqueVector & v, const GeneriqueVector & w){
  if(v.size() != w.size()){
    std::cout<<"Impossible d'additionner deux vecteurs de taille différentes"<<"\n";
    throw 0;
  }else{
    GeneriqueVector res(v);
    res += w;
    return res;
  }
}

//operateur - externe avec un reel
GeneriqueVector operator-(const GeneriqueVector & v, const double & c){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) - c;
  }
  return v1;
}

GeneriqueVector operator-(const double & c, const GeneriqueVector & v){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) - c;
  }
  return v1;
}

//operateur - externe avec un vecteur
GeneriqueVector operator-(const GeneriqueVector & v, const GeneriqueVector & w){
  if(v.size() != w.size()){
    std::cout<<"Impossible d'additionner deux vecteurs de taille différentes"<<"\n";
    throw 0;
  }else{
    GeneriqueVector res(v);
    res -= w;
    return res;
  }
}

//operateur / externe avec un reel
GeneriqueVector operator/(const GeneriqueVector & v, const double & c){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  if(dimension == 0){
    std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
    throw 0;
  }else{
    for (int i =0; i < dimension; i++){
      if(v(i) == ((complex<double>)0)){
        std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
        throw 0;
      }
      v1(i) = c/v(i);
    }
    return v1;
  }

}

GeneriqueVector operator/(const double & c, const GeneriqueVector & v){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  if(c == 0){
    std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
    throw 0;
  }else{
    for (int i =0; i < dimension; i++){
      v1(i) = v(i)/c;
    }
    return v1;
  }
}

//operateur * externe avec un reel
GeneriqueVector operator*(const GeneriqueVector & v, const double & c){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = c * v(i);
  }
  return v1;
}

GeneriqueVector operator*(const double & c, const GeneriqueVector & v){
  GeneriqueVector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = c * v(i);
  }
  return v1;
}

//operateur - unaire
GeneriqueVector operator-(const GeneriqueVector & v){
  GeneriqueVector res(v.size());
  for (int i = 0; i<v.size(); i++){
    res(i)=-v(i);
  }
  return res;
}

//operateur <<
std::ostream & operator << (std::ostream & Out, const GeneriqueVector & v){
  Out<<"GeneriqueVector : ";
  for (int i =0; i<v.size(); i++){
    Out<<v(i)<<" ";
  }
  Out<<"\n";
  return Out;
}

// //operateur >>
// std::ostream & operator >> (std::ostream & In, const GeneriqueVector & v){
//   for (int i =0; i<v.size(); i++){
//     In>>v(i);
//   }
//   return In;
// }

//operateur de test d'egalite ==
bool GeneriqueVector::operator ==(const GeneriqueVector & v){
  if (taille != v.size()){
    return false;
  }
  else{
    for (int i = 0; i < v.size(); i++){
      if (tab[i] != v(i)){
        return false;
      }
    }
  }
  return true;
}

//methode pour modifier la taille du vecteur et remplit
//le vecteur avec le reel c si le vecteur est augmenté
void GeneriqueVector::resize(const int & dimension, const double & c){
  GeneriqueVector res(dimension);
  if (dimension > taille){
    for (int i = 0; i<taille; i++){
      res.tab[i] = tab[i];
    }
    for (int i = taille; i < dimension; i++){
      res.tab[i] = c;
    }
  }
  else{
    for (int i = 0; i<dimension; i++){
      res.tab[i] = tab[i];
    }
  }
  *this = res;
}

complex<double> GeneriqueVector::pdt_scalaire(GeneriqueVector w){
  if (this->size() != w.size()){
    return 0;
  }
  else{
    complex<double> pdt = 0;
    for (int i = 0; i < w.size(); i++){
      pdt += (*this)(i)*w(i);
    }
    return pdt;
  }
}


GeneriqueVector GeneriqueVector::fft(){
  int n = this->taille;
  int N = n/2;
  GeneriqueVector odd;
  GeneriqueVector even;
  even.tab = ((complex<double>*) malloc(N * sizeof(complex<double>)));
  even.taille = N;
  odd.tab = ((complex<double>*) malloc(N * sizeof(complex<double>)));
  odd.taille = N;
  if(n%2 != 0 and n != 1){
    std::cout<<"Erreur : la longueur n'est pas un multiple de 2"<<"\n";
    throw 0;
  }
  if(n <= 1){
    return *this;
  }else{
    int i = 0;
    while(i < n){
      even.tab[i/2] = tab[i];
      odd.tab[i/2] = tab[i+1];
      i += 2;
    }
    even.fft();
    odd.fft();
    int k = 0;
    while(k <=  N -1 ){
      complex<double> t = ((complex<double>)cexp(-I*2*PI*k/N))*odd.tab[k];
      tab[k] = (even.tab[k] + t);
      tab[k + N] = even.tab[k] -t;
      k+= 1;
    }
    this->tab = tab;
    return *this;
  }
}

GeneriqueVector GeneriqueVector::conjugue(){
  int n = this->size();
  GeneriqueVector conjugu = GeneriqueVector(n);
  int k = 0;
  while(k<n){
    conjugu.tab[k] = conj(tab[k]);
    k +=1;
  }
  return conjugu;
}

GeneriqueVector GeneriqueVector::conjuguedivise(){
  int n = this->size();
  GeneriqueVector conjugu = GeneriqueVector(n);
  int k = 0;
  while(k<n){
    conjugu.tab[k] = conj(tab[k]/((complex<double>)n));
    k +=1;
  }
  return conjugu;
}

GeneriqueVector GeneriqueVector::ifft(){
  int n = this->size();
  if(n <= 1){
    return *this;
  }else{
    GeneriqueVector nouveau = GeneriqueVector(n);
    nouveau = this->conjugue();
    nouveau.fft();
    GeneriqueVector newf = nouveau.conjuguedivise();
    return newf;
  }
}


//
// int main(){
//   GeneriqueVector v = GeneriqueVector(2);
//   printf("La taille du vecteur v est %i \n ", v.size());
//   printf("Je suis v \n");
//   v.display(std::cout);
//   v.fillRandomly();
//   v.display(std::cout);
//   GeneriqueVector y = GeneriqueVector(v);
//   printf("Je suis y \n");
//   y.display(std::cout);
//   GeneriqueVector w = GeneriqueVector(3);
//   printf("Je suis w \n" );
//   w.display(std::cout);
//   w = y;
//   printf("Je suis w après avoir été change en y\n");
//   w.display(std::cout);
//   w += y;
//   printf("Je suis w + y \n");
//   w.display(std::cout);
//   w += 1;
//   printf("On rajoute 1 à  w\n");
//   w.display(std::cout);
//   w -= 1;
//   printf("En fait c'était moche donc on enlève 1\n");
//   w.display(std::cout);
//   w*=5;
//   printf("Il est préférable de le multiplier par 5 plutot\n");
//   w.display(std::cout);
//   w /= v;
//   printf("Oh je viens de me diviser par v\n");
//   w.display(std::cout);
//   y = 5 + w;
//   printf("Oups on m'ajoute 5 \n");
//   y.display(std::cout);
//   w = w + w;
//   printf("Je vais devenir grand \n");
//   w.display(std::cout);
//   printf("%i\n ", w == y);
//   complex<double> com = cexp(-I*4);
//   complex<double> com2 = cexp(-I*8);
//   printf("Mon complexe est %f, %f\n", com);
//   GeneriqueVector ffggt = GeneriqueVector(8, com);
//   GeneriqueVector ffw = GeneriqueVector(8,com2);
//   GeneriqueVector ff = ffggt + ffw;
//   printf("%i", ff.size());
//   printf("Mon nouveau vecteur ff \n");
//   ff.display(std::cout);
//   GeneriqueVector ffko = ff.conjugue();
//   printf("Mon nouveau vecteur ff \n");
//   ffko.display(std::cout);
//   GeneriqueVector ffl = ffko.conjugue();
//   printf("Mon nouveau vecteur ffL \n");
//   ffl.display(std::cout);
//   ff.fft();
//   printf("J'ai subit une fft \n");
//   ff.display(std::cout);
//   printf("On a subit une ifft\n");
//   GeneriqueVector gjg = ff.ifft();
//   gjg.display(std::cout);
//
// }
