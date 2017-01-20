#ifndef TYPEUNITE_H
#define TYPEUNITE_H

#include <vector>
#include <string>

using namespace std;

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
    string getNom() const;
    int getPrix() const;
    int getPointsVieBase() const;
    int getPointsAttaque() const;
};

#endif // TYPEUNITE_H
