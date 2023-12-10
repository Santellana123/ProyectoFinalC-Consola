#pragma once
#include <iostream>
#include <stack>
class EstructuraBase {
public:
    virtual void MostrarFunciones() {
        std::cout << "No se han implementado funciones para esta estructura." << std::endl;
    }
};
class Pila : public EstructuraBase {
private:
    std::stack<int> pila;

public:
    virtual void MostrarFunciones() override {
        std::cout << "1. Apilar" << std::endl;
        std::cout << "2. Desapilar" << std::endl;
    }

    void Apilar(int valor) {
        pila.push(valor);
    }

    void Desapilar() {
        if (!pila.empty()) {
            int valorDesapilado = pila.top();
            pila.pop();
            std::cout << "Elemento desapilado: " << valorDesapilado << std::endl;
        }
        else {
            std::cout << "La pila está vacía." << std::endl;
        }
    }

    void MostrarPila() {
        std::stack<int> pilaTemp = pila;

        while (!pilaTemp.empty()) {
            std::cout << pilaTemp.top() << " ";
            pilaTemp.pop();
        }

        std::cout << std::endl;
    }
};