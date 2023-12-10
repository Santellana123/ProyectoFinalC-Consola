#pragma once
#include <iostream>
#include <vector>

class MergeSort {
public:
    static void OrdenarMerge(std::vector<int>& array) {
        if (array.size() <= 1)
            return;

        // Dividir el vector en dos mitades
        int medio = array.size() / 2;
        std::vector<int> izquierda(array.begin(), array.begin() + medio);
        std::vector<int> derecha(array.begin() + medio, array.end());

        // Recursivamente ordenar las dos mitades
        OrdenarMerge(izquierda);
        OrdenarMerge(derecha);

        // Combinar las mitades ordenadas
        Combinar(array, izquierda, derecha);
    }

    static void Combinar(std::vector<int>& array, const std::vector<int>& izquierda, const std::vector<int>& derecha) {
        int i = 0, j = 0, k = 0;

        while (i < izquierda.size() && j < derecha.size()) {
            if (izquierda[i] <= derecha[j]) {
                array[k] = izquierda[i];
                i++;
            }
            else {
                array[k] = derecha[j];
                j++;
            }
            k++;
        }

        while (i < izquierda.size()) {
            array[k] = izquierda[i];
            i++;
            k++;
        }

        while (j < derecha.size()) {
            array[k] = derecha[j];
            j++;
            k++;
        }
    }

    static void MostrarVector(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};
