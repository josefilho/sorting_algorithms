////////////////////////////////////////////////////////////////////////////////
/// @author Jose Carlos da Silva Filho
/// @brief Sort library header file. This file contains the prototypes of the
///        functions used to sort arrays. Bubble sort, bubble sort improved,
///        selection sort, insertion sort, merge sort, quick sort pivot last,
///        quick sort pivot median, quick sort pivot random and heap sort.
/// @date September 28, 2023. 3:29AM.
/// @reference Estrutura de Dados e Seus Algoritmos, Jayme Luiz Szwarcfiter, Lilian
///      Markenzon, 3rd edition, LTC, 2010.
/// @license MIT, see the LICENSE file for more details.
///
////////////////////////////////////////////////////////////////////////////////


#ifndef SORTING_ALGORITHMS_H

#define SORTING_ALGORITHMS_H

#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

/// @brief Pivot type.
typedef enum pivot_e {
    PIVOT_FIRST = 1,
    PIVOT_LAST,
    PIVOT_MEDIAN,
    PIVOT_RANDOM
} pivot_t;

/// @brief Swap the values of two variables.
/// @param a First variable.
/// @param b Second variable.
static inline void swap(int32_t *a, int32_t *b) {
    int32_t aux = *a;
    *a = *b;
    *b = aux;
}

/// @brief Order an array using the bubble sort algorithm. O(n²).
/// @param array The array to be sorted.
/// @param n The size of the array.
void bubble_sort(int32_t *array, size_t n);

/// @brief Order an array using the bubble sort improved algorithm. O(n²).
/// @param array The array to be sorted.
/// @param n The size of the array.
void bubble_sort_improved(int32_t *array, size_t n);

/// @brief Order an array using the selection sort algorithm.
/// @param array The array to be sorted.
/// @param n The size of the array.
void selection_sort(int32_t *array, size_t n);

/// @brief Order an array using the merge sort algorithm.
/// @param array The array to be sorted.
/// @param tmp The temporary array.
/// @param left The left index.
/// @param right The right index.
/// @warning tmp must be allocated before calling this function.
void merge_sort(int32_t *array, int32_t *tmp, size_t left, size_t right);

/// @brief Merge two arrays. Auxiliary function for merge sort.
/// @param array The array to be sorted.
/// @param tmp The temporary array.
/// @param ini1 The initial index of the first array.
/// @param ini2 The initial index of the second array.
/// @param end2 The last index of the second array.
/// @note This function is called by merge_sort.
/// @note The last index of the first array is ini2 - 1.
/// @warning This function is not intended to be called by the user.
static void merge(int32_t *array, int32_t *tmp, size_t ini1, size_t ini2, size_t end2);

/// @brief Order an array using the quick sort algorithm.
/// @param array The array to be sorted.
/// @param start The start index.
/// @param end The end index.
/// @param pivot The pivot type. PIVOT_FIRST, PIVOT_LAST, PIVOT_MEDIAN or PIVOT_RANDOM.
void quick_sort(int32_t *array, ssize_t start, ssize_t end, pivot_t pivot);

/// @brief Choose the pivot index.
/// @param array The array containing the elements.
/// @param ini The initial index.
/// @param end The end index.
/// @param pivot The pivot type.
size_t choose_pivot(const int32_t *array, size_t ini, size_t end, pivot_t pivot);

/// @brief Order an array using the heap sort algorithm.
/// @param array The array to be sorted.
/// @param n The size of the array.
void heap_sort(int32_t *array, size_t n);

/// @brief Build a heap.
/// @param array The array where the heap will be built.
/// @param n The size of the array.
void build_heap(int32_t *array, size_t n);

/// @brief Downheap.
/// @param array The array where the heap will be built.
/// @param n The size of the array.
/// @param i The index of the element to be downheaped.
void downheap(int32_t *array, size_t n, size_t i);

#endif // SORTING_ALGORITHMS_H