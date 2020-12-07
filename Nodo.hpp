#ifndef NODO
#define NODO

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <memory>

using namespace std;

template <class T>
class Arbol;

template <class T>
class Nodo : public enable_shared_from_this<Nodo<T>> {
private:
    shared_ptr<Nodo<T>> left;
    shared_ptr<Nodo<T>> right;
    shared_ptr<Nodo<T>> father;        
    T key;

public:
    Nodo();
    ~Nodo();
    
    friend class Arbol<T>;
    bool add(T); // Agregar nodo
    shared_ptr<Nodo<T>> search(T); // Buscar un nodo en específico
    void inOrder(); // Ordenamiento inOrder 
    void preOrder(); // Ordenamiento preOrder
    void postOrder(); // Ordenamiento postOrder
    void levelbylevel(); // Ordenamiento levelbylevel
    int height(); // Altura de un nodo en específico
    void ancestors(); // Ancestros de un nodo en específico 
    shared_ptr<Nodo<T>> successor(); // Sucesor de un nodo en específico
    shared_ptr<Nodo<T>> predecessor(); // Precesor de un nodo en específico
    void del(shared_ptr<Nodo<T>> &); // Borrado de un nodo
    int whatlevelamI(shared_ptr<Nodo<T>> &); // Nivel de un nodo en específico
    T max();
};
    
#endif // NODO