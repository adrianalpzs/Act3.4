#include "Arbol.hpp"

template <class T>
Arbol<T>::Arbol() { }

template <class T>
Arbol<T>::~Arbol() { }

template <class T>
bool Arbol<T>::add(T key) { 
    if(raiz == nullptr) {
        raiz = make_shared<Nodo<T>>();
        raiz->key = key;
        return true;
    }
    return raiz->add(key);
}

template <class T>
bool Arbol<T>::search(T key) { 
    if(raiz != nullptr) {
        shared_ptr<Nodo<T>> nodo = raiz->search(key);
        return nodo != nullptr;
    }
    return false;
}

template <class T>
T* Arbol<T>::search2(T key) { 
    if(raiz != nullptr) {
        shared_ptr<Nodo<T>> nodo = raiz->search(key);
        if(nodo != nullptr) {
            return &(nodo->key);
        }
    }
    return nullptr;
}

template <class T>
void Arbol<T>::visit(int n) {
    switch (n) {
    case 1:
        preOrder();
        break;

    case 2:
        inOrder();
        break;

    case 3:
        postOrder();
        break;
    
    case 4:
        levelbylevel();
        break;
        
    default:
        inOrder();
        break;
    }
}

template <class T>
void Arbol<T>::inOrder() {
    if(raiz != nullptr)
        raiz->inOrder();
}

template <class T>
void Arbol<T>::preOrder() {
    if(raiz != nullptr) 
        raiz->preOrder();
}

template <class T>
void Arbol<T>::postOrder() {
    if(raiz != nullptr) 
        raiz->postOrder();
}

template <class T>
void Arbol<T>::levelbylevel() {
    if(raiz != nullptr) 
        raiz->levelbylevel();
}

template <class T>
int Arbol<T>::height() {
    if(raiz != nullptr)
        return raiz->height();
    return 0;
}

template <class T>
T Arbol<T>::successor(T key) {
    if(raiz == nullptr)
        throw "No exite sucesor";
    shared_ptr<Nodo<T>> n = raiz->search(key);
    if(n == nullptr)
        throw "No existe sucesor";
    shared_ptr<Nodo<T>> m = n->successor();
    if(m == nullptr)
        throw "No existe sucesor";
    return m->key;
}

template <class T>
T Arbol<T>::predecessor(T key) {
    if(raiz == nullptr)
        throw "No exite predecesor";
    shared_ptr<Nodo<T>> n = raiz->search(key);
    if(n == nullptr)
        throw "No existe predecesor";
    shared_ptr<Nodo<T>> m = n->predecessor();
    if(m == nullptr)
        throw "No existe predecesor";
    return m->key;
}

template <class T>
bool Arbol<T>::del(T key) {
    if(raiz == nullptr) 
        return false;
    shared_ptr<Nodo<T>> n = raiz->search(key);
    if(n == nullptr)
        return false;
    n->del(raiz);
    return true;
}

template <class T>
void Arbol<T>::ancestors(T key) {
    if(raiz == nullptr) 
        return;
    shared_ptr<Nodo<T>> n = raiz->search(key);
    if(n == nullptr)
        return;
    n->ancestors();
}

template <class T>
int Arbol<T>::whatlevelamI(T key) {
    if(raiz != nullptr) {
        shared_ptr<Nodo<T>> _key = raiz->search(key);
        return raiz->whatlevelamI(_key);
    }
    return -1;
}

template <class T>
T Arbol<T>::max() {
    if(raiz != nullptr) {
        return raiz->max();
    }
    throw "El árbol está vacío";
}