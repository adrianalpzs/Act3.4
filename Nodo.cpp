#include "Nodo.hpp"

template <class T>
Nodo<T>::Nodo() { }

template <class T>
Nodo<T>::~Nodo() { }

template <class T>
bool Nodo<T>::add(T _key) { 
    if(_key == key)
        return false;
    
    if(_key < key) {
        if(left == nullptr) {
            left = make_shared<Nodo<T>>();
            left->key = _key;
            left->father = this->shared_from_this();
            return true;
        }
        return left->add(_key);
    }
    if(right == nullptr) {
        right = make_shared<Nodo<T>>();
        right->key = _key;
        right->father = this->shared_from_this();
        return true;
    }
    return right->add(_key);
}

template <class T>
shared_ptr<Nodo<T>> Nodo<T>::search(T _key) { 
    if(_key == key)
        return this->shared_from_this();

    if(_key < key) {
        if(left == nullptr) {
            return nullptr;
        }
        return left->search(_key);
    }
    if(right == nullptr) {
        return nullptr;
    }
    return right->search(_key);
}

template <class T>
void Nodo<T>::inOrder() {
    if(left != nullptr) 
        left->inOrder();
    cout << key << endl;
    if(right != nullptr) 
        right->inOrder();
}

template <class T>
void Nodo<T>::preOrder() {
    cout << key << endl;
    if(left != nullptr) 
        left->preOrder();
    if(right != nullptr) 
        right->preOrder();
}

template <class T>
void Nodo<T>::postOrder() {
    if(left != nullptr) 
        left->preOrder();
    if(right != nullptr) 
        right->preOrder();
    cout << key << endl;
}

template <class T>
void Nodo<T>::levelbylevel() {
    queue<shared_ptr<Nodo<T>>> pila;
    pila.push(this->shared_from_this());

    while (!pila.empty()){
        shared_ptr<Nodo<T>> nodo = pila.front();
        pila.pop();
        cout << nodo->key << endl;
        if(nodo->left != nullptr)
            pila.push(nodo->left);
        if(nodo -> right != nullptr)
            pila.push(nodo->right);
    }
}

template <class T>
int Nodo<T>::height() { 
    int hl, hr = 0;
    if(left != nullptr)
        hl = left->height();
    if(right != nullptr)
        hr = right->height();
    return max(hl, hr) + 1;
}

template <class T>
void Nodo<T>::ancestors() {
    shared_ptr<Nodo<T>> ptr = father;
    while (ptr != nullptr) {
        cout << ptr->key << endl;
        ptr = ptr->father;
    }
}

template <class T>
shared_ptr<Nodo<T>> Nodo<T>::successor() {
    shared_ptr<Nodo<T>> m = right;
    if(m == nullptr) {
        if(father->left == this->shared_from_this())
            return father;
        else
            return nullptr;
    }
    while (m->left != nullptr) {
        m = m->left;
    }
    return m;
}

template <class T>
shared_ptr<Nodo<T>> Nodo<T>::predecessor() {
    shared_ptr<Nodo<T>> m = left;
    if(m == nullptr) {
        if(father->right == this->shared_from_this())
            return father;
        else
            return nullptr;
    }
    while (m->right != nullptr) {
        m = m->right;
    }
    return m;
} 

template <class T>
void Nodo<T>::del(shared_ptr<Nodo<T>> &raiz) {
    if(left != nullptr && right != nullptr) {
        shared_ptr<Nodo<T>> ptr = successor();
        T tmp = ptr->key;
        ptr->key = key;
        key = tmp;
        ptr->del(raiz);
        return;
    }
    if(raiz == this->shared_from_this()) {
        raiz = (left != nullptr) ? left : right;
        return;
    }
    if(father->right == this->shared_from_this()) {
        father->right = (left != nullptr) ? left : right;
        if(father->right != nullptr)
            father->right->father = father;
    }
    else {
        father->left = (left != nullptr) ? left : right;
        if(father->left != nullptr)
            father->left->father = father;
    }
}

template <class T>
int Nodo<T>::whatlevelamI(shared_ptr<Nodo<T>> &nodo) {
    if(nodo == nullptr)
        return -1;
    int alturaNodo = nodo->height();
    return height() - alturaNodo;
}

template <class T>
T Nodo<T>::max() {
    shared_ptr<Nodo<T>> tmp = this->shared_from_this();
    while(tmp->right != nullptr) {
        tmp = tmp->right;
    }
    return tmp->key;
}