#include <iostream>

#include "joueur.h"

using namespace std;

Joueur::Joueur(string _nom) : nom(_nom), argent(0), vieBase(100)
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
    cout << "    Nom : " << nom << endl;
    cout << "    Sens : " << (sens == Joueur::Sens::J1 ? "de la case 1 vers la case 12" : "de la case 12 vers la case 1")
         << endl;
    cout << "    Argent : " << argent << endl;
    if (!unites.empty()) {
        cout << "    Unités : " << endl;
        for (Unite const &unite : unites) {
            unite.afficher();
        }
    }
}

bool Joueur::acheter(TypeUnite &typeUnite) {
    if (argent >= typeUnite.getPrix()) {
        unites.push_back(Unite(&typeUnite, 0));
        argent -= typeUnite.getPrix();

        return true;
    }

    return false;
}

void Joueur::incrArgent(int _argent) {
    argent += _argent;
}

void Joueur::jouer() {

}
