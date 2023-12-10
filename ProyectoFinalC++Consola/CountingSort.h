#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class CountingSort {
public:
    static void OrdenarCounting(std::vector<int>& array) {
        if (array.empty())
            return;

        int max = *std::max_element(array.begin(), array.end());
        int min = *std::min_element(array.begin(), array.end());
        int range = max - min + 1;

        // Inicializar el arreglo de conteo
        std::vector<int> conteo(range, 0);
        std::vector<int> resultado(array.size(), 0);

        // Contar la frecuencia de cada elemento
        for (int i = 0; i < array.size(); i++) {
            conteo[array[i] - min]++;
        }

        // Calcular las posiciones finales de los elementos en el resultado
        for (int i = 1; i < range; i++) {
            conteo[i] += conteo[i - 1];
        }

        // Construir el arreglo ordenado
        for (int i = array.size() - 1; i >= 0; i--) {
            resultado[conteo[array[i] - min] - 1] = array[i];
            conteo[array[i] - min]--;
        }

        // Copiar el resultado al arreglo original
        for (int i = 0; i < array.size(); i++) {
            array[i] = resultado[i];
        }
    }

    static void MostrarVector(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};


