#ifndef AIREDEJEU_H
#define AIREDEJEU_H

#include <map>

#include "joueur.h"

class AireDeJeu
{
private:
    Joueur &joueur1;
    Joueur &joueur2;
    int tour;
    map<int, Unite*> unites;
public:
    AireDeJeu(Joueur& j1, Joueur& j2);
    ~AireDeJeu();
    AireDeJeu& addUnite(Unite *unite);
    void lancer();
    void afficher() const;
};

#endif // AIREDEJEU_H
