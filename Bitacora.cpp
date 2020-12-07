#include "Bitacora.hpp"


Bitacora::Bitacora(time_t fechaHora, string ip, string razon) {
    this->fechaHora = fechaHora;
    this->ip = ip;
    this->razon = razon;    
}

Bitacora::~Bitacora() { }

void Bitacora::setFechaHora(time_t fh) { fechaHora = fh; }

void Bitacora::setRazon(string razon) { this->razon = razon; }

string Bitacora::getIP() { return ip; }

time_t Bitacora::getFechaHora() { return fechaHora; }

ostream& operator<<(ostream &os, const Bitacora &b) {
    tm ts = *std::localtime(&b.fechaHora);
    os << "fecha hora: " << b.fechaHora << " " << std::put_time(&ts,"%F %T") << " ip: " << b.ip << " razón: " << b.razon << " ";
    return os;
} 

bool operator<(const Bitacora &b1, const Bitacora &b2) { return b1.fechaHora < b2.fechaHora; }

bool operator>(const Bitacora &b1, const Bitacora &b2) { return b1.fechaHora > b2.fechaHora; }

bool operator==(const Bitacora &b1, const Bitacora &b2) { return b1.fechaHora == b2.fechaHora; }
