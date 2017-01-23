#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "typeunite.h"
#include "singleton.h"

class Catapulte :  public Singleton<Catapulte>,  public TypeUnite
{
friend class Singleton<Catapulte>;
private:
    Catapulte();
    virtual void action1(Unite* unite);
    virtual void action2(Unite* unite);
    virtual void action3(Unite* unite);
};

#endif // CATAPULTE_H
