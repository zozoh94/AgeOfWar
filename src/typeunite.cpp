#include "typeunite.h"

TypeUnite::TypeUnite(string _nom, int _prix, int _pointsVieBase, int _pointsAttaque) :
nom(_nom), prix(_prix), pointsVieBase(_pointsVieBase), pointsAttaque(_pointsAttaque)
{
}

string TypeUnite::getNom() { return nom; }

int TypeUnite::getPrix() { return prix; }

int TypeUnite::getPointsVieBase() { return pointsVieBase; }

int TypeUnite::getPointsAttaque() { return pointsAttaque; }