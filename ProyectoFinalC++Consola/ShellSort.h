#pragma once
#include <iostream>

class ShellSort {
public:
    static void OrdenarShell(int* array, int longitud) {
        if (array == nullptr || longitud <= 1)
            return;

        int brecha = longitud / 2;

        while (brecha > 0) {
            for (int i = brecha; i < longitud; i++) {
                int temp = array[i];
                int j = i;

                // Realizar inserción directa en el subarray
                while (j >= brecha && array[j - brecha] > temp) {
                    array[j] = array[j - brecha];
                    j -= brecha;
                }

                array[j] = temp;
            }

            // Reducir la brecha
            brecha /= 2;
        }
    }

    static void MostrarArreglo(int* array, int longitud) {
        for (int i = 0; i < longitud; i++) {
            std::cout << array[i] << " ";
        }

        std::cout << std::endl;
    }
};

