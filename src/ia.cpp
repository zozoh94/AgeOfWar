#include <iostream>

#include "ia.h"
#include "fantassin.h"
#include "archer.h"
#include "catapulte.h"

using namespace std;

void IA::choisir()
{
    Fantassin *fantassin = Fantassin::getInstance();
    Archer *archer = Archer::getInstance();
    Catapulte *catapulte = Catapulte::getInstance();

    TypeUnite *typeUnite;

    if (argent < 10)
        cout << endl << nom << "ne fait rien. Il lui reste " << argent << " d'or." << endl;

    while (argent >= 10) {
        if (argent >= 20)
            typeUnite = catapulte;
        else if (argent >= 12)
            typeUnite = archer;
        else
            typeUnite = fantassin;

        if (acheter(*typeUnite))
            cout << endl << nom << "a achete un " << typeUnite->getNom() << ". Il lui reste " << argent << " d'or." << endl;
        else {
            cout << endl << nom << "ne fait rien. Il lui reste " << argent << " d'or." << endl;
            break;
        }
    }

}

void IA::afficher() const
{
    cout << "    Type : IA" << endl;
    Joueur::afficher();
}
