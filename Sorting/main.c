#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

// Auxillary functions
/**
 * @brief Generate a random array of len elements.
 *
 * @param len Number of elements
 * @param seed Seed used by the RNG
 * @param max_val Upper bound of the array
 * @return int* points to the start of the array
 */
int* generate_array(size_t len, unsigned int seed, int max_val);

int main(int argc, char const* argv[argc + 1])
{
	size_t len = 10;
	unsigned int func_id = 0;
	// Get arguments from the user
	if (argc == 3) {
		len = atol(argv[1]);
		func_id = atoi(argv[2]);
	} else {
		printf("Usage: %s <length of the array> <function-id>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int* arr = generate_array(len, 7, 9999);
	// int arr[] = {7, 1, 3, 0, 2, 6, 5, 4, 8, 9};
	int* sorted_arr = malloc(sizeof(int) * len);
	sorting_function[func_id](len, arr, sorted_arr);

	// Print the contents of the array
	printf("Sorting with %s\nSorted Array: ", sort_name[func_id]);
	print_array(len, sorted_arr);

	// Free array and return
	free(arr);
	free(sorted_arr);
	return EXIT_SUCCESS;
}

// Generate a random array of given size
int* generate_array(size_t len, unsigned int seed, int max_val)
{
	// Get memory for array
	size_t arr_size = sizeof(int) * len;
	int* arr = malloc(arr_size);

	srand(seed);
	// Fill it with random values
	for (size_t i = 0; i < len; i++) {
		arr[i] = rand() % max_val;
	}
	return arr;
}