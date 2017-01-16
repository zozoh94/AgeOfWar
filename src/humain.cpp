#include <iostream>

#include "humain.h"
#include "fantassin.h"
#include "archer.h"
#include "catapulte.h"

using namespace std;

void Humain::jouer()
{
    int joueurChoix;

    // Afficher statistiques joueur
    cout << std::endl << "Tour de " << nom << endl << "---" << endl << endl;
    cout << "Que voulez-vous acheter ? (" << argent << " or)" << endl;

    Fantassin *fantassin = Fantassin::getInstance();
    Archer *archer = Archer::getInstance();
    Catapulte *catapulte = Catapulte::getInstance();

    cout << "1. " << fantassin->getNom() << " (prix:" << fantassin->getPrix() << ")"  << endl;
    cout << "2. " << archer->getNom() << " (prix:" << archer->getPrix() << ")"  << endl;
    cout << "3. " << catapulte->getNom() << " (prix:" << catapulte->getPrix() << ")"  << endl;

    cin >> joueurChoix;

    TypeUnite *typeUnite;
    switch (joueurChoix) {
        case 1:
            typeUnite = fantassin;
            break;
        case 2:
            typeUnite = archer;
            break;
        case 3:
            typeUnite = catapulte;
            break;
        default:
            typeUnite = fantassin;
    }

    if (acheter(*typeUnite))
        cout << "Vous avez acheté un " << typeUnite->getNom() << "." << endl;
    else
        cout << "Vous n'avez pas assez d'argent pour acheter un " << typeUnite->getNom() << "." << endl;


}

void Humain::afficher() const
{
    cout << "   Type : Humain" << endl;
    Joueur::afficher();
}

