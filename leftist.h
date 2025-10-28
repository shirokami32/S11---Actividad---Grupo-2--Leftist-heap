#include <iostream>
#include <string> 

using namespace std;

struct Incidente {
    int prioridad;
    string descripcion;
    string ubicacion;

    Incidente(int p, string d, string u)
        : prioridad(p), descripcion(d), ubicacion(u) {}
};

struct Nodo {
    Incidente* incidente;
    int npl;
    Nodo* izq;
    Nodo* der;

    Nodo(Incidente* i)
        : incidente(i), npl(0), izq(nullptr), der(nullptr) {}
};

// Insertando un nuevo incidente en el heap
Nodo* merge(Nodo* h1, Nodo* h2);

Nodo* insertar(Nodo* heap, Incidente* nuevo) {
    Nodo* nuevoNodo = new Nodo(nuevo);
    return merge(heap, nuevoNodo);
}


Nodo* eliminarMin(Nodo* head){
    if(!heap) return nullptr;

    Nodo *nuevo = merge(head->izq, head->der);
    cout << "\n Incidente atendido: "
         << heap->incidente->descripcion
         << " | Ubicacion: " << heap->incidente->ubicacion
         << " | Prioridad: " << heap->incidente->prioridad << endl;
    delete heap->incidente;
    delete heap;
    return nuevo;
}

//Funcionalidad que muestra el incidente mas urgente sin eliminarlo
void verMin(Nodo* heap){
    if(!heap){
        cout<<"\n No hay incidentes pendientes. \n";
        return;
    }
    cout << "\n Incidente mas urgente:\n";
    cout << "   Descripcion: " << heap->incidente->descripcion << endl;
    cout << "   Ubicacion: " << heap->incidente->ubicacion << endl;
    cout << "   Prioridad: " << heap->incidente->prioridad << endl;
}

void printHeap(Nodo* heap, int padre){
    if(!heap) return;

    cout<<endl<<"Valor actual: "<<heap->dato;
    cout<<", Padre" << padre;
    cout<<", NPL: "<<heap->npl;

    cout<<endl<<"Hijo Izquierdo: ";
    printHeap(heap->izq, heap->dato);
    cout<<endl<<"Hijo Derecho: ";
    printHeap(heap->der, heap->dato);
}



int main(){

    Nodo* heap = nullptr;

    heap = insertar(heap, 10);
    heap = insertar(heap, 5);
    heap = insertar(heap, 20);
    heap = insertar(heap, 3);
    heap = insertar(heap, 11);
    heap = insertar(heap, 16);
    heap = insertar(heap, 30);
    heap = insertar(heap, 42);

    cout<<endl<<endl<<"Recorrido Preorden: ";
    printHeap(heap, -1);

    heap = eliminarMin(heap);
    heap = eliminarMin(heap);

    cout<<endl<<endl<<"Recorrido Preorden: ";
    printHeap(heap, -1);

    return 0;
}
