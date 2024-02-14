// exam_q1.c
//
// This program was written by z5361475
// on 18-08-2021

#include <stdio.h>

// Return the number of pairs with multiples in the array.
int count_multiples(int size, int array[size][2]) {
    int row_counter = 0; 
    int total_multiples = 0; 
    while (row_counter < size) { 
        if (array[row_counter][1] % array[row_counter][0] == 0) { 
            //printf("the multiple is %d and %d \n",array[row_counter][1], array[row_counter][0] );
            total_multiples++;
        }
        row_counter++;
    }
    // PUT YOUR CODE HERE (you must change the next line!)
    return total_multiples;
}


// This is a simple main function which could be used
// to test your count_multiples function.
// It will not be marked.
// Only your count_multiples function will be marked.

#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE][2] = {
        {2, 3}, {4, 4}, {8, 4}, {3, 30}, {30, 40}, {80, 40}, {30, 110}, {30, 120},
    };

    int result = count_multiples(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}
