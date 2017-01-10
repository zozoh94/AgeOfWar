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
public:
    Joueur(string nom);
    Joueur::Sens getSens() const;
    Joueur& setSens(Joueur::Sens sens);
    virtual void afficher() const;
    virtual void jouer() = 0;
};

#endif // JOUEUR_H
