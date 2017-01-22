#include <iostream>

#include "airedejeu.h"
#include "archer.h"
#include "fantassin.h"
#include "catapulte.h"
#include "supersoldat.h"

using namespace std;

AireDeJeu::AireDeJeu(Joueur& j1, Joueur& j2): joueur1(j1), joueur2(j2), tour(0)
{
    joueur1.setSens(Joueur::Sens::J1).setAire(this);
    joueur2.setSens(Joueur::Sens::J2).setAire(this);
}

void AireDeJeu::lancer()
{
    char choix = 'o';
    while(choix != 'N' && tour < 100) {
        ++tour;
        cout << "TOUR " << tour << endl << endl;
        joueur1.incrArgent(8);
        joueur2.incrArgent(8);
        afficher();
        cout << endl << "En train de jouer ..." << endl << endl;
        joueur1.jouer();
        joueur2.jouer();
        cout << endl << endl;
        afficher();
        if(joueur1.estMort() || joueur2.estMort())
            break;
        joueur1.choisir();
        joueur2.choisir();
        cout << endl << "Voulez vous continuer ? (o/N)" << endl;
        cin >> choix;
        cout << endl;
    }

    if(joueur1.estMort() && !joueur2.estMort())
        cout << "Vicoire du joueur 2 !" << endl;
    else if(!joueur1.estMort() && joueur2.estMort())
        cout << "Vicoire du joueur 1 !" << endl;
    else
        cout << "Il n'y a pas de vainqueur !" << endl;
}

void AireDeJeu::afficher() const
{
    cout << "ETAT DU JEU" << endl;
    cout << "Joueur 1 :" << endl;
    joueur1.afficher();
    cout << "Joueur 2 :" << endl;
    joueur2.afficher();
}

bool AireDeJeu::addUnite(Unite *unite) {
    if (unites.find(unite->getCase()) != unites.end())
        return false;
    unites.insert({unite->getCase(), unite});
    return true;
}

AireDeJeu::~AireDeJeu() {
    Singleton<Archer>::kill();
    Singleton<Fantassin>::kill();
    Singleton<Catapulte>::kill();
    Singleton<SuperSoldat>::kill();
    //On supprime les unites qui sont encore sur le plateau
    for(auto it = unites.begin();it != unites.end(); ++it)
    {
        delete it->second;
    }
    unites.clear();
}

Joueur *AireDeJeu::getAdversaire(AireDeJeu *aire, Joueur *joueur) {
    if(joueur == &(aire->joueur1))
        return &(aire->joueur2);
    else
        return &(aire->joueur1);
}

bool AireDeJeu::attaquer(Joueur* joueur, int case_, int attaque) {
    if (unites.find(case_) != unites.end() && unites.find(case_)->second->getJoueur() == joueur) {
        unites[case_]->decrVie(attaque);
        if(unites[case_]->estMort()) {
            unites.erase(case_);
            joueur->supprimerUnite(case_);
        }
        return true;
    }
    else if((joueur->getSens() == Joueur::Sens::J1 && case_ == 0) ||
            (joueur->getSens() == Joueur::Sens::J2 && case_ == 11)) {
        joueur->decrVie(attaque);
        return true;
    }
    return false;
}

void AireDeJeu::avancer(Unite *unite) {
    if((unite->getJoueur()->getSens() == Joueur::Sens::J1 && unite->getCase() != 10 && unites.find(unite->getCase()+1) == unites.end()) ||
            (unite->getJoueur()->getSens() == Joueur::Sens::J2 && unite->getCase() != 1 && unites.find(unite->getCase()-1) == unites.end())) {
        unites.erase(unite->getCase());
        unite->getJoueur()->avancerUnite(unite);
    }
}
