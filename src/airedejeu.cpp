#include <iostream>

#include "airedejeu.h"

using namespace std;

AireDeJeu::AireDeJeu(Joueur& j1, Joueur& j2): joueur1(j1), joueur2(j2)
{
    j1.setSens(Joueur::Sens::J1);
    j2.setSens(Joueur::Sens::J2);
}

void AireDeJeu::lancer()
{
    char choix = 'y';
    while(choix == 'y') {
        //j1.jouer();
        //j2.jouer();
        //cout << "Voulez vous arrêter ? (o/N)" << endl;
        //cin >> choix;
    }
}
