#include "typeunite.h"

TypeUnite::TypeUnite(string _nom, int _prix, int _pointsVieBase, int _pointsAttaque) :
nom(_nom), prix(_prix), pointsVieBase(_pointsVieBase), pointsAttaque(_pointsAttaque)
{
}

string TypeUnite::getNom() const { return nom; }

int TypeUnite::getPrix() const { return prix; }

int TypeUnite::getPointsVieBase() const { return pointsVieBase; }

int TypeUnite::getPointsAttaque() const { return pointsAttaque; }

int TypeUnite::addition(int a, int b) { return a+b; }

int TypeUnite::subtraction(int a, int b) {return a-b; }