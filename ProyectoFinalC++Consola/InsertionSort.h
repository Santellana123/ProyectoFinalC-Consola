#pragma once
#include <iostream>
#include <vector>

class InsertionSort {
public:
    static void OrdenarInsercion(std::vector<int>& array) {
        int n = array.size();

        for (int i = 1; i < n; ++i) {
            int key = array[i];
            int j = i - 1;

            // Mover los elementos del array[0..i-1] que son mayores que key
            // a una posición por delante de su posición actual
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }

            array[j + 1] = key;
        }
    }

    static void MostrarVector(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};
