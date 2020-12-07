#include "CargaBitacora.hpp"


Arbol<Acceso>cargaBitacora(string archivo) {
    Arbol<Acceso>bitacoras; // Arbol de Accesos que regresaremos al final del método
    ifstream f;
    string mes, dia, tiempo;
    string ip, puerto, razon;
    int idx = 0; // Índices
    string ip_a = "";  // IP's

    
    f.open(archivo); // Abrimos el archivo de texto
    while (!f.eof()) { // Ejecutará el archivo de texto hasta que este vacío
        getline(f, mes, ' ');
        getline(f, dia, ' ');
        getline(f, tiempo, ' ');
        tm ts;
        ts.tm_isdst = 1;
        string tss = "2019 " + mes + " " + dia + " " + tiempo; 
        strptime(tss.c_str(),"%Y %b %d %H:%M:%S", &ts);
        time_t fechaHora = mktime(&ts);
        getline(f, ip, ':');
        getline(f, puerto, ' ');
        getline(f, razon);

        if(ip_a == "") { // Preguntamos si la ip anterior está vacía
            ip_a = ip; 
            idx = 1;
        }
        else if(ip_a == ip) { // Preguntamos si la ip anterior es igual a la actual
            idx++;
        }
        else { // Si las ip's son distintas significa que debemos guardar dicha ip
            Acceso acc;
            acc.accesos = idx;
            Acceso *accVec;
            if((accVec = bitacoras.search2(acc)) != nullptr) { // Preguntamos si el número de acceso se encuentra en el arbol
                accVec->ips.push_back(ip_a); // Insertamos la ip en el nodo correspondiente en caso de encontrar que ya existía el número de acceso
            }
            else { // En caso de no encontrar el número de acceso ya insertado, lo insertamos en el arbol
                acc.ips.push_back(ip_a); 
                bitacoras.add(acc);
            }
            ip_a = ""; // IP anterior la igualamos a "vacío"
        }
    }
    
    // Se realiza una vez más para agregar a las últimas IPS
    Acceso acc;
    acc.accesos = idx;
    Acceso *accVec;
    if((accVec = bitacoras.search2(acc)) != nullptr) {
        accVec->ips.push_back(ip_a);
    }
    else {
        acc.ips.push_back(ip_a);
        bitacoras.add(acc);
    }

    f.close();
    return bitacoras;
}
