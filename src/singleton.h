#ifndef SINGLETONTPL_H
#define SINGLETONTPL_H

template <class T> class Singleton
{
public:
	static T* getInstance();
    ~Singleton<T>();
protected:
	static T *instance;
private:
	T& operator= (const T&){}
};

#include "singleton.inc"

#endif
