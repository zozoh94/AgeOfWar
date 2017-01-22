#include <iostream>

#include "joueur.h"
#include "airedejeu.h"

using namespace std;

Joueur::Joueur(string _nom) : nom(_nom), argent(8), vieBase(100)
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
    cout << "    Vie : " << vieBase << endl;
    cout << "    Sens : " << (sens == Sens::J1 ? "de la case 1 vers la case 12" : "de la case 12 vers la case 1")
         << endl;
    cout << "    Argent : " << argent << endl;
    if (!unites.empty()) {
        cout << "    Unités : " << endl;
        if(sens == Sens::J1) {
            for (auto it = unites.begin(); it != unites.end(); ++it) {
                it->second->afficher();
            }
        } else {
            for (auto it = unites.rbegin(); it != unites.rend(); ++it) {
                it->second->afficher();
            }
        }
    }
}

bool Joueur::acheter(TypeUnite &typeUnite) {
    if (argent >= typeUnite.getPrix()) {
        Unite *unite = new Unite(&typeUnite, *this, sens == Sens::J1 ? 0 : 11);
        if(unites.find(unite->getCase()) == unites.end()){
            if(aire->addUnite(unite)) {
                unites.insert({unite->getCase(), unite});
                argent -= typeUnite.getPrix();
            } else {
                return false;
            }
        } else {
            delete unite;
            return false;
        }

        return true;
    }

    return false;
}

void Joueur::incrArgent(int _argent) {
    argent += _argent;
}

void Joueur::jouer() {
    //cout << nom << " joue" << endl;
    //Action1
    for(auto it = unites.begin();it != unites.end(); ++it) {
        it->second->action1();
    }
    //Action2
    for(auto it = unites.rbegin();it != unites.rend(); ++it) {
        it->second->action2();
    }
    //Action3
    for(auto it = unites.rbegin();it != unites.rend(); ++it) {
        it->second->action3();
    }
}

string Joueur::getNom() const {
    return nom;
}

int Joueur::getVieBase() const {
    return vieBase;
}

Joueur &Joueur::setAire(AireDeJeu *_aire) {
    aire = _aire;
    return *this;
}

AireDeJeu *Joueur::getAire() {
    return aire;
}

Joueur *Joueur::getAdversaire() {
    return AireDeJeu::getAdversaire(aire, this);
}

void Joueur::decrVie(int vie) {
    vieBase -= vie;
}

bool Joueur::estMort() const {
    return vieBase <= 0;
}

void Joueur::avancerUnite(Unite* unite) {
    unites.erase(unite->getCase());
    if(sens == J1)
        unite->setCase(unite->getCase()+1);
    else
        unite->setCase(unite->getCase()-1);
    aire->addUnite(unite);
    unites.insert({unite->getCase(), unite});
}

void Joueur::supprimerUnite(int case_) {
    delete unites.find(case_)->second;
    unites.erase(case_);
}
