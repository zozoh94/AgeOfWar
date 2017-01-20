#include <iostream>

#include "unite.h"
#include "joueur.h"

using namespace std;

Unite::Unite(TypeUnite *_type, Joueur &_joueur, int _case_) : case_(_case_), joueur(_joueur), type(_type)
{
    pointsVie = type->pointsVieBase;
}

void Unite::afficher() const
{
    cout << "        Unite : " << endl;
    cout << "            Points de vie : " << pointsVie << endl;
    cout << "            Points d'attaque : " << type->pointsAttaque << endl;
    cout << "            Type : " << type->nom << endl;
    cout << "            Case : " << case_ << endl;
    cout << "            Joueur : " << joueur.getNom() << endl;
}

int Unite::getCase() const {
    return case_;
}

Joueur* Unite::getJoueur() const {
    return &joueur;
}

void Unite::action1() {
    type->action1(this);
}

void Unite::action2() {
    type->action2(this);
}

void Unite::action3() {
    type->action3(this);
}

void Unite::decrVie(int vie) {
    pointsVie -= vie;
}

void Unite::setCase(int _case_) {
    case_ = _case_;
}

bool Unite::estMort() const {
    return pointsVie <= 0;
}