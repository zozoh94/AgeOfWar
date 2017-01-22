#ifndef TYPEUNITE_H
#define TYPEUNITE_H

#include <vector>
#include <string>

class AireDeJeu;
class Joueur;
class Unite;

using namespace std;

class TypeUnite
{
friend class Unite;
protected:
    string nom;
    int prix;
    int pointsVieBase;
    int pointsAttaque;
    virtual void action1(Unite* unite) const = 0;
    virtual void action2(Unite* unite) const = 0;
    virtual void action3(Unite* unite) const = 0;

    // utils
    int addition(int a, int b);
    int subtraction(int a, int b);

public:
    TypeUnite(string nom, int prix, int pointsVieBase, int pointsAttaque);
    string getNom() const;
    int getPrix() const;
    int getPointsVieBase() const;
    int getPointsAttaque() const;
};

#endif // TYPEUNITE_H
