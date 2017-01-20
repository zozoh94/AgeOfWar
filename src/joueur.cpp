#include <iostream>

#include "joueur.h"
#include "airedejeu.h"

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
        for (Unite *unite : unites) {
            unite->afficher();
        }
    }
}

bool Joueur::acheter(TypeUnite &typeUnite) {
    if (argent >= typeUnite.getPrix()) {
        Unite *unite = new Unite(&typeUnite, *this, sens == Sens::J1 ? 1 : 10);
        aire->addUnite(unite);
        unites.push_back(unite);
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

string Joueur::getNom() const {
    return nom;
}

Joueur &Joueur::setAire(AireDeJeu *_aire) {
    aire = _aire;
}
