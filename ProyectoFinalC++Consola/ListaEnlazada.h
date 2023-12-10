#pragma once
#include <iostream>
class EstructuraBase {
public:
    virtual void MostrarFunciones() {
        std::cout << "No se han implementado funciones para esta estructura." << std::endl;
    }
};
class ListaEnlazada : public EstructuraBase {
private:
    struct NodoListaEnlazada {
        int Valor;
        NodoListaEnlazada* Siguiente;

        NodoListaEnlazada(int valor) : Valor(valor), Siguiente(nullptr) {}
    };

    NodoListaEnlazada* inicio;

public:
    ListaEnlazada() : inicio(nullptr) {}

    virtual void MostrarFunciones() override {
        std::cout << "1. Insertar elemento" << std::endl;
        std::cout << "2. Eliminar elemento" << std::endl;
        std::cout << "3. Mostrar Lista Enlazada" << std::endl;
    }

    void InsertarElemento(int valor) {
        NodoListaEnlazada* nuevoNodo = new NodoListaEnlazada(valor);
        if (inicio == nullptr) {
            inicio = nuevoNodo;
        }
        else {
            NodoListaEnlazada* actual = inicio;
            while (actual->Siguiente != nullptr) {
                actual = actual->Siguiente;
            }
            actual->Siguiente = nuevoNodo;
        }
    }

    void EliminarElemento(int valor) {
        if (inicio == nullptr) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }

        if (inicio->Valor == valor) {
            NodoListaEnlazada* temp = inicio;
            inicio = inicio->Siguiente;
            delete temp;
            return;
        }

        NodoListaEnlazada* actual = inicio;
        while (actual->Siguiente != nullptr && actual->Siguiente->Valor != valor) {
            actual = actual->Siguiente;
        }

        if (actual->Siguiente != nullptr) {
            NodoListaEnlazada* temp = actual->Siguiente;
            actual->Siguiente = actual->Siguiente->Siguiente;
            delete temp;
        }
        else {
            std::cout << "El elemento " << valor << " no se encuentra en la lista." << std::endl;
        }
    }

    void MostrarLista() {
        NodoListaEnlazada* actual = inicio;
        while (actual != nullptr) {
            std::cout << actual->Valor << " ";
            actual = actual->Siguiente;
        }
        std::cout << std::endl;
    }

    ~ListaEnlazada() {
        // Liberar la memoria al destruir la lista
        NodoListaEnlazada* actual = inicio;
        while (actual != nullptr) {
            NodoListaEnlazada* temp = actual;
            actual = actual->Siguiente;
            delete temp;
        }
    }
};
