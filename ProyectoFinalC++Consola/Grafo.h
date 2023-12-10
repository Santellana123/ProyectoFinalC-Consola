#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
class EstructuraBase {
public:
    virtual void MostrarFunciones() {
        std::cout << "No se han implementado funciones para esta estructura." << std::endl;
    }
};
class Grafo : public EstructuraBase {
private:
    std::unordered_map<std::string, std::vector<std::string>> vertices;

public:
    Grafo() {}

    virtual void MostrarFunciones() override {
        std::cout << "1. Agregar vértice" << std::endl;
        std::cout << "2. Agregar arista" << std::endl;
        std::cout << "3. Mostrar Grafo" << std::endl;
        std::cout << "4. Búsqueda en Profundidad (DFS)" << std::endl;
        std::cout << "5. Búsqueda en Amplitud (BFS)" << std::endl;
    }

    void AgregarVertice(const std::string& nombreVertice) {
        if (vertices.find(nombreVertice) == vertices.end()) {
            vertices[nombreVertice] = std::vector<std::string>();
        }
        else {
            std::cout << "El vértice " << nombreVertice << " ya existe en el grafo." << std::endl;
        }
    }

    void AgregarArista(const std::string& origen, const std::string& destino) {
        auto it_origen = vertices.find(origen);
        auto it_destino = vertices.find(destino);

        if (it_origen != vertices.end() && it_destino != vertices.end()) {
            it_origen->second.push_back(destino);
        }
        else {
            std::cout << "Al menos uno de los vértices no existe en el grafo." << std::endl;
        }
    }

    void MostrarGrafo() {
        for (const auto& vertice : vertices) {
            std::cout << vertice.first << ": ";
            for (const auto& vecino : vertice.second) {
                std::cout << vecino << " ";
            }
            std::cout << std::endl;
        }
    }

    void BusquedaProfundidad(const std::string& inicio) {
        std::cout << "Recorrido DFS:" << std::endl;
        std::unordered_set<std::string> visitados;
        DFS(inicio, visitados);
        std::cout << std::endl;
    }

    void BusquedaAmplitud(const std::string& inicio) {
        std::cout << "Recorrido BFS:" << std::endl;
        std::unordered_set<std::string> visitados;
        std::queue<std::string> cola;

        visitados.insert(inicio);
        cola.push(inicio);

        while (!cola.empty()) {
            std::string actual = cola.front();
            cola.pop();
            std::cout << actual << " ";

            for (const auto& vecino : vertices[actual]) {
                if (visitados.find(vecino) == visitados.end()) {
                    visitados.insert(vecino);
                    cola.push(vecino);
                }
            }
        }

        std::cout << std::endl;
    }

private:
    void DFS(const std::string& vertice, std::unordered_set<std::string>& visitados) {
        if (visitados.find(vertice) == visitados.end()) {
            std::cout << vertice << " ";
            visitados.insert(vertice);

            for (const auto& vecino : vertices[vertice]) {
                DFS(vecino, visitados);
            }
        }
    }
};
