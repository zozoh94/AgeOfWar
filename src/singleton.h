#ifndef SINGLETONTPL_H
#define SINGLETONTPL_H

template <class T> class Singleton
{
public:
	static T& getInstance();
protected:
	static T instance;
};

#include "singleton.inc"
#endif
