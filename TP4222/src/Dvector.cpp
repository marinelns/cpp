
#include "Dvector.h"
const double PI = 3.1415926535;


Dvector::Dvector(Dvector const& autre){
  int taillAutre = autre.taille;
  taille = taillAutre;
  for(int i = 0; i< taille; i++){
    tab.push_back(autre.tab[i]);
  }
}



Dvector::Dvector()
{
  int longueur = 0;
  taille = longueur;
  for(int i = 0; i< longueur; i++){
    tab.push_back(0);
  }
}

Dvector::Dvector(int longueur, int valeur)
{
  taille = longueur;
  for(int i =0; i < longueur; i++){
    tab.push_back(valeur);
  }
}

Dvector::Dvector(int longueur)
{
  taille = longueur;
  for(int i = 0; i< longueur; i++){
    tab.push_back(0);
  }
}

Dvector::~Dvector(){
  if(tab.size() == 0){
    tab.clear();
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
Dvector::Dvector(std::string fichier){
  std::ifstream Fichier(fichier.c_str());
  if(Fichier.fail()){
    *this = Dvector();
    return;
  }
}

//////////////////////////////
//LAB 2
//////////////////////////////

//Question 1
//operateur d'accession a un element du vecteur
complex<double> & Dvector::operator()(int i){
  if (i <= taille){
    return tab.at(i);
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
    tab.clear();
    copy(v.tab.begin(), v.tab.end(), back_inserter(tab));
    return *this;
  }
}

// Dvector &Dvector::operator=(const Dvector &v){
//   int dimension = v.taille;
//   Dvector &Vecteur = *this;
//   Vecteur.taille = dimension;
//   for(int i = 0; i< dimension; i++){
//     Vecteur.tab = &v.tab[i];
//   }
//   return *this;
// }

//Question 3

//operateur += avec un vecteur
Dvector & Dvector::operator+=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res.tab[i] = res.tab[i] + v.tab[i];
  }
  return res;
}

//operateur += avec un reel
Dvector & Dvector::operator+=(const double & c){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res.tab[i] = res.tab[i] + c;
  }
  return res;
}

//operateur -= avec un vecteur
Dvector & Dvector::operator-=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res.tab[i] = res.tab[i] - v.tab[i];
  }
  return res;
}
//operateur -= avec un reel
Dvector & Dvector::operator-=(const double & c){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res.tab[i] = res.tab[i] - c;
  }
  return res;
}

//operateur *= avec un vecteur
Dvector & Dvector::operator*=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res.tab[i] = res.tab[i] * v.tab[i];
  }
  return res;
}
//operateur *= avec un reel
Dvector & Dvector::operator*=(const double & c){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    res.tab[i] = res.tab[i] * c;
  }
  return res;
}

//operateur /= avec un vecteur
Dvector & Dvector::operator/=(const Dvector & v){
  Dvector &res = *this;
  for(int i = 0; i < taille; i++){
    if (v.tab[i] == ((complex<double>) 0)){
      std::cout<<"Erreur : division par 0"<<"\n";
      throw 0;
    }
    else{
      res.tab[i] = res.tab[i] / v.tab[i];
    }
  }
  return res;
}

//operateur /= avec un reel
Dvector & Dvector::operator/=( double c){
  Dvector &res = *this;
  if (c==0){
    std::cout<<"Erreur : division par 0"<<"\n";
    throw 0;
  }
  else{
    for(int i = 0; i < taille; i++){
      res.tab[i] = res.tab[i] * c;
    }
    return res;
  }
}

//question 4:
//operateur + externe avec un reel
Dvector operator+(const Dvector & v, const double & c){
  Dvector v1;
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1.tab[i] = v.tab[i] + c;
  }
  return v1;
}

Dvector operator+(const double & c, const Dvector & v){
  Dvector v1;
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1.tab[i] = v.tab[i] + c;
  }
  return v1;
}

//operateur + externe avec un vecteur
Dvector operator+(const Dvector & v, const Dvector & w){
  if(v.size() != w.size()){
    std::cout<<"Impossible d'additionner deux vecteurs de taille différentes"<<"\n";
    throw 0;
  }else{
    Dvector res;
    int dimension= v.size();
    for (int i =0; i < dimension; i++){
      res.tab[i] = v.tab[i] + w.tab[i];
    }
    return res;
  }
}

//operateur - externe avec un reel
Dvector operator-(const Dvector & v, const double & c){
  Dvector v1;
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1.tab[i] = v.tab[i] - c;
  }
  return v1;
}

Dvector operator-(const double & c, const Dvector & v){
  Dvector v1;
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1.tab[i] = v.tab[i] - c;
  }
  return v1;
}

//operateur - externe avec un vecteur
Dvector operator-(const Dvector & v, const Dvector & w){
  if(v.size() != w.size()){
    std::cout<<"Impossible d'additionner deux vecteurs de taille différentes"<<"\n";
    throw 0;
  }else{
    Dvector res;
    res -= w;
    return res;
  }
}

//operateur / externe avec un reel
Dvector operator/(const Dvector & v, const double & c){
  Dvector v1;
  int dimension = v.size();
  if(dimension == 0){
    std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
    throw 0;
  }else{
    for (int i =0; i < dimension; i++){
      if(v.tab[i] == ((complex<double>)0)){
        std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
        throw 0;
      }
      v1.tab[i] = c/v.tab[i];
    }
    return v1;
  }

}

