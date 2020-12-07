#include "Acceso.hpp"


Acceso::Acceso() { }

Acceso::~Acceso() { }

bool operator<(const Acceso& a1, const Acceso& a2) {
    return a1.accesos < a2.accesos;
}   

bool operator>(const Acceso& a1, const Acceso& a2) {
    return a1.accesos > a2.accesos;
} 

bool operator==(const Acceso& a1, const Acceso& a2) {
    return a1.accesos == a2.accesos;
} 

ostream& operator<<(ostream& os, const Acceso& a) {
    int idx = 0;
    os << a.accesos << ":" << "\t";
    for(auto acc : a.ips) {
        os << acc << "\t";
        idx++;
        if(idx % 5 == 0)
            os << "\n\t";
    }
    os << endl;
    return os;
    
}
