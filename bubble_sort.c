/*
 * Task 1 (c): Bubble sort in C.
 *
 * Reads 8 integers from standard input and prints them in ascending order.
 *
 * Build: gcc -Wall -Wextra -O2 -o bubble_sort bubble_sort.c
 * Run:   ./bubble_sort
 */

#include <stdio.h>

#define N 8

/* Sort a[0..n-1] into ascending order using bubble sort. */
static void bubble_sort(int *a, int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++) {
        int swapped = 0;

        /* Each pass bubbles the largest element of the remaining
         * range to its final position at the end. */
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = 1;
            }
        }

        /* No swap in this pass means the array is already sorted. */
        if (!swapped)
            break;
    }
}

int main(void)
{
    int a[N];
    int i;

    printf("Please input %d numbers:", N);
    fflush(stdout);

    for (i = 0; i < N; i++) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "input error\n");
            return 1;
        }
    }

    bubble_sort(a, N);

    printf("After sorting:");
    for (i = 0; i < N; i++)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
