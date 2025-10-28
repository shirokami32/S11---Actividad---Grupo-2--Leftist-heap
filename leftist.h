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



Nodo* merge(Nodo* h1, Nodo* h2) {
    if (!h1) return h2;
    if (!h2) return h1;


    if (h1->incidente->prioridad > h2->incidente->prioridad)
        swap(h1, h2);


    h1->der = merge(h1->der, h2);
   
    int nplD = h1->der ? h1->der->npl : -1;
    int nplI = h1->izq ? h1->izq->npl : -1;
   
    if (nplI < nplD)
        swap(h1->der, h1->izq);


    h1->npl = (h1->der ? h1->der->npl : -1) + 1;


    return h1;
}

void printHeap(Nodo* heap, int nivel = 0, string lado = "Raiz") {
    if (!heap) return;


    for (int i = 0; i < nivel; i++)
        cout << "   ";


    cout << "-> [" << lado << "] "
         << "(Prioridad: " << heap->incidente->prioridad
         << ", NPL: " << heap->npl << ") "
         << heap->incidente->descripcion
         << " | " << heap->incidente->ubicacion
         << endl;


    if (heap->izq)
        printHeap(heap->izq, nivel + 1, "Izq");
    if (heap->der)
        printHeap(heap->der, nivel + 1, "Der");
}


void mostrarMenu() {
    cout << "\n===== SISTEMA DE EMERGENCIAS =====\n";
    cout << "1. Insertar nuevo incidente\n";
    cout << "2. Atender incidente mas urgente\n";
    cout << "3. Ver incidente mas urgente\n";
    cout << "4. Fusionar zonas\n";
    cout << "5. Mostrar estructura del heap\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
}



