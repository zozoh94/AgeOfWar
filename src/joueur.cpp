#include "joueur.h"

Joueur::Joueur(string _nom) : nom(_nom)
{
    argent = 1000;
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

const void Joueur::afficher()
{

}

bool Joueur::acheter(TypeUnite typeUnite) {
    if (argent >= typeUnite.getPrix()) {
        unites.push_back(Unite(typeUnite, 0));
        argent -= typeUnite.getPrix();

        return true;
    }

    return false;
}