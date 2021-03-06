/**
* \file Dvector.c
* \brief mise en place des vecteurs
*/

#include "Dvector.h"


Dvector::Dvector(Dvector const& autre){
  int taillAutre = autre.taille;
  tab = new double[taillAutre];
  taille = taillAutre;
  for(int i = 0; i< taille; i++){
    tab[i] = autre.tab[i];
  }
}


Dvector::Dvector()
{
  tab = (double*) malloc(sizeof(double));
  this->tab = tab;
  this->taille = 0;
}

Dvector::Dvector(int longueur, double valeur)
{
  tab = (double*) malloc(longueur * sizeof(double));
  for(int i = 0; i < longueur; i++){
    tab[i] = valeur;
  }
  this->taille = longueur;
  this->tab = tab;
}

Dvector::Dvector(int longueur)
{
  tab = (double*) malloc(longueur * sizeof(double));
  this->taille = longueur;
  this->tab = tab;
}

Dvector::~Dvector(){
  if(tab != NULL){
    delete[] tab;
  }
}

void Dvector::display(std::ostream& str){
  for(int i=0; i< taille ; i++){
    str << tab[i];
    str << "\n";
  }
}

int Dvector::size() const{
  return this->taille;
}

void Dvector::fillRandomly(){
  for(int i = 0; i<taille; i++){
    tab[i] = rand()/(float)RAND_MAX;
  }
}

//Question 3
int getNbLine(std::string filename){
  std::ifstream Fichier(filename.c_str());
  int n = 0;
  if(Fichier){
    std::string ligne;
    while(getline(Fichier, ligne)){
      n++;
    }
  }else{
      std::cout << "ERREUR : impossible d'ouvrir le fichier" << std::endl;
  }
  return n;
}

Dvector::Dvector(std::string fichier){
  taille = getNbLine(fichier);
  std::ifstream Fichier(fichier.c_str());

  if(Fichier){
    tab = new double[taille];
    std::string ligne;
    int i = 0;
    while(getline(Fichier, ligne)){
      tab[i] = std::atof(ligne.c_str());
      i++;
    }
  }else{
    std::cout << "ERREUR : Impossible d'ouvrir le fichier" << std::endl;
  }
  Fichier.close();
}

//////////////////////////////
//LAB 2
//////////////////////////////

//Question 1
//operateur d'accession a un element du vecteur
double& Dvector::operator()(int i)const{
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
Dvector &Dvector::operator=(const Dvector &v){
  if (this==&v){
    return *this;
  }
  else{
    delete[] tab;
    taille = v.taille;
    tab = new double[taille];
    memcpy(tab, v.tab, taille*sizeof(double));
    return *this;
  }
}


//Question 3

//operateur += avec un vecteur
Dvector & Dvector::operator+=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) + v(i);
  }
  return res;
}

//operateur += avec un reel
Dvector & Dvector::operator+=(const double & c){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) + c;
  }
  return res;
}

//operateur -= avec un vecteur
Dvector & Dvector::operator-=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) - v(i);
  }
  return res;
}
//operateur -= avec un reel
Dvector & Dvector::operator-=(const double & c){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) - c;
  }
  return res;
}

//operateur *= avec un vecteur
Dvector & Dvector::operator*=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) * v(i);
  }
  return res;
}
//operateur *= avec un reel
Dvector & Dvector::operator*=(const double & c){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res(i) = res(i) * c;
  }
  return res;
}

//operateur /= avec un vecteur
Dvector & Dvector::operator/=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    if (v(i)==0){
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
Dvector & Dvector::operator/=(const double & c){
  Dvector &res = *this;
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
Dvector operator+(const Dvector & v, const double & c){
  Dvector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) + c;
  }
  return v1;
}

Dvector operator+(const double & c, const Dvector & v){
  Dvector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) + c;
  }
  return v1;
}

//operateur + externe avec un vecteur
Dvector operator+(const Dvector & v, const Dvector & w){
  if(v.size() != w.size()){
    std::cout<<"Impossible d'additionner deux vecteurs de taille différentes"<<"\n";
    throw 0;
  }else{
    Dvector res(v);
    res += w;
    return res;
  }
}

//operateur - externe avec un reel
Dvector operator-(const Dvector & v, const double & c){
  Dvector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) - c;
  }
  return v1;
}

Dvector operator-(const double & c, const Dvector & v){
  Dvector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = v(i) - c;
  }
  return v1;
}

//operateur - externe avec un vecteur
Dvector operator-(const Dvector & v, const Dvector & w){
  if(v.size() != w.size()){
    std::cout<<"Impossible d'additionner deux vecteurs de taille différentes"<<"\n";
    throw 0;
  }else{
    Dvector res(v);
    res -= w;
    return res;
  }
}

//operateur / externe avec un reel
Dvector operator/(const Dvector & v, const double & c){
  Dvector v1(v.size());
  int dimension = v.size();
  if(dimension == 0){
    std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
    throw 0;
  }else{
    for (int i =0; i < dimension; i++){
      if(v(i) == 0){
        std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
        throw 0;
      }
      v1(i) = c/v(i);
    }
    return v1;
  }

}

Dvector operator/(const double & c, const Dvector & v){
  Dvector v1(v.size());
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
Dvector operator*(const Dvector & v, const double & c){
  Dvector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = c * v(i);
  }
  return v1;
}

Dvector operator*(const double & c, const Dvector & v){
  Dvector v1(v.size());
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1(i) = c * v(i);
  }
  return v1;
}

//operateur - unaire
Dvector operator-(const Dvector & v){
  Dvector res(v.size());
  for (int i = 0; i<v.size(); i++){
    res(i)=-v(i);
  }
  return res;
}

//operateur <<
std::ostream & operator << (std::ostream & Out, const Dvector & v){
  Out<<"Dvector : ";
  for (int i =0; i<v.size(); i++){
    Out<<v(i)<<" ";
  }
  Out<< std::endl;
  return Out;
}

// //operateur >>
// std::ostream & operator >> (std::ostream & In, const Dvector & v){
//   for (int i =0; i<v.size(); i++){
//     In>>v(i);
//   }
//   return In;
// }

//operateur de test d'egalite ==
bool Dvector::operator ==(const Dvector & v){
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
void Dvector::resize(const int & dimension, const double & c){
  Dvector res(dimension);
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

double Dvector::pdt_scalaire(Dvector w){
  if (this->size() != w.size()){
    return 0;
  }
  else{
    double pdt = 0;
    for (int i = 0; i < w.size(); i++){
      pdt += (*this)(i)*w(i);
    }
    return pdt;
  }
}

double norm(const Dvector &v){
  double res = 0;
  for (int i = 0; i < v.size(); i++){
    res += pow(v(i), 2);
  }
  return sqrt(res);
}

Dvector& fill(Dvector& vec, double v){
  for(int i= 0; i<vec.size(); i++){
      vec(i) =v;
  }
  return vec;
}
