#ifndef HUMAIN_H
#define HUMAIN_H

#include "joueur.h"

class Humain : public Joueur
{
public:
    using Joueur::Joueur;
    virtual void jouer();
    virtual void afficher() const;
};

#endif // HUMAIN_H
