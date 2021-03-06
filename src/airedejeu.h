#ifndef AIREDEJEU_H
#define AIREDEJEU_H

#define SSTR( x ) static_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()

#include <map>

#include "joueur.h"

class AireDeJeu
{
private:
    Joueur &joueur1;
    Joueur &joueur2;
    int tour;
    //On utilise une map pour s'assurer qu'il y a toujours une seule unite par case
    //De plus elle permettra de supprimer toutes les unites qui sont encore sur le plateau à la fin
    map<int, Unite*> unites;
public:
    AireDeJeu(Joueur& j1, Joueur& j2);
    ~AireDeJeu();
    bool addUnite(Unite *unite);
    void lancer();
    void afficher() const;
    void afficherVue() const;
    static Joueur* getAdversaire(AireDeJeu* aire, Joueur* joueur);
    bool attaquer(Joueur* joueur, int case_, int attaque);
    void avancer(Unite* unite);
};

#endif // AIREDEJEU_H
