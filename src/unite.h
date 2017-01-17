#ifndef UNITE_H
#define UNITE_H

#include "typeunite.h"

class Unite
{
private:
    int case_;
    int pointsVie;
    TypeUnite *type;
public:
    Unite(TypeUnite *type, int _case_);
    void afficher() const;
};

#endif // UNITE_H
