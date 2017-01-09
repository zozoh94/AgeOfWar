#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "typeunite.h"
#include "singleton.h"

class Fantassin : public Singleton<Fantassin>, public TypeUnite
{
friend class Singleton<Fantassin>;
private:
    Fantassin();
};

#endif // FANTASSIN_H
