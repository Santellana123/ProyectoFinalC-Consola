#pragma once
#include <iostream>
#include <vector>

class CocktailSort {
public:
    static void OrdenarCocktail(std::vector<int>& array) {
        bool swapped;
        int start = 0;
        int end = array.size();

        do {
            // fase ascendente (de izquierda a derecha)
            swapped = false;
            for (int i = start; i < end - 1; ++i) {
                if (array[i] > array[i + 1]) {
                    // Swap elements
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;

                    swapped = true;
                }
            }

            if (!swapped)
                break;

            // disminuir el rango ya que el último elemento está en su posición correcta
            end--;

            // fase descendente (de derecha a izquierda)
            swapped = false;
            for (int i = end - 1; i >= start; --i) {
                if (array[i] > array[i + 1]) {
                    // Swap elements
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;

                    swapped = true;
                }
            }

            // aumentar el rango ya que el primer elemento está en su posición correcta
            start++;
        } while (swapped);
    }

    static void MostrarVector(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};
