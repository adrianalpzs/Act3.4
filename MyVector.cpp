#include "MyVector.hpp"

template <class T>
MyVector<T>::MyVector() { }

template <class T>
MyVector<T>::~MyVector() { }

template <class T>
ostream& operator<<(ostream& os, const MyVector<T>& v) {
    os << "vector " << endl;
    for(auto a: v) {
        os << a << '\t';
    }
    os << endl;
    return os;
}