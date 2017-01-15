#include <iostream>
#include "humain.h"
#include "fantassin.h"
#include "archer.h"
#include "supersoldat.h"

void Humain::jouer()
{
    int joueurChoix;

    // Afficher statistiques joueur
    cout << std::endl << "Tour de " << nom << endl << "---" << endl << endl;
    cout << "Que voulez-vous acheter ? (" << argent << " or)" << endl;

    cout << "1. Fantassin (50o)"  << endl;
    cout << "2. Archer (75o)"  << endl;
    cout << "3. Super soldat (200o)"  << endl;

    cin >> joueurChoix;

    TypeUnite *typeUnite;
    switch (joueurChoix) {
        case 1:
            typeUnite = &Fantassin::getInstance();
            break;
        case 2:
            typeUnite = &Archer::getInstance();
            break;
        case 3:
            typeUnite = &SuperSoldat::getInstance();
            break;
    }

    if (acheter(*typeUnite))
        cout << "Vous avez acheté un " << typeUnite->getNom() << "." << endl;
    else
        cout << "Vous n'avez pas assez d'argent pour acheter un " << typeUnite->getNom() << "." << endl;


}
