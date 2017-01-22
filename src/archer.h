#ifndef ARCHER_H
#define ARCHER_H

#include "typeunite.h"
#include "singleton.h"

class Archer :  public Singleton<Archer>, public TypeUnite
{
friend class Singleton<Archer>;
private:
    Archer();
    virtual void action1(Unite* unite);
    virtual void action2(Unite* unite);
    virtual void action3(Unite* unite);
};

#endif // ARCHER_H
