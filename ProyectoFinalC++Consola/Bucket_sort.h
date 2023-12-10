#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class BucketSort {
public:
    static void OrdenarBucket(std::vector<int>& array) {
        if (array.empty())
            return;

        int max = *std::max_element(array.begin(), array.end());
        int min = *std::min_element(array.begin(), array.end());
        int range = max - min + 1;

        // Crear buckets
        std::vector<std::vector<int>> buckets(range);

        // Colocar elementos en los buckets
        for (int i = 0; i < array.size(); i++) {
            buckets[array[i] - min].push_back(array[i]);
        }

        // Ordenar cada bucket e insertar de nuevo en el array
        int index = 0;
        for (const auto& bucket : buckets) {
            if (!bucket.empty()) {
                std::sort(bucket.begin(), bucket.end());
                for (int item : bucket) {
                    array[index++] = item;
                }
            }
        }
    }

    static void MostrarVector(const std::vector<int>& array) {
        for (int num : array) {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }
};

