#pragma once
#include <iostream>

class SelectionSort {
public:
    static void OrdenarSeleccion(int* array, int longitud) {
        if (array == nullptr || longitud <= 1)
            return;

        for (int i = 0; i < longitud - 1; i++) {
            // Encontrar el índice del elemento mínimo en el subarray no ordenado
            int indiceMinimo = i;
            for (int j = i + 1; j < longitud; j++) {
                if (array[j] < array[indiceMinimo]) {
                    indiceMinimo = j;
                }
            }

            // Intercambiar el elemento mínimo con el primer elemento no ordenado
            int temp = array[indiceMinimo];
            array[indiceMinimo] = array[i];
            array[i] = temp;
        }
    }

    static void MostrarArreglo(int* array, int longitud) {
        for (int i = 0; i < longitud; i++) {
            std::cout << array[i] << " ";
        }

        std::cout << std::endl;
    }
};

