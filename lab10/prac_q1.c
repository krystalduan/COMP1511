//this code was written by PENGPENG-DUAN on 12-08-2021
// (z5361475)
#include <stdio.h>
#define TEST_ARRAY_SIZE 100

// Return the maximum sum of a row in the 2D array.
int max_row_sum(int array[TEST_ARRAY_SIZE][TEST_ARRAY_SIZE], int side_length) {
    int counter_for_row = 0; 
    int highest_total_for_row = 0;
    while (counter_for_row < side_length) { 
        int counter_for_column = 0; 
        int total_for_row = 0;
        while (counter_for_column < side_length) {
            //int total_for_row = 0;
            total_for_row = total_for_row + array[counter_for_row][counter_for_column];
            counter_for_column++;
        } 

        if (total_for_row > highest_total_for_row) { 
            highest_total_for_row = total_for_row;
        }
        
        counter_for_row++;
    }
    // PUT YOUR CODE HERE (you must change the next line!)
    return highest_total_for_row;
}

// This is a simple main function which could be used
// to test your max_row_sum function.
// It will not be marked.

int main(void) {
    int test_array[TEST_ARRAY_SIZE][TEST_ARRAY_SIZE] = {
        { 1,    2,    3,    4 },
        { 1,   11,  111,  111 },
        { 1,    1,    1,    1 },
        { 22,  22,    2,    2 }
    };

    int result;

    result = max_row_sum(test_array, 1);
    printf("Max row sum in 1x1 array: %d\n", result);

    result = max_row_sum(test_array, 2);
    printf("Max row sum in 2x2 array: %d\n", result);

    result = max_row_sum(test_array, 3);
    printf("Max row sum in 3x3 array: %d\n", result);

    result = max_row_sum(test_array, 4);
    printf("Max row sum in 4x4 array: %d\n", result);

    return 0;
}
