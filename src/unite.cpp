#include <iostream>

#include "unite.h"

using namespace std;

Unite::Unite(TypeUnite *_type, int _case_) : case_(_case_), type(_type)
{
    pointsVie = type->pointsVieBase;
}

void Unite::afficher() const
{
    cout << "       Unite : " << endl;
    cout << "           Points de vie : " << pointsVie << endl;
    cout << "           Points d'attaque : " << type->pointsAttaque << endl;
    cout << "           Type : " << type->nom << endl;
    cout << "           Case : " << case_ << endl;
}
    
