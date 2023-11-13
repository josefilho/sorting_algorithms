#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <assert.h>

#include "sorting_algorithms.h"

void print_array(int32_t *array, size_t n){
    for(size_t i = 0; i < n; ++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(int argc, char** argv){
    srand(time(NULL));
    if (argc != 3) {
        printf("Usage: %s <filename> <algorithm>\n", argv[0]);
        printf("Algorithms:\n");
        printf("\t1 - Bubble Sort\n");
        printf("\t2 - Bubble Sort Improved\n");
        printf("\t3 - Selection Sort\n");
        printf("\t4 - Merge Sort\n");
        printf("\t5 - Quick Sort (PIVOT LAST ELEMENT)\n");
        printf("\t6 - Quick Sort (PIVOT RANDOM)\n");
        printf("\t7 - Quick Sort (PIVOT MEDIAN)\n");
        printf("\t8 - Heap Sort\n");
        return EXIT_FAILURE;
    }
    int algorithm = atoi(argv[2]);
    if (algorithm < 1 || algorithm > 8) {
        printf("Invalid algorithm!\n");
        return EXIT_FAILURE;
    }

    // Open file
    FILE *fp = fopen(argv[1], "rb");
    assert(fp != NULL);

    // Get file size
    fseek(fp, 0, SEEK_END);
    size_t n = ftell(fp) / sizeof(int32_t);
    rewind(fp);

    int32_t *array = (int32_t *) malloc(n * sizeof(int32_t));
    assert(array != NULL);

    // Read file
    fread(array, sizeof(int32_t), n, fp);
    fclose(fp);

    time_t start_time, end_time;

    switch(algorithm){
        case 1:{
            start_time = time(NULL);
            bubble_sort(array, n);
            end_time = time(NULL);
        } break;
        case 2:{
            start_time = time(NULL);
            bubble_sort_improved(array, n);
            end_time = time(NULL);
        } break;
        case 3:{
            start_time = time(NULL);
            selection_sort(array, n);
            end_time = time(NULL);
        } break;
        case 4:{
            int32_t *tmp = (int32_t *) malloc(n * sizeof(int32_t));
            assert(tmp != NULL);
            start_time = time(NULL);
            merge_sort(array, tmp, 0, n - 1);
            end_time = time(NULL);
            free(tmp);
        } break;
        case 5:{
            start_time = time(NULL);
            quick_sort(array, 0, (ssize_t) n - 1, PIVOT_LAST);
            end_time = time(NULL);
        } break;
        case 6:{
            start_time = time(NULL);
            quick_sort(array, 0, (ssize_t) n - 1, PIVOT_RANDOM);
            end_time = time(NULL);
        } break;
        case 7:{
            start_time = time(NULL);
            quick_sort(array, 0, (ssize_t) n - 1, PIVOT_MEDIAN);
            end_time = time(NULL);
        } break;
        case 8:{
            start_time = time(NULL);
            heap_sort(array, n);
            end_time = time(NULL);
        } break;
        default: {
            printf("Invalid algorithm!\n");
            return EXIT_FAILURE;
        }break;
    }

    printf("%ld ms\n", (end_time - start_time));
    return EXIT_SUCCESS;
}


