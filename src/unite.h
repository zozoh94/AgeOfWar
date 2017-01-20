#ifndef UNITE_H
#define UNITE_H

#include "typeunite.h"

class Joueur;

class Unite
{
private:
    int case_;
    int pointsVie;
    TypeUnite *type;
    Joueur &joueur;
public:
    Unite(TypeUnite *type, Joueur &joueur, int _case_);
    int getCase() const;
    const TypeUnite* getType() const;
    Joueur* getJoueur() const;
    void decrVie(int vie);
    void setCase(int case_);
    void afficher() const;
    void action1();
    void action2();
    void action3();
    bool estMort() const;
};

#endif // UNITE_H
