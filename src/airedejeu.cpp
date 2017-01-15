#include <iostream>

#include "airedejeu.h"

using namespace std;

AireDeJeu::AireDeJeu(Joueur& j1, Joueur& j2): joueur1(j1), joueur2(j2)
{
    joueur1.setSens(Joueur::Sens::J1);
    joueur2.setSens(Joueur::Sens::J2);
}

void AireDeJeu::lancer()
{
    char choix = 'o';
    while(choix == 'o') {
        joueur1.jouer();
        joueur2.jouer();
        cout << "Voulez vous continuer ? (o/N)" << endl;
        cin >> choix;
    }
}

const void AireDeJeu::afficher()
{
    joueur1.afficher();
    joueur2.afficher();
}
