#include "fantassin.h"
#include "joueur.h"
#include "airedejeu.h"

Fantassin::Fantassin() : TypeUnite("Fantassin", 10, 10, 4)
{
}

void Fantassin::action1(Unite *unite) const {
    Joueur *joueur = unite->getJoueur();
    Joueur *adversaire = unite->getJoueur()->getAdversaire();

    if(joueur->getSens() == Joueur::Sens::J1)
        joueur->getAire()->attaquer(adversaire, unite->getCase()+1, pointsAttaque);
    else
        joueur->getAire()->attaquer(adversaire, unite->getCase()-1, pointsAttaque);
}

void Fantassin::action2(Unite *unite) const {
    unite->getJoueur()->getAire()->avancer(unite);
}

void Fantassin::action3(Unite *unite) const {

}