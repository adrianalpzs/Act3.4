#ifndef ARBOL
#define ARBOL

#include <memory>
#include "Nodo.cpp"

using namespace std;

template <class T>
class Arbol {
private:
    shared_ptr<Nodo<T>> raiz;

public:
    Arbol();
    ~Arbol();
    bool add(T); // Agregar nodo
    bool search(T); // Buscar un nodo en específico
    T* search2(T); // Busca un nodo y nos regresa el nodo
    void inOrder(); // Ordenamiento inOrder 
    void preOrder(); // Ordenamiento preOrder
    void postOrder(); // Ordenamiento postOrder
    void levelbylevel(); // Ordenamiento levelbylevel
    void visit(int n); // Visita ordenamiento 
    int height(); // Altura de un nodo en específico
    T successor(T); // Sucesor de un nodo en específico
    T predecessor(T); // Predecesor de un nodo en específico
    bool del(T); // Borrado de un nodo
    void ancestors(T); // Ancestros de un nodo en específico
    int whatlevelamI(T); // Nivel de un nodo en específico
    T max();
};
    
#endif // ARBOL