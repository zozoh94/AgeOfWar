#include <iostream>

#include "ia.h"
#include "humain.h"
#include "airedejeu.h"

int main(int argc, char **argv) {
    if(argc >= 2) {
        int mode = std::stoi(argv[1]);
        Joueur *j1, *j2;
        if(mode == 1) {
            Humain humain1("Enzo");
            Humain humain2("Benoit");
            AireDeJeu jeu(humain1, humain2);
            jeu.lancer();
        } else if(mode == 2) {
            IA ia("Alpha");
            Humain humain("Benoit");
            AireDeJeu jeu(ia, humain);
            jeu.lancer();
        } else {
            IA ia1("Alpha");
            IA ia2("Omega");
            AireDeJeu jeu(ia1, ia2);
            jeu.lancer();
        }
    } else {
        cout << "Vous devez lancer le jeu comme ceci './bin/ageofwar mode', le mode peut être : " << endl;
        cout << "1 : Humain vs Humain" << endl;
        cout << "2 : IA vs Humain" << endl;
        cout << "3 : IA vs IA (partie interminable)" << endl;
    }

    return 0;
}