Dvector operator/(const double & c, const Dvector & v){
  Dvector v1;
  int dimension = v.size();
  if(c == 0){
    std::cout<<"Impossible de diviser par le vecteur nul"<<"\n";
    throw 0;
  }else{
    for (int i =0; i < dimension; i++){
      v1.tab[i] = v.tab[i]/c;
    }
    return v1;
  }
}

//operateur * externe avec un reel
Dvector operator*(const Dvector & v, const double & c){
  Dvector v1;
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1.tab[i] = c * v.tab[i];
  }
  return v1;
}

Dvector operator*(const double & c, const Dvector & v){
  Dvector v1;
  int dimension = v.size();
  for (int i =0; i < dimension; i++){
    v1.tab[i] = c * v.tab[i];
  }
  return v1;
}

//operateur - unaire
Dvector operator-(const Dvector & v){
  Dvector res;
  for (int i = 0; i<v.size(); i++){
    res.tab[i]=-v.tab[i];
  }
  return res;
}

//operateur <<
std::ostream & operator << (std::ostream & Out, const Dvector & v){
  Out<<"Dvector : ";
  for (int i =0; i<v.size(); i++){
    Out<<v.tab[i]<<" ";
  }
  Out<<"\n";
  return Out;
}

// //operateur >>
// std::ostream & operator >> (std::ostream & In, const Dvector & v){
//   for (int i =0; i<v.size(); i++){
//     In>>((char)v.tab[i]);
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
      if (tab[i] != v.tab[i]){
        return false;
      }
    }
  }
  return true;
}

//methode pour modifier la taille du vecteur et remplit
//le vecteur avec le reel c si le vecteur est augmenté
// void Dvector::resize(const int & dimension, const double & c){
//   Dvector res(dimension);
//   if (dimension > taille){
//     for (int i = 0; i<taille; i++){
//       res.tab[i] = tab[i];
//     }
//     for (int i = taille; i < dimension; i++){
//       res.tab[i] = c;
//     }
//   }
//   else{
//     for (int i = 0; i<dimension; i++){
//       res.tab[i] = tab[i];
//     }
//   }
//   *this = res;
// }

complex<double> Dvector::pdt_scalaire(Dvector w){
  if (this->size() != w.size()){
    return 0;
  }
  else{
    complex<double> pdt = 0;
    for (int i = 0; i < w.size(); i++){
      pdt = pdt + (*this).tab[i]*w.tab[i];
    }
    return pdt;
  }
}

/////////////////////////// LAB 4/////////////////////

Dvector Dvector::FFT(){
  Dvector even = Dvector();
  Dvector odd = Dvector();
  int n = int(this->tab.size());
  if(n <= 1){
    return *this;
  }else{
    int j = 0;
    while(j < n){
      even.tab.push_back(tab[j]);
      odd.tab.push_back(tab[j+1]);
      j += 2;
    }
    even.FFT();
    odd.FFT();
    tab.clear();
    std::vector<complex<double> >::iterator it;
    it = tab.begin();
    for(int k = 0; k < (n/2-1); k++){
      complex<double> t = std::polar(1.0, -2*PI*k/n)*odd.tab[k];
      tab.insert(it + k, even.tab[k] + t);
      tab.insert(it + k+n/2, even.tab[k] - t);
    }
    return *this;
  }
}

void Dvector::conj(){
  int n = ((int)tab.size());
  for(int k = 0; k<n; k++){
    tab[k] = std::conj(tab[k]);
  }
}

Dvector Dvector::ifft(){
  Dvector res = *this;
  int n = ((int)tab.size());
  if(n <= 1){
    return *this;
  }else{
    this->conj();
    this->FFT();
    this->conj();
    *this /= ((double)n);
    return *this;
  }
}

int main(){
  // Dvector v = Dvector();
  // printf("La taille du vecteur v est %i \n ", v.size());
  // printf("Je suis v \n");
  // v.display(std::cout);
  // v.fillRandomly();
  // v.display(std::cout);
  // Dvector y = Dvector(v);
  // printf("Je suis y \n");
  // y.display(std::cout);
  // Dvector w = Dvector(3);
  // printf("Je suis w \n" );
  // w.display(std::cout);
  // w = y;
  // printf("Je suis w après avoir été change en y\n");
  // w.display(std::cout);
  // w += y;
  // printf("Je suis w + y \n");
  // w.display(std::cout);
  // w += 1;
  // printf("On rajoute 1 à  w\n");
  // w.display(std::cout);
  // w -= 1;
  // printf("En fait c'était moche donc on enlève 1\n");
  // w.display(std::cout);
  // w*=5;
  // printf("Il est préférable de le multiplier par 5 plutot\n");
  // w.display(std::cout);
  // w /= v;
  // printf("Oh je viens de me diviser par v\n");
  // w.display(std::cout);
  // printf("Je suis y avant\n");
  // y.display(std::cout);
  // y = 5 + w;
  // printf("Oups on m'ajoute 5 \n");
  // y.display(std::cout);
  // printf("Je suis w avant\n");
  // w.display(std::cout);
  // w = w + w;
  // printf("Je vais devenir grand \n");
  // w.display(std::cout);
  // printf("%i\n ", w == y);
  // // w.FFT();
  // // printf("Je suis la fft de f\n");
  // // w.display(std::cout);
  Dvector ff = Dvector(4, 10);
  printf("Mon nouveau vecteur ff \n");
  ff.display(std::cout);
  ff.FFT();
  printf("J'ai subit une fft \n");
  ff.display(std::cout);
  printf("On a subit une ifft\n");
  ff.ifft();
  ff.display(std::cout);
}
