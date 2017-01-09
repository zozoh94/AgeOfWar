#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "typeunite.h"
#include "singleton.h"

class Catapulte :  public Singleton<Catapulte>,  public TypeUnite
{
friend class Singleton<Catapulte>;
private:
    Catapulte();
};

#endif // CATAPULTE_H
