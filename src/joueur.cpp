#include "joueur.h"

Joueur::Joueur(string _nom) : nom(_nom)
{
}

const Joueur::Sens Joueur::getSens()
{
    return sens;
}

Joueur& Joueur::setSens(Joueur::Sens _sens)
{
    sens = _sens;
    
    return *this;
}
