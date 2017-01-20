#include <iostream>

template <class T> T* Singleton<T>::instance = NULL;

template <class T>  T* Singleton<T>::getInstance()
{
    if(!instance)
        instance = new T();
    return instance;
}

template <class T> void Singleton<T>::kill()
{
    delete instance;
}