#include "fantassin.h"
#include "joueur.h"
#include "airedejeu.h"
#include "supersoldat.h"

Fantassin::Fantassin() : TypeUnite("Fantassin", 10, 10, 4)
{
}

void Fantassin::action1(Unite *unite) {
    Joueur *joueur = unite->getJoueur();
    Joueur *adversaire = unite->getJoueur()->getAdversaire();
    int case_ = unite->getCase();

    if (joueur->getSens() == Joueur::Sens::J1) {
        unite->setEchecAction1(!joueur->getAire()->attaquer(adversaire, unite->getCase() + 1, pointsAttaque));
        if (!unite->getEchecAction1() && adversaire->getUnite(case_ + 1) == nullptr) {
            unite->setType(SuperSoldat::getInstance());
        }
    } else {
        unite->setEchecAction1(!joueur->getAire()->attaquer(adversaire, unite->getCase() - 1, pointsAttaque));
        if (!unite->getEchecAction1() && adversaire->getUnite(case_ - 1) == nullptr) {
            unite->setType(SuperSoldat::getInstance());
        }
    }
}

void Fantassin::action2(Unite *unite) {
    unite->getJoueur()->getAire()->avancer(unite);
}

void Fantassin::action3(Unite *unite) {
    if(unite->getEchecAction1())
        action1(unite);
    unite->setEchecAction1(false);
}