// ProyectoFinalC++Consola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <string>
#include "Cola.h"  // Reemplaza con el nombre correcto de tus archivos de encabezado
#include "Pila.h"
#include "Arbol.h"
#include "ListaEnlazada.h"
#include "Grafo.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Bubblesort.h"  // Asegúrate de incluir el archivo de encabezado correcto para cada algoritmo de ordenamiento
#include "Cocktail_sort.h"
#include "InsertionSort.h"
#include "Bucket_sort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "BinaryTreeSort.h"
#include "RadixSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "Heapsort.h"
#include "Quicksort.h"

using namespace std;


// Declaraciones de funciones
void MostrarFuncionesBasicas(string nombreEstructura, EstructuraBase estructura);
void RealizarOperacionesArbol(Arbol& arbol);
int main()
{
    Cola cola;
    Pila pila;
    Arbol arbol;
    ListaEnlazada listaEnlazada;
    Grafo grafo;

    while (true) {
        cout << "Elija una estructura de datos:" << endl;
        cout << "1. Cola" << endl;
        cout << "2. Pila" << endl;
        cout << "3. Árbol" << endl;
        cout << "4. Lista Enlazada" << endl;
        cout << "5. Grafo" << endl;
        cout << "6. Algoritmos de Ordenamiento" << endl;
        cout << "0. Salir" << endl;

        cout << "Ingrese su elección: ";
        string opcion;
        getline(cin, opcion);

        switch (stoi(opcion)) {
        case 1:
            RealizarOperacionesCola(cola);
            break;
        case 2:
            RealizarOperacionesPila(pila);
            break;
        case 3:
            RealizarOperacionesArbol(arbol);
            break;
        case 4:
            RealizarOperacionesListaEnlazada(listaEnlazada);
            break;
        case 5:
            RealizarOperacionesGrafo(grafo);
            break;
        case 6:
            RealizarOperacionesOrdenamiento(listaEnlazada);
            break;
        case 0:
            cout << "Saliendo del programa. ¡Hasta luego!" << endl;
            return 0;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }
    }

    return 0;
}
void RealizarOperacionesCola(Cola& cola) {
    while (true) {
        cout << "Operaciones de la Cola:" << endl;
        cout << "1. Encolar" << endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Mostrar Cola" << endl;
        cout << "0. Volver al menú principal" << endl;

        cout << "Ingrese su elección: ";
        string opcionCola;
        getline(cin, opcionCola);

        switch (stoi(opcionCola)) {
        case 1: {
            cout << "Ingrese el valor a encolar: ";
            int valorEncolar;
            cin >> valorEncolar;
            cola.Encolar(valorEncolar);
            break;
        }
        case 2:
            cola.Desencolar();
            break;
        case 3:
            cout << "Cola actual:" << endl;
            cola.MostrarCola();
            break;
        case 0:
            return;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpiar el buffer de entrada
    }
}
void RealizarOperacionesPila(Pila& pila) {
    while (true) {
        cout << "Operaciones de la Pila:" << endl;
        cout << "1. Apilar" << endl;
        cout << "2. Desapilar" << endl;
        cout << "3. Mostrar Pila" << endl;
        cout << "0. Volver al menú principal" << endl;

        cout << "Ingrese su elección: ";
        string opcionPila;
        getline(cin, opcionPila);

        switch (stoi(opcionPila)) {
        case 1: {
            cout << "Ingrese el valor a apilar: ";
            int valorApilar;
            cin >> valorApilar;
            pila.Apilar(valorApilar);
            break;
        }
        case 2:
            pila.Desapilar();
            break;
        case 3:
            cout << "Pila actual:" << endl;
            pila.MostrarPila();
            break;
        case 0:
            return;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpiar el buffer de entrada
    }
}
void RealizarOperacionesListaEnlazada(ListaEnlazada& listaEnlazada) {
    while (true) {
        cout << "Operaciones de la Lista Enlazada:" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Eliminar elemento" << endl;
        cout << "3. Mostrar Lista Enlazada" << endl;
        cout << "0. Volver al menú principal" << endl;

        cout << "Ingrese su elección: ";
        string opcionLista;
        getline(cin, opcionLista);

        switch (stoi(opcionLista)) {
        case 1: {
            cout << "Ingrese el valor a insertar: ";
            int valorInsertar;
            cin >> valorInsertar;
            listaEnlazada.InsertarElemento(valorInsertar);
            break;
        }
        case 2: {
            cout << "Ingrese el valor a eliminar: ";
            int valorEliminar;
            cin >> valorEliminar;
            listaEnlazada.EliminarElemento(valorEliminar);
            break;
        }
        case 3:
            cout << "Lista Enlazada actual:" << endl;
            listaEnlazada.MostrarLista();
            break;
        case 0:
            return;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpiar el buffer de entrada
    }
}
void RealizarOperacionesGrafo(Grafo& grafo) {
    while (true) {
        cout << "Operaciones del Grafo:" << endl;
        cout << "1. Agregar vértice" << endl;
        cout << "2. Agregar arista" << endl;
        cout << "3. Mostrar Grafo" << endl;
        cout << "4. Búsqueda en Profundidad (DFS)" << endl;
        cout << "5. Búsqueda en Amplitud (BFS)" << endl;
        cout << "0. Volver al menú principal" << endl;

        cout << "Ingrese su elección: ";
        string opcionGrafo;
        getline(cin, opcionGrafo);

        switch (stoi(opcionGrafo)) {
        case 1: {
            cout << "Ingrese el nombre del vértice a agregar: ";
            string nombreVertice;
            getline(cin, nombreVertice);
            grafo.AgregarVertice(nombreVertice);
            break;
        }
        case 2: {
            cout << "Ingrese el nombre del vértice de origen: ";
            string origen;
            getline(cin, origen);
            cout << "Ingrese el nombre del vértice de destino: ";
            string destino;
            getline(cin, destino);
            grafo.AgregarArista(origen, destino);
            break;
        }
        case 3:
            cout << "Grafo actual:" << endl;
            grafo.MostrarGrafo();
            break;
        case 4: {
            cout << "Ingrese el vértice de inicio para DFS: ";
            string inicioDFS;
            getline(cin, inicioDFS);
            grafo.BusquedaProfundidad(inicioDFS);
            break;
        }
        case 5: {
            cout << "Ingrese el vértice de inicio para BFS: ";
            string inicioBFS;
            getline(cin, inicioBFS);
            grafo.BusquedaAmplitud(inicioBFS);
            break;
        }
        case 0:
            return;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpiar el buffer de entrada
    }
}

void MostrarFuncionesBasicas(string nombreEstructura, EstructuraBase estructura) {
    cout << "Funciones básicas de " << nombreEstructura << ":" << endl;
    estructura.MostrarFunciones();
    cout << endl;
}

void RealizarOperacionesArbol(Arbol& arbol) {
    while (true) {
        cout << "Operaciones del Árbol:" << endl;
        cout << "1. Insertar nodo" << endl;
        cout << "2. Eliminar nodo" << endl;
        cout << "3. Mostrar Árbol" << endl;
        cout << "0. Volver al menú principal" << endl;

        cout << "Ingrese su elección: ";
        string opcionArbol;
        getline(cin, opcionArbol);

        switch (stoi(opcionArbol)) {
        case 1:
            cout << "Ingrese el valor del nuevo nodo: ";
            int valorNodo;
            cin >> valorNodo;
            arbol.InsertarNodo(valorNodo);
            break;
        case 2:
            cout << "Ingrese el valor del nodo a eliminar: ";
            int valorEliminar;
            cin >> valorEliminar;
            arbol.EliminarNodo(valorEliminar);
            break;
        case 3:
            cout << "Árbol actual:" << endl;
            arbol.MostrarArbol();
            break;
        case 0:
            return;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }
    }
}
void RealizarOperacionesOrdenamiento(ListaEnlazada& listaEnlazada) {
    while (true) {
        cout << "Algoritmos de Ordenamiento:" << endl;
        cout << "1. Bubblesort" << endl;
        cout << "2. Cocktail sort" << endl;
        cout << "3. Insertion sort" << endl;
        cout << "4. Bucket sort" << endl;
        cout << "5. Counting sort" << endl;
        cout << "6. Merge sort" << endl;
        cout << "7. Binary tree sort" << endl;
        cout << "8. Radix sort" << endl;
        cout << "9. Shell sort" << endl;
        cout << "10. Selection sort" << endl;
        cout << "11. Heapsort" << endl;
        cout << "12. Quicksort" << endl;
        cout << "0. Volver al menú principal" << endl;

        cout << "Ingrese su elección: ";
        string opcionOrdenamiento;
        getline(cin, opcionOrdenamiento);

        switch (stoi(opcionOrdenamiento)) {
        case 1: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputBubblesort;
            getline(cin, inputBubblesort);
            vector<int> valoresBubblesort;
            istringstream issBubblesort(inputBubblesort);
            int valorBubblesort;
            while (issBubblesort >> valorBubblesort) {
                valoresBubblesort.push_back(valorBubblesort);
            }
            Bubblesort::OrdenarBurbuja(valoresBubblesort);
            break;
        }
        case 2: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputCocktailSort;
            getline(cin, inputCocktailSort);
            vector<int> valoresCocktailSort;
            istringstream issCocktailSort(inputCocktailSort);
            int valorCocktailSort;
            while (issCocktailSort >> valorCocktailSort) {
                valoresCocktailSort.push_back(valorCocktailSort);
            }
            CocktailSort::OrdenarCocktail(valoresCocktailSort);
            break;
        }
        case 3: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputInsertionSort;
            getline(cin, inputInsertionSort);
            vector<int> valoresInsertionSort;
            istringstream issInsertionSort(inputInsertionSort);
            int valorInsertionSort;
            while (issInsertionSort >> valorInsertionSort) {
                valoresInsertionSort.push_back(valorInsertionSort);
            }
            InsertionSort::OrdenarInsercion(valoresInsertionSort);
            break;
        }
        case 4: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputBucketSort;
            getline(cin, inputBucketSort);
            vector<int> valoresBucketSort;
            istringstream issBucketSort(inputBucketSort);
            int valorBucketSort;
            while (issBucketSort >> valorBucketSort) {
                valoresBucketSort.push_back(valorBucketSort);
            }
            BucketSort::OrdenarBucket(valoresBucketSort);
            break;
        }
        case 5: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputCountingSort;
            getline(cin, inputCountingSort);
            vector<int> valoresCountingSort;
            istringstream issCountingSort(inputCountingSort);
            int valorCountingSort;
            while (issCountingSort >> valorCountingSort) {
                valoresCountingSort.push_back(valorCountingSort);
            }
            CountingSort::OrdenarCounting(valoresCountingSort);
            break;
        }
        case 6: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputMergeSort;
            getline(cin, inputMergeSort);
            vector<int> valoresMergeSort;
            istringstream issMergeSort(inputMergeSort);
            int valorMergeSort;
            while (issMergeSort >> valorMergeSort) {
                valoresMergeSort.push_back(valorMergeSort);
            }
            MergeSort::OrdenarMerge(valoresMergeSort);
            break;
        }
        case 7: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputBinaryTreeSort;
            getline(cin, inputBinaryTreeSort);
            vector<int> valoresBinaryTreeSort;
            istringstream issBinaryTreeSort(inputBinaryTreeSort);
            int valorBinaryTreeSort;
            while (issBinaryTreeSort >> valorBinaryTreeSort) {
                valoresBinaryTreeSort.push_back(valorBinaryTreeSort);
            }
            BinaryTreeSort::OrdenarBinaryTree(valoresBinaryTreeSort);
            break;
        }
        case 8: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputRadixSort;
            getline(cin, inputRadixSort);
            vector<int> valoresRadixSort;
            istringstream issRadixSort(inputRadixSort);
            int valorRadixSort;
            while (issRadixSort >> valorRadixSort) {
                valoresRadixSort.push_back(valorRadixSort);
            }
            RadixSort::OrdenarRadix(valoresRadixSort);
            break;
        }
        case 9: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputShellSort;
            getline(cin, inputShellSort);
            vector<int> valoresShellSort;
            istringstream issShellSort(inputShellSort);
            int valorShellSort;
            while (issShellSort >> valorShellSort) {
                valoresShellSort.push_back(valorShellSort);
            }
            ShellSort::OrdenarShell(valoresShellSort);
            break;
        }
        case 10: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputSelectionSort;
            getline(cin, inputSelectionSort);
            vector<int> valoresSelectionSort;
            istringstream issSelectionSort(inputSelectionSort);
            int valorSelectionSort;
            while (issSelectionSort >> valorSelectionSort) {
                valoresSelectionSort.push_back(valorSelectionSort);
            }
            SelectionSort::OrdenarSeleccion(valoresSelectionSort);
            break;
        }
        case 11: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputHeapsort;
            getline(cin, inputHeapsort);
            vector<int> valoresHeapsort;
            istringstream issHeapsort(inputHeapsort);
            int valorHeapsort;
            while (issHeapsort >> valorHeapsort) {
                valoresHeapsort.push_back(valorHeapsort);
            }
            Heapsort::OrdenarHeap(valoresHeapsort);
            break;
        }
        case 12: {
            cout << "Ingrese los valores separados por espacios: ";
            string inputQuicksort;
            getline(cin, inputQuicksort);
            vector<int> valoresQuicksort;
            istringstream issQuicksort(inputQuicksort);
            int valorQuicksort;
            while (issQuicksort >> valorQuicksort) {
                valoresQuicksort.push_back(valorQuicksort);
            }
            Quicksort::OrdenarQuick(valoresQuicksort);
            break;
        }
        case 0:
            return;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }
    }
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
