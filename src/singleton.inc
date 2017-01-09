template <class T> T Singleton<T>::instance=T();

template <class T>  T& Singleton<T>::getInstance()
{
        return instance;
}
