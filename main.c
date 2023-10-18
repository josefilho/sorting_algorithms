#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "sorting_algorithms.h"

int main(int argc, char** argv){
    int32_t array[] = { 5, 4, 3, 6, 10, 2, 1 };
    size_t n = sizeof(array) / sizeof(int32_t);

    bubble_sort(array, n);

    for(size_t i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
