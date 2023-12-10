#include <iostream>
#include <vector>

class Bubblesort {
public:
    static void OrdenarBurbuja(std::vector<int>& array) {
        int n = array.size();
        bool swapped;

        do {
            swapped = false;

            for (int i = 1; i < n; i++) {
                if (array[i - 1] > array[i]) {
                    // Swap elements
                    int temp = array[i - 1];
                    array[i - 1] = array[i];
                    array[i] = temp;

                    swapped = true;
                }
            }

            // After each pass, the largest unsorted element is at the end
            n--;
        } while (swapped);

        // Mostrar el vector ordenado
        std::cout << "Vector ordenado con Bubblesort: ";
        MostrarVector(array);
    }

    static void MostrarVector(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};


