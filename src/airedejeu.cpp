#include <iostream>
#include <iomanip>

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

        afficherVue();

        joueur1.incrArgent(8);
        joueur2.incrArgent(8);
        joueur1.jouer();
        joueur2.jouer();

        cout << "                        \\/" << endl;

        afficherVue();

        if(joueur1.estMort() || joueur2.estMort())
            break;

        joueur1.choisir();
        joueur2.choisir();

        /*cout << endl << "Voulez vous continuer ? (o/N)" << endl;
        cin >> choix;*/
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

void AireDeJeu::afficherVue() const
{
    // Nom des bases
    cout << " ";
    for (int i = 0 ; i < 11 ; i++)
        if (i == 0 || i == 11) cout << "___ ";
        else cout << "    ";
    cout << "___" << endl;
    string base1 = "| " + joueur1.getNom() + " |";
    string base2 = "| " + joueur2.getNom() + " |";
    cout << setw(40) << left << base1 << base2 << endl;
    /*for (int i = 1 ; i < 11 ; i++)
        if (i < 10) cout << "    ";
        else cout << "   ";*/

    // Top
    cout << "|";
    for (int i = 0 ; i < 11 ; i++)
    {
            cout << "____";
    }
    cout << "___|" << endl << "|";

    // inside
    for (int j = 0; j < 2 ; j++) {
        for (int i = 0 ; i < 12 ; i++) {
            cout << " ";

            bool found = false;
            for (auto it = unites.begin(); it != unites.end(); ++it) {
                if (it->second->getCase() == i) {
                    if (j == 0)
                        //cout << " ";
                        cout << it->second->getJoueur()->getNom()[0];
                    else
                        if (it->second->getType()->getNom() == "Fantassin")
                            cout << "F";
                        else if (it->second->getType()->getNom() == "Archer")
                            cout << "A";
                        if (it->second->getType()->getNom() == "Catapulte")
                            cout << "C";

                    found = true;
                }
            }
            if (!found) cout << " ";

            cout << " |";
        }

        cout << endl << "|";
    }

    // Bottom
    for (int i = 0 ; i < 12 ; i++)
    {
        cout << "___|";
    }

    cout << endl;
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
