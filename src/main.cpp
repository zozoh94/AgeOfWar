#include <iostream>

#include "ia.h"
#include "humain.h"
#include "airedejeu.h"

int main(int argc, char **argv) {
    IA ia("Alpha");
    Humain humain("Enzo");
    Humain humain2("Benoit");
    AireDeJeu jeu(humain, humain2);
    jeu.lancer();
    return 0;
}
