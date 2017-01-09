#ifndef TYPEUNITE_H
#define TYPEUNITE_H

class Unite;

class TypeUnite
{
friend class Unite;
protected:
    int prix;
    int pointsVieBase;
    int pointsAttaque;
    int portee;
};

#endif // TYPEUNITE_H
