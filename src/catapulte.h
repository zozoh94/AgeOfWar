#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "typeunite.h"
#include "singleton.h"

class Catapulte :  public Singleton<Catapulte>,  public TypeUnite
{
friend class Singleton<Catapulte>;
private:
    Catapulte();
    virtual void action1(Unite* unite) const;
    virtual void action2(Unite* unite) const;
    virtual void action3(Unite* unite) const;
};

#endif // CATAPULTE_H
