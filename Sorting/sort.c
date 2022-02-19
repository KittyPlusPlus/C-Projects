#include "sort.h"

sorting_funcs* sorting_function[NUM_FUNCS] = {merge_sort, quick_sort, rec_merge_sort};
char* sort_name[NUM_FUNCS] = {"Merge Sort", "Quick Sort", "Merge Sort[Recursive]"};

// ================ Auxilliary functions ================ //
void copy_array(size_t len, int src[len], int dst[len])
{
	for (size_t idx = 0; idx < len; idx++) {
		dst[idx] = src[idx];
	}
}

void merge(size_t a_start, size_t a_end, size_t b_start, size_t b_end, int arr[], int sorted[])
{
	size_t i = a_start, j = b_start, k = a_start;
	// Merge the two sorted arrays
	while (i < a_end && j < b_end) {
		if (arr[i] < arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	// Copy the remaining elements
	while (i < a_end) sorted[k++] = arr[i++];
	while (j < b_end) sorted[k++] = arr[j++];
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(size_t start, size_t end, int arr[])
{
	// Use the last element as pivot
	int pivot = arr[end - 1];
	size_t piv_id = start;
	// Move all the elements smaller than the pivot to the left end
	for (size_t idx = start; idx < end - 1; idx++) {
		if (arr[idx] < pivot) {
			if (piv_id != idx) swap(&arr[idx], &arr[piv_id]);
			piv_id += 1;
		}
	}
	// Move the pivot to the center of the partition and return it's position
	swap(&arr[end - 1], &arr[piv_id]);
	return piv_id;
}

void recursive_part(size_t start, size_t end, int arr[])
{
	// If the array is of size 1, stop
	if (end - start <= 1) return;

	// Create partitions
	int pos = partition(start, end, arr);

	// Sort the two partitions recursively
	recursive_part(start, pos, arr);
	recursive_part(pos + 1, end, arr);
}

void recursive_merge(size_t start, size_t end, int len, int a[len], int b[len])
{
	// Return single element arrays
	if (start == end - 1) return;

	// Recursively sort left and right partitions
	size_t mid = (start + end) / 2;
	recursive_merge(start, mid, len, a, b);
	recursive_merge(mid, end, len, a, b);

	// Merge left, right partitions and write it back to main array
	merge(start, mid, mid, end, a, b);
	for (size_t i = start; i < end; i++) {
		a[i] = b[i];
	}
}

// ================ Library functions ================ //
void merge_sort(size_t len, int arr[len], int sorted[len])
{
	// Prime sorted array for future use
	copy_array(len, arr, sorted);

	size_t blk_width = 1;
	bool swapped = false;
	do {
		// Merge 2 adjacent sorted blocks
		for (size_t idx = 0; idx < len; idx += 2 * blk_width) {
			// Get boundaries of the first block
			size_t a_start = idx, a_end = idx + blk_width;
			if (a_end >= len) continue;

			// Get boundaries of the second block
			size_t b_start = idx + blk_width, b_end = idx + blk_width * 2;
			if (b_end >= len) b_end = len;

			merge(a_start, a_end, b_start, b_end, arr, sorted);
		}
		// Repeat the process with twice the block size
		blk_width *= 2;
		copy_array(len, sorted, arr);
	} while (blk_width < len);

	// Write the array to output pointer if it's not in the right place
	if (swapped) copy_array(len, arr, sorted);
}

void quick_sort(size_t len, int arr[len], int sorted[len])
{
	recursive_part(0, len, arr);
	copy_array(len, arr, sorted);
}

void rec_merge_sort(size_t len, int arr[], int sorted_arr[])
{
	copy_array(len, arr, sorted_arr);
	recursive_merge(0, len, len, arr, sorted_arr);
}

// Print elements in the array
void print_array(size_t len, int arr[len])
{
	size_t idx = 0;
	printf("%d", arr[0]);
	// The first few elements
	for (idx = 1; (idx < len && idx < 32); idx++) {
		printf(", %d", arr[idx]);
	}
	// Print the last element
	if (len > 32) {
		printf("... %d", arr[len - 1]);
	}
	printf("\n");
}