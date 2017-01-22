#include "archer.h"
#include "joueur.h"
#include "airedejeu.h"

Archer::Archer() : TypeUnite("Archer", 12, 8, 3)
{
}

void Archer::action1(Unite *unite) {
    Joueur *joueur = unite->getJoueur();
    Joueur *adversaire = unite->getJoueur()->getAdversaire();
    if(joueur->getSens() == Joueur::Sens::J1) {
        for(int i = unite->getCase()+1; i<=unite->getCase()+3; i++) {
            if(joueur->getAire()->attaquer(adversaire, i, pointsAttaque))
                break;
        }
    }
    else {
        for(int i = unite->getCase()-1; i>=unite->getCase()-3; i--) {
            if(joueur->getAire()->attaquer(adversaire, i, pointsAttaque))
                break;
        }
    }
}

void Archer::action2(Unite *unite) {
    unite->getJoueur()->getAire()->avancer(unite);
}

void Archer::action3(Unite *unite) {
}