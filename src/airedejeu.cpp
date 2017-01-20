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
    while(choix == 'o' && tour < 100) {
        ++tour;
        cout << "TOUR " << tour << endl << endl;
        joueur1.incrArgent(8);
        joueur2.incrArgent(8);
        afficher();
        cout << endl << "En train de jouer ..." << endl << endl;
        joueur1.jouer();
        joueur2.jouer();
        afficher();
        joueur1.choisir();
        joueur2.choisir();
        cout << endl << "Voulez vous continuer ? (o/N)" << endl;
        cin >> choix;
        cout << endl;
    }
    if(tour == 100) {
        cout << "Il n'y a pas de vainqueur !" << endl;
    }
}

void AireDeJeu::afficher() const
{
    cout << "ETAT DU JEU" << endl;
    cout << "Joueur 1 :" << endl;
    joueur1.afficher();
    cout << "Joueur 2 :" << endl;
    joueur2.afficher();
}

AireDeJeu &AireDeJeu::addUnite(Unite *unite) {
    unites.insert({unite->getCase(), unite});
    return *this;
}

AireDeJeu::~AireDeJeu() {
    Singleton<Archer>::kill();
    Singleton<Fantassin>::kill();
    Singleton<Catapulte>::kill();
    Singleton<SuperSoldat>::kill();
    map<int, Unite*>::const_iterator it;
    //On supprime les unites qui sont encore sur le plateau
    for(it = unites.begin();it != unites.end(); ++it)
    {
        delete it->second;
    }
    unites.clear();
}
