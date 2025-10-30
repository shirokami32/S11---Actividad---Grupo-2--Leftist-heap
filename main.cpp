#include <iostream>
#include "leftist.h"
using namespace std;

int main() {
    Nodo* zonaA = nullptr;
    Nodo* zonaB = nullptr;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                int prio;
                string desc, ubi;
                cout << "\nPrioridad (menor = mas urgente): ";
                cin >> prio;
                cin.ignore();
                cout << "Descripcion: ";
                getline(cin, desc);
                cout << "Ubicacion: ";
                getline(cin, ubi);
                zonaA = insertar(zonaA, new Incidente(prio, desc, ubi));
                cout << "\n Incidente insertado correctamente.\n";
                break;
        }
            case 2:
                zonaA = eliminarMin(zonaA);
                break;
            case 3:
                verMin(zonaA);
                break;
           case 4:
                cout << "\n--- Creando zona B con incidentes de prueba ---\n";
                zonaB = insertar(zonaB, new Incidente(4, "Incendio leve", "Distrito Norte"));
                zonaB = insertar(zonaB, new Incidente(2, "Choque multiple", "Avenida Central"));
                cout << "Fusionando zona A con zona B...\n";
                zonaA = merge(zonaA, zonaB);
                zonaB = nullptr;
                cout << "Zonas fusionadas correctamente.\n";
                break;
            case 5:
                cout << "\n--- Estructura actual del heap ---\n";
                printHeap(zonaA, -1);
                cout << endl;
                break;
            case 6:
                cout << "\nSaliendo...\n";
                break;
            default:
                cout << "\nOpcion invalida.\n";
        }
    }while (opcion != 6);

    return 0;

} 

