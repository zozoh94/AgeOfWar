#include "catapulte.h"
#include "joueur.h"
#include "airedejeu.h"

Catapulte::Catapulte() : TypeUnite("Catapulte", 20, 12, 6)
{
}

void Catapulte::action1(Unite *unite) const {

    Joueur *joueur = unite->getJoueur();
    Joueur *adversaire = unite->getJoueur()->getAdversaire();


    if(joueur->getSens() == Joueur::Sens::J1) {
        // Ennemy at case +2..+4 ?
        for(int i = unite->getCase()+2 ; i <= unite->getCase()+4 ; i++)
            if(i < unite->getCase()+4 && joueur->getAire()->attaquer(adversaire, i, pointsAttaque)) {
                joueur->getAire()->attaquer(adversaire, i + 1, pointsAttaque); // Attack next case
                break;
            }
            else if (joueur->getAire()->attaquer(adversaire, i, pointsAttaque))
                joueur->getAire()->attaquer(adversaire, i - 1, pointsAttaque); // Attack previous case
    }
    else {
        // Ennemy at case -2..-4 ?
        for(int i = unite->getCase()-2 ; i >= unite->getCase()-4 ; i++)
            if(i > unite->getCase()-4 && joueur->getAire()->attaquer(adversaire, i, pointsAttaque)) {
                joueur->getAire()->attaquer(adversaire, i - 1, pointsAttaque); // Attack next case
                break;
            }
            else if (joueur->getAire()->attaquer(adversaire, i, pointsAttaque))
                joueur->getAire()->attaquer(adversaire, i + 1, pointsAttaque); // Attack previous case
    }
}

void Catapulte::action2(Unite *unite) const {
    unite->getJoueur()->getAire()->avancer(unite);
}

void Catapulte::action3(Unite *unite) const {

}