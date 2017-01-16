#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "typeunite.h"
#include "singleton.h"
#include <iostream>

using namespace std;

class Fantassin : public Singleton<Fantassin>, public TypeUnite
{
friend class Singleton<Fantassin>;
private:
    Fantassin();
};

#endif // FANTASSIN_H
