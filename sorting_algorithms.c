//
// Created by null on 18/10/23.
//

#include "sorting_algorithms.h"

// Tests: Pass
void bubble_sort(int32_t *array, size_t n){
    // if(array == NULL || n == 0) return;
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n - 1; j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// Tests: pass
void bubble_sort_improved(int32_t *array, size_t n){
    bool swapped = true;
    size_t n_ = n;
    size_t store = n;

    while(swapped){
        size_t j = 0;
        swapped = false;
        while(j < n_){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
                swapped = true;
                store = j;
            }
            j++;
        }
        n_ = store;
    }
}