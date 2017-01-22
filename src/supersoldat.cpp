#include "supersoldat.h"
#include "joueur.h"
#include "airedejeu.h"

SuperSoldat::SuperSoldat() : TypeUnite("Super Soldat", 0, 10, 4)
{
}

void SuperSoldat::action1(Unite *unite) const {
    Joueur *joueur = unite->getJoueur();
    Joueur *adversaire = unite->getJoueur()->getAdversaire();

    if(joueur->getSens() == Joueur::Sens::J1)
        joueur->getAire()->attaquer(adversaire, unite->getCase()+1, pointsAttaque);
    else
        joueur->getAire()->attaquer(adversaire, unite->getCase()-1, pointsAttaque);
}

void SuperSoldat::action2(Unite *unite) const {
    unite->getJoueur()->getAire()->avancer(unite);
}

void SuperSoldat::action3(Unite *unite) const {
    action1(unite);
}