#include <iostream>

#include "ia.h"
#include "humain.h"
#include "airedejeu.h"

int main(int argc, char **argv) {
    IA ia("Alpha");
    Humain humain("Enzo");
    AireDeJeu jeu(ia, humain);
    jeu.lancer();
    return 0;
}
