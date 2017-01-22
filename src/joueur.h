#ifndef JOUEUR_H
#define JOUEUR_H

#include <map>
#include <string>

#include "unite.h"

using namespace std;

class AireDeJeu;

class Joueur
{
public:
    enum Sens{J1, J2};
protected:
    multimap<int, Unite*> unites;
    Joueur::Sens sens;
    string nom;
    int argent;
    int vieBase;
    bool acheter(TypeUnite& unite);
    AireDeJeu *aire;
public:
    Joueur(string nom);
    Joueur& setAire(AireDeJeu* aire);
    Joueur::Sens getSens() const;
    Joueur& setSens(Joueur::Sens sens);
    string getNom() const;
    AireDeJeu* getAire();
    virtual void afficher() const;
    virtual void choisir() = 0;
    void jouer();
    void incrArgent(int argent);
    Joueur* getAdversaire();
    void decrVie(int vie);
    void avancerUnite(Unite* unite);
    bool estMort() const;
    void supprimerUnite(int case_);
    Unite* getUnite(int case_) const;
};

#endif // JOUEUR_H
