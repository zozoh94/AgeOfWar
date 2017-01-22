#include "supersoldat.h"
#include "joueur.h"
#include "airedejeu.h"

SuperSoldat::SuperSoldat() : TypeUnite("Super Soldat", 0, 10, 4)
{
}

void SuperSoldat::action1(Unite *unite) {
    Joueur *joueur = unite->getJoueur();
    Joueur *adversaire = unite->getJoueur()->getAdversaire();

    if(joueur->getSens() == Joueur::Sens::J1)
        joueur->getAire()->attaquer(adversaire, unite->getCase()+1, pointsAttaque);
    else
        joueur->getAire()->attaquer(adversaire, unite->getCase()-1, pointsAttaque);
}

void SuperSoldat::action2(Unite *unite) {
    unite->getJoueur()->getAire()->avancer(unite);
}

void SuperSoldat::action3(Unite *unite) {
    action1(unite);
}