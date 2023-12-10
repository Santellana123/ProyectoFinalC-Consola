#pragma once
#include <iostream>
#include <vector>

class Heapsort {
public:
    static void OrdenarHeap(std::vector<int>& array) {
        if (array.empty() || array.size() <= 1)
            return;

        int n = array.size();

        // Construir el heap (mont�culo)
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heapify(array, n, i);
        }

        // Extraer elementos uno por uno desde el heap
        for (int i = n - 1; i > 0; i--) {
            // Intercambiar la ra�z (elemento m�ximo) con el �ltimo elemento no ordenado
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;

            // Llamar a Heapify para reconstruir el heap en el subarray reducido
            Heapify(array, i, 0);
        }
    }

    // Funci�n para convertir un sub�rbol con ra�z en el �ndice 'i' en un mont�culo (heap)
    static void Heapify(std::vector<int>& array, int n, int i) {
        int mayor = i;          // Inicializar el mayor como la ra�z
        int izquierda = 2 * i + 1;  // �ndice del hijo izquierdo
        int derecha = 2 * i + 2;     // �ndice del hijo derecho

        // Si el hijo izquierdo es mayor que la ra�z
        if (izquierda < n && array[izquierda] > array[mayor]) {
            mayor = izquierda;
        }

        // Si el hijo derecho es mayor que la ra�z
        if (derecha < n && array[derecha] > array[mayor]) {
            mayor = derecha;
        }

        // Si el mayor no es la ra�z
        if (mayor != i) {
            // Intercambiar la ra�z con el mayor
            int temp = array[i];
            array[i] = array[mayor];
            array[mayor] = temp;

            // Llamar recursivamente a Heapify para el sub�rbol afectado
            Heapify(array, n, mayor);
        }
    }

    static void MostrarVector(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};
