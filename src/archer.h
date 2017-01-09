#ifndef ARCHER_H
#define ARCHER_H

#include "typeunite.h"
#include "singleton.h"

class Archer :  public Singleton<Archer>, public TypeUnite
{
friend class Singleton<Archer>;
private:
    Archer();
};

#endif // ARCHER_H
