#pragma once
#include <iostream>
#include <vector>

class BinaryTreeSort {
private:
    class Nodo {
    public:
        int Valor;
        Nodo* Izquierda;
        Nodo* Derecha;

        Nodo(int valor) : Valor(valor), Izquierda(nullptr), Derecha(nullptr) {}
    };

    // Función para insertar un valor en el árbol binario
    static Nodo* Insertar(Nodo* nodo, int valor) {
        if (nodo == nullptr)
            return new Nodo(valor);

        if (valor < nodo->Valor)
            nodo->Izquierda = Insertar(nodo->Izquierda, valor);
        else if (valor > nodo->Valor)
            nodo->Derecha = Insertar(nodo->Derecha, valor);

        return nodo;
    }

    // Función para realizar un recorrido en orden del árbol y almacenar los elementos en el vector
    static void RecorridoEnOrden(Nodo* nodo, std::vector<int>& array) {
        if (nodo != nullptr) {
            RecorridoEnOrden(nodo->Izquierda, array);
            array.push_back(nodo->Valor);
            RecorridoEnOrden(nodo->Derecha, array);
        }
    }

public:
    // Función principal para ordenar utilizando Binary Tree Sort
    static void OrdenarBinaryTree(std::vector<int>& array) {
        if (array.size() <= 1)
            return;

        Nodo* raiz = nullptr;

        // Insertar todos los elementos en el árbol binario
        for (int valor : array) {
            raiz = Insertar(raiz, valor);
        }

        // Realizar un recorrido en orden del árbol y almacenar los elementos en el vector
        array.clear();  // Limpiar el vector antes de almacenar los elementos ordenados
        RecorridoEnOrden(raiz, array);
    }

    static void MostrarArreglo(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};


