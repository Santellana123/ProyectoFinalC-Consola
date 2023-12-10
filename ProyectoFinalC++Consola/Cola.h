#pragma once
#include <iostream>
#include <queue>

class EstructuraBase {
public:
    virtual void MostrarFunciones() {
        std::cout << "No se han implementado funciones para esta estructura." << std::endl;
    }
};

class Cola : public EstructuraBase {
private:
    std::queue<int> cola;

public:
    virtual void MostrarFunciones() override {
        std::cout << "1. Encolar" << std::endl;
        std::cout << "2. Desencolar" << std::endl;
    }

    void Encolar(int valor) {
        cola.push(valor);
    }

    void Desencolar() {
        if (!cola.empty()) {
            int valorDesencolado = cola.front();
            cola.pop();
            std::cout << "Elemento desencolado: " << valorDesencolado << std::endl;
        }
        else {
            std::cout << "La cola está vacía." << std::endl;
        }
    }

    void MostrarCola() {
        // Utiliza un iterador personalizado para recorrer la cola
        auto it = cola;
        while (!it.empty()) {
            std::cout << it.front() << " ";
            it.pop();
        }
        std::cout << std::endl;
    }
};
