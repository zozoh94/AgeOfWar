#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include "typeunite.h"
#include "singleton.h"

class SuperSoldat : public Singleton<SuperSoldat>, public TypeUnite
{
friend class Singleton<SuperSoldat>;
private:
    SuperSoldat();
    virtual void action1(Unite* unite) const;
    virtual void action2(Unite* unite) const;
    virtual void action3(Unite* unite) const;
};

#endif // SUPERSOLDAT_H
