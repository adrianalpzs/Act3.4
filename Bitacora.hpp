#ifndef BITACORA_HPP
#define BITACORA_HPP

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Bitacora {    
    private: 
        time_t fechaHora;
        string ip;
        string razon;
        
    public:
        Bitacora(time_t fechaHora, string ip, string razon);
        ~Bitacora();
        
        void setFechaHora(time_t fh);
        void setRazon(string razon);
        
        string getIP();
        time_t getFechaHora();

        friend ostream& operator<<(ostream &strm, const Bitacora &b);
        friend bool operator<(const Bitacora &b1, const Bitacora &b2);
        friend bool operator>(const Bitacora &b1, const Bitacora &b2);
        friend bool operator==(const Bitacora &b1, const Bitacora &b2);
};

#endif // BITACORA_HPP