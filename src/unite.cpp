#include <iostream>

#include "unite.h"
#include "joueur.h"

using namespace std;

Unite::Unite(TypeUnite *_type, Joueur &_joueur, int _case_) : case_(_case_), joueur(_joueur), type(_type), echecAction1(false)
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
}

const TypeUnite* Unite::getType() const {
    return type;
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

void Unite::setType(TypeUnite* _type) {
    type = _type;
}

bool Unite::getEchecAction1() {
    return echecAction1;
}

void Unite::setEchecAction1(bool echec) {
    echecAction1 = echec;
}
