#ifndef IA_H
#define IA_H

#include <string>

#include "joueur.h"

using namespace std;

class IA : public Joueur
{
public:
    using Joueur::Joueur;
    virtual void choisir();
    virtual void afficher() const;
};

#endif // IA_H
