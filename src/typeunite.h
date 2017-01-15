#ifndef TYPEUNITE_H
#define TYPEUNITE_H

#include <vector>
#include <string>

using namespace std;

class Unite;

class TypeUnite
{
friend class Unite;
protected:
    string nom;
    int prix;
    int pointsVieBase;
    int pointsAttaque;
public:
    TypeUnite(string nom, int prix, int pointsVieBase, int pointsAttaque);
    string getNom();
    int getPrix();
    int getPointsVieBase();
    int getPointsAttaque();
};

#endif // TYPEUNITE_H
