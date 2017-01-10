#include <iostream>

#include "ia.h"

using namespace std;

void IA::jouer()
{
}

void IA::afficher() const
{
    cout << "   Type : IA" << endl;
    Joueur::afficher();
}
