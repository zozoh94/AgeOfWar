#include <iostream>

#include "ia.h"
#include "fantassin.h"
#include "archer.h"
#include "catapulte.h"

using namespace std;

void IA::choisir()
{
    // Afficher tour
    cout << std::endl << "Tour de " << nom << endl << "---" << endl << endl;

    Fantassin *fantassin = Fantassin::getInstance();
    Archer *archer = Archer::getInstance();
    Catapulte *catapulte = Catapulte::getInstance();

    TypeUnite *typeUnite;
    while (argent >= 10) {
        if (argent >= 20)
            typeUnite = catapulte;
        else if (argent >= 12)
            typeUnite = archer;
        else
            typeUnite = fantassin;

        acheter(*typeUnite);
        cout << nom << "a achete un " << typeUnite->getNom() << "." << endl;
    }

}

void IA::afficher() const
{
    cout << "    Type : IA" << endl;
    Joueur::afficher();
}
