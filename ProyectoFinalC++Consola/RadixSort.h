#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class RadixSort {
private:
    static int ObtenerDigito(int num, int posicion) {
        for (int i = 0; i < posicion; i++) {
            num /= 10;
        }
        return num % 10;
    }

    // Función para encontrar el número de dígitos en el número más grande
    static int NumeroDeDigitos(int num) {
        int count = 0;
        while (num > 0) {
            num /= 10;
            count++;
        }
        return count;
    }

public:
    // Función principal para ordenar utilizando Radix Sort
    static void OrdenarRadix(int* array, int longitud) {
        if (array == nullptr || longitud <= 1)
            return;

        int max = *std::max_element(array, array + longitud);
        int numDigitos = NumeroDeDigitos(max);

        // Aplicar Radix Sort para cada posición de dígito
        for (int posicion = 0; posicion < numDigitos; posicion++) {
            // Crear buckets para cada dígito (0-9)
            std::vector<std::vector<int>> buckets(10);

            // Colocar elementos en los buckets según el dígito en la posición actual
            for (int i = 0; i < longitud; i++) {
                int digito = ObtenerDigito(array[i], posicion);
                buckets[digito].push_back(array[i]);
            }

            // Reconstruir el array ordenado a partir de los buckets
            int index = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < buckets[i].size(); j++) {
                    array[index++] = buckets[i][j];
                }
            }
        }
    }

    static void MostrarArreglo(int* array, int longitud) {
        for (int i = 0; i < longitud; i++) {
            std::cout << array[i] << " ";
        }

        std::cout << std::endl;
    }
};


