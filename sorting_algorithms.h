////////////////////////////////////////////////////////////////////////////////
/// @author Jose Carlos da Silva Filho
/// @brief Sort library header file. This file contains the prototypes of the
///        functions used to sort arrays. Bubble sort, bubble sort improved,
///        selection sort, insertion sort, merge sort, quick sort pivot last,
///        quick sort pivot median, quick sort pivot random and heap sort.
/// @date September 28, 2023. 3:29AM.
/// @reference Estrutura de Dados e Seus Algoritmos, Jayme Luiz Szwarcfiter, Lilian
///      Markenzon, 3rd edition, LTC, 2010.
/// @license MIT
/// @algorithms
///     Bubble sort: O(n²), Ω(n²), Θ(n²);
///     Bubble sort improved: O(n²), Ω(n), Θ(n²);
///     Insertion sort: O(n²), Ω(n), Θ(n²);
///     Merge sort: O(n log n), Ω(n log n), Θ(n log n);
///     Quick sort pivot last: O(n²), Ω(n log n), Θ(n log n);
///     Quick sort random pivot: O(n²), Ω(n log n), Θ(n log n);
///     Quick sort pivot median: O(n²), Ω(n log n), Θ(n log n);
///     Heap sort: O(n log n), Ω(n log n), Θ(n log n);
////////////////////////////////////////////////////////////////////////////////


#ifndef SORTING_ALGORITHMS_H

#define SORTING_ALGORITHMS_H

#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

/// @brief Swap the values of two variables.
/// @param a First variable.
/// @param b Second variable.
static inline void swap(int32_t *a, int32_t *b){
    int32_t aux = *a;
    *a = *b;
    *b = aux;
}

/// @brief Order an array using the bubble sort algorithm. O(n²).
/// @param array The array to be sorted.
/// @param n The size of the array.
void bubble_sort(int32_t *array, size_t n);

void

/// @brief Order an array using the bubble sort improved algorithm. O(n²).
/// @param array The array to be sorted.
/// @param n The size of the array.
void bubble_sort_improved(int32_t *array, size_t n);

#endif // SORTING_ALGORITHMS_H