#pragma once
#include <iostream>

class Quicksort {
public:
    static void OrdenarQuick(int* array, int longitud) {
        if (array == nullptr || longitud <= 1)
            return;

        QuicksortRecursivo(array, 0, longitud - 1);
    }

    // Funci�n recursiva para Quicksort
    static void QuicksortRecursivo(int* array, int inicio, int fin) {
        if (inicio < fin) {
            // Obtener el �ndice de partici�n, array[p] ahora est� en su posici�n correcta
            int indiceParticion = Particionar(array, inicio, fin);

            // Ordenar los elementos antes y despu�s de la partici�n
            QuicksortRecursivo(array, inicio, indiceParticion - 1);
            QuicksortRecursivo(array, indiceParticion + 1, fin);
        }
    }

    // Funci�n para particionar el array y devolver el �ndice de la posici�n del pivote
    static int Particionar(int* array, int inicio, int fin) {
        int pivote = array[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            // Si el elemento actual es menor o igual al pivote
            if (array[j] <= pivote) {
                i++;

                // Intercambiar array[i] y array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Intercambiar array[i+1] y array[fin] (poner el pivote en su posici�n correcta)
        int temp2 = array[i + 1];
        array[i + 1] = array[fin];
        array[fin] = temp2;

        // Devolver el �ndice del pivote
        return i + 1;
    }

    static void MostrarArreglo(int* array, int longitud) {
        for (int i = 0; i < longitud; i++) {
            std::cout << array[i] << " ";
        }

        std::cout << std::endl;
    }
};