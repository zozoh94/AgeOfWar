#include "unite.h"

Unite::Unite(TypeUnite &_type, int _case_) : case_(_case_), type(_type)
{
    pointsVie = type.pointsVieBase;
}
