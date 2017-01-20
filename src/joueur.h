#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>

#include "unite.h"

using namespace std;

class Joueur
{
public:
    enum Sens{J1, J2};
protected:
    vector<Unite> unites;
    Joueur::Sens sens;
    string nom;
    int argent;
    int vieBase;
    bool acheter(TypeUnite& unite);
public:
    Joueur(string nom);
    Joueur::Sens getSens() const;
    Joueur& setSens(Joueur::Sens sens);
    virtual void afficher() const;
    virtual void choisir() = 0;
    void jouer();
    void incrArgent(int argent);
};

#endif // JOUEUR_H
