#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <vector>
#include <iostream>

using namespace std;

template<class T>
class MyVector;

template<class T>
ostream& operator<<(ostream&, const MyVector<T>&);

template <class T>
class MyVector : public vector<T> {
public:
    MyVector();
    ~MyVector();
    friend ostream& operator<< <T>(ostream&, const MyVector<T>&);
};

#endif // MYVECTOR_HPP