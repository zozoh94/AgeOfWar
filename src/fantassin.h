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
    virtual void action1(Unite* unite) const;
    virtual void action2(Unite* unite) const;
    virtual void action3(Unite* unite) const;
};

#endif // FANTASSIN_H
