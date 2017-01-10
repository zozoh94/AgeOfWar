#include <iostream>

#include "humain.h"

using namespace std;

void Humain::jouer()
{
}

void Humain::afficher() const
{
    cout << "   Type : Humain" << endl;
    Joueur::afficher();
}

