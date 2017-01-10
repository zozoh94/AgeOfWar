#include <iostream>

#include "joueur.h"

using namespace std;

Joueur::Joueur(string _nom) : nom(_nom)
{
}

Joueur::Sens Joueur::getSens() const
{
    return sens;
}

Joueur& Joueur::setSens(Joueur::Sens _sens)
{
    sens = _sens;
    
    return *this;
}

void Joueur::afficher() const {
    cout << "   Nom : " << nom << endl;
    cout << "   Sens : " << (sens == Joueur::Sens::J1 ? "de la case 1 vers la case 12" : "de la case 12 vers la case 1")
         << endl;
    if (!unites.empty()) {
        cout << "   Unités : " << endl;
        for (Unite const &unite : unites) {
            unite.afficher();
        }
    }
}
