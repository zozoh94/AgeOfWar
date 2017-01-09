#ifndef AIREDEJEU_H
#define AIREDEJEU_H

#include "joueur.h"

class AireDeJeu
{
private:
    Joueur &joueur1;
    Joueur &joueur2;
public:
    AireDeJeu(Joueur& j1, Joueur& j2);
    void lancer();
    const void afficher();
};

#endif // AIREDEJEU_H
