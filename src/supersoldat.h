#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include "typeunite.h"
#include "singleton.h"

class SuperSoldat : public Singleton<SuperSoldat>, public TypeUnite
{
friend class Singleton<SuperSoldat>;
private:
    SuperSoldat();
};

#endif // SUPERSOLDAT_H
