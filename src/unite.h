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
    void afficher() const;
};

#endif // UNITE_H
