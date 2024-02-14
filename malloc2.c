#include <stdio.h>
#include <stdlib.h>

int *create_odd_array(int n);

int main(void) {
    int n_odd_numbers = 10;

    int *ptr = create_odd_array(n_odd_numbers);

    int j = 0;
    while (j < n_odd_numbers) {
        printf("%d\n", ptr[j]);
        j = j + 1;
    }

    // free the allocated memory
    free(ptr);

    return 0;
}

// create an array containing first n odd numbers
int *create_odd_array(int n) {
    int *odd_ptr = malloc(n * sizeof (int));

    int i = 0;
    while (i < n) {
        odd_ptr[i] = 2 * i + 1;
        i = i  + 1;
    }

    return odd_ptr;
}