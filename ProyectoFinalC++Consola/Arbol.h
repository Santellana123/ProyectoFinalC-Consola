#pragma once
#include <iostream>
class EstructuraBase {
public:
    virtual void MostrarFunciones() {
        std::cout << "No se han implementado funciones para esta estructura." << std::endl;
    }
};
class Arbol : public EstructuraBase {
private:
    class NodoArbol {
    public:
        int Valor;
        NodoArbol* Izquierda;
        NodoArbol* Derecha;

        NodoArbol(int valor) : Valor(valor), Izquierda(nullptr), Derecha(nullptr) {}
    };

    NodoArbol* raiz;

public:
    Arbol() : raiz(nullptr) {}

    virtual void MostrarFunciones() override {
        std::cout << "1. Insertar nodo" << std::endl;
        std::cout << "2. Eliminar nodo" << std::endl;
    }

    void InsertarNodo(int valor) {
        raiz = InsertarNodoRecursivo(raiz, valor);
    }

    NodoArbol* InsertarNodoRecursivo(NodoArbol* nodo, int valor) {
        if (nodo == nullptr) {
            return new NodoArbol(valor);
        }

        if (valor < nodo->Valor) {
            nodo->Izquierda = InsertarNodoRecursivo(nodo->Izquierda, valor);
        }
        else if (valor > nodo->Valor) {
            nodo->Derecha = InsertarNodoRecursivo(nodo->Derecha, valor);
        }

        return nodo;
    }

    void EliminarNodo(int valor) {
        raiz = EliminarNodoRecursivo(raiz, valor);
    }

    NodoArbol* EliminarNodoRecursivo(NodoArbol* nodo, int valor) {
        if (nodo == nullptr) {
            return nodo;
        }

        if (valor < nodo->Valor) {
            nodo->Izquierda = EliminarNodoRecursivo(nodo->Izquierda, valor);
        }
        else if (valor > nodo->Valor) {
            nodo->Derecha = EliminarNodoRecursivo(nodo->Derecha, valor);
        }
        else {
            if (nodo->Izquierda == nullptr) {
                return nodo->Derecha;
            }
            else if (nodo->Derecha == nullptr) {
                return nodo->Izquierda;
            }

            nodo->Valor = ObtenerMinimoValor(nodo->Derecha);
            nodo->Derecha = EliminarNodoRecursivo(nodo->Derecha, nodo->Valor);
        }

        return nodo;
    }

    int ObtenerMinimoValor(NodoArbol* nodo) {
        int minimoValor = nodo->Valor;
        while (nodo->Izquierda != nullptr) {
            minimoValor = nodo->Izquierda->Valor;
            nodo = nodo->Izquierda;
        }
        return minimoValor;
    }

    void MostrarArbol() {
        MostrarArbolRecursivo(raiz, 0);
    }

    void MostrarArbolRecursivo(NodoArbol* nodo, int nivel) {
        if (nodo != nullptr) {
            MostrarArbolRecursivo(nodo->Derecha, nivel + 1);

            for (int i = 0; i < nivel; i++) {
                std::cout << "   ";
            }

            std::cout << nodo->Valor << std::endl;

            MostrarArbolRecursivo(nodo->Izquierda, nivel + 1);
        }
    }
};



