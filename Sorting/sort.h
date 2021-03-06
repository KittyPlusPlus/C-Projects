#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum { MERGE, QUICK, SORT_COUNT };
typedef void sorting_funcs(size_t, int*, int*);

// Sorting Functions
/**
 * @brief Implement the Merge Sort algorithm
 *
 * @param len Length of the array
 * @param[in] arr Input Array
 * @param[out] sorted_arr Store the sorted array
 */

void merge_sort(size_t len, int arr[len], int sorted_arr[len]);
/**
 * @brief Implement the Merge Sort algorithm using recursion
 *
 * @param len Length of the array
 * @param[in] arr Input Array
 * @param[out] sorted_arr Store the sorted array
 */
void quick_sort(size_t len, int arr[len], int sorted_arr[len]);

/**
 * @brief Prints the given array.
 *
 * @param len Length of the array
 * @param arr Array being printed
 */
void print_array(size_t len, int arr[len]);

// Sorting functions available
extern sorting_funcs* sorting_function[SORT_COUNT];
extern char* sort_name[SORT_COUNT];

#endif
