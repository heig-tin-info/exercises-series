//#include <rand.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int binary_search(int *array, size_t left, size_t right, int value) {
    if (right < left) return -1;

    size_t mid = left + (right - left ) / 2;

    if (array[mid] == value)
        return mid;

    if (array[mid] > value)
        return binary_search(array, left, mid - 1, value);
    else
        return binary_search(array, mid + 1, right, value);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int display(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * O(d*radix*n) time
 * O(n+radix) space
 */
void radix_sort(int *a, const size_t size, const int radix, int digits) {
    assert(digits % 2 == 0);
    int *count = calloc(radix, sizeof(int));
    int *b = malloc(size * sizeof(int));
    int exp = 1;
    while(digits-- > 0) {
        // Count elements
        memset(count, 0, radix * sizeof(int));
        for (int i = 0; i < size; i++)
            count[a[i] / exp % radix]++;

        // Cumulative sum
        for (int i = 1; i < radix; i++)
            count[i] += count[i - 1];

        // Build output array
        for (int i = size - 1; i >= 0; i--)
            b[count[(a[i]/exp)%10]-- - 1] = a[i];

        exp *= radix;
        int *p = a; a = b; b = p;
    };

    free(b);
    free(count);
}


int main(void)
{
    #define SIZE 5
    int data[SIZE];

    for (int i = 0; i < SIZE; i++) {
        data[i] = rand()%1000;
    }

    display(data, SIZE);
    //qsort(data, SIZE, sizeof(data[0]), cmpfunc);
    radix_sort(data, SIZE, 10, 4);
    display(data, SIZE);
    //int x = data[254];
    //printf("%d\n", binary_search(data, 0, SIZE - 1, x));

}