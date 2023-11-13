//
// Created by null on 18/10/23.
//

#include <stdio.h>
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

// Tests: Pass
void bubble_sort_improved(int32_t *array, size_t n){
    bool swapped = true;
    size_t n_ = n - 1;
    size_t store = n - 1;

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

void selection_sort(int32_t *array, size_t n){
    for (size_t i = 1; i < n; ++i){
        int32_t provisory = array[i];
        int32_t value = array[i];
        ssize_t j = (ssize_t)i - 1;
        while (j >= 0 && value < array[j]){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = provisory;
    }
}

void merge_sort(int32_t *array, int32_t *tmp, size_t left, size_t right){
    if(left < right){
        size_t middle = (left + right) / 2;
        merge_sort(array, tmp, left, middle);
        merge_sort(array, tmp, middle + 1, right);
        merge(array, tmp, left, middle + 1, right);
    }
}
void merge(int32_t *array, int32_t *tmp, size_t ini1, size_t ini2, size_t end2){
    size_t end1 = ini2 - 1;
    ssize_t nro = 0;
    size_t ind = ini1;

    while(ini1 <= end1 && ini2 <= end2){
        if(array[ini1] <= array[ini2]){
            tmp[ind] = array[ini1++];
        }else{
            tmp[ind] = array[ini2++];
        }
        ++ind, ++nro;
    }

    while(ini1 <= end1){
        tmp[ind++] = array[ini1++];
        ++nro;
    }

    while(ini2 <= end2){
        tmp[ind++] = array[ini2++];
        ++nro;
    }

    for(size_t i = 0; i < nro; ++i, --end2){
        array[end2] = tmp[end2];
    }
}

void quick_sort(int32_t *array, ssize_t start, ssize_t end, pivot_t pivot) {
    if (end - start < 2) {
        if (end - start == 1 && array[start] > array[end]) {
            swap(&array[start], &array[end]);
        }
    } else {
        ssize_t pivot_index = (ssize_t)choose_pivot(array, start, end, pivot);
        swap(&array[pivot_index], &array[end]);
        ssize_t i = start;
        ssize_t j = end - 1;
        int32_t key = array[end];
        while (j >= i) {
            while (array[i] < key) i = i + 1;
            while (j>=start && array[j] > key) j = j - 1;
            if (j >= i) {
                swap(&array[i], &array[j]);
                i = i + 1;
                j = j - 1;
            }
        }
        swap(&array[i], &array[end]);
        quick_sort(array, start, i - 1, pivot);
        quick_sort(array, i + 1, end, pivot);
    }
}

size_t choose_pivot(const int32_t *array, size_t ini, size_t end, pivot_t pivot){
    size_t pivot_index = 0;
    switch(pivot){
        case PIVOT_FIRST: {
            pivot_index = ini;
        } break;
        case PIVOT_LAST: {
            pivot_index = end;
        } break;
        case PIVOT_MEDIAN: {
            int32_t p = array[ini]; // First element of array
            int32_t f = array[end]; // Last element of array
            int32_t m = array[(ini + end) / 2]; // Middle element of array

            if((p > m || p > f) && (p < m || p < f)){
                pivot_index = ini;
            }
            else if((f > m || f > p) && (f < m || f < p)){
                pivot_index = end;
            }
            else {
                pivot_index = (ini + end) / 2;
            }
        } break;
        case PIVOT_RANDOM: {
            pivot_index = ini + rand() % (end - ini + 1);
        } break;
    }
    return pivot_index;
}

void downheap(int32_t *array, size_t n, size_t i){
    size_t j = 2 * i + 1;
    if (j < n) {
        if (j + 1 < n && array[j] < array[j + 1]) {
            j++;
        }
        if (array[i] < array[j]) {
            swap(&array[i], &array[j]);
            downheap(array, n, j);
        }
    }
}

void build_heap(int32_t *array, size_t n) {
    for (size_t i = n / 2; i > 0; i--) {
        downheap(array, n, i - 1); // Ajustado o índice
    }
}

void heap_sort(int32_t *array, size_t n){
    build_heap(array, n);
    size_t m = n;
    while(m > 0){
        swap(&array[0], &array[m - 1]); // Corrigido o índice
        --m;
        downheap(array, m, 0); // Corrigido o último argumento
    }
}