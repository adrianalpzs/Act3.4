#ifndef ACCESO_HPP
#define ACCESO_HPP

#include <iostream>
#include <string>
#include "MyVector.cpp"

using namespace std;

class Acceso {
public:
    int accesos;
    MyVector<string> ips;

    Acceso();
    ~Acceso();
    friend ostream& operator<<(ostream& os, const Acceso& a);
};

bool operator<(const Acceso& a1, const Acceso& a2);
bool operator>(const Acceso& a1, const Acceso& a2);
bool operator==(const Acceso& a1, const Acceso& a2);

#endif // ACCESO_HPP