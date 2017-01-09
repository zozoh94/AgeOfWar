#ifndef TYPEUNITE_H
#define TYPEUNITE_H

#include <vector>

using namespace std;

class Unite;

class TypeUnite
{
friend class Unite;
protected:
    int prix;
    int pointsVieBase;
    int pointsAttaque;
    vector<int> portees;
public:
    TypeUnite(int prix, int pointsVieBase, int pointsAttaque, initializer_list<int> portees);
};

#endif // TYPEUNITE_H
