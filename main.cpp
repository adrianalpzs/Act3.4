/*
 main.cpp
 Act 3.4 - Actividad Integral de BST (Evidencia Competencia)

 Adriana López A01656937
 Mariana Muñoz A01653166
 
 
 Se obtienen datos de un txt y son almacenadoss en un vector que se ordena por IP's, que es
 transformada en un int de 4 bytes, para después buscar la ip con busqueda binaria y almacear
 estos datos en otro txt.
 
*/

#include <iostream>
#include <string>
#include <vector>
#include "CargaBitacora.hpp"

using namespace std;

int main () {
    Arbol<Acceso>arbol = cargaBitacora("bitacoraOrdenada.txt");
    arbol.inOrder();
    vector<string>ips = IPS(arbol, 5);
    ImprimeAccesos(ips);
    return 0;
}



//Aqui se obtienen las IP con mayor número de accesos
vector<string>IPS(Arbol<Acceso>tree, int size) {
    Acceso a = tree.max();
    vector<string>temp;

    while (temp.size() < size) {
        for(int i = 0; i < a.ips.size(); i++) {
            if(temp.size() < size)
                temp.push_back(a.ips[i]);
            else
                break;
            
        }
        a = tree.befo(a);
    }

    return temp;
    
}



// Se imprime el número de accesos
void ImprimeAccesos(vector<string>ips) {
    cout << "IP's"<< to_string(ips.size()) << " = " << endl;
    for(auto a : ips) {
        cout << "\t\t\t" << a << endl;
    }
}


