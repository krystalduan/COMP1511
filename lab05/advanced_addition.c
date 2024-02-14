//This code was written by PENGPENG DUAN (z5361475) 
//on 19-07-2021. 
// Add two numbers together, but in an array.

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 101

int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE] = {0};

    // Get the array size.
    int num_digits, num_rows;
    printf("Enter the number of rows (excluding the last): ");
    scanf("%d", &num_rows);
    assert(num_rows > 0 && num_rows < 100);

    printf("Enter the number of digits on each row: ");
    scanf("%d", &num_digits);
    assert(num_digits > 0 && num_digits < MAX_SIZE);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < num_rows) {
        int j = 0;
        while (j < num_digits) {
            assert(scanf("%d", &array[i][j]) == 1);
            if (array[i][j] < 0 || array[i][j] > 9) {
                printf("You entered a value not between 0 and 9.\n");
                return 1;
            }
            j++;
        }
        i++;
    }

    int carry = sum(num_rows, num_digits, array);

    int j = 0;
    while (j < num_digits) {
        printf("%d ", array[num_rows][j]);
        j++;
    }
    printf("\n");

    if (carry > 0) {
        printf("Carried over: %d\n", carry);
    }

    return 0;
}

// Put the sum of the lines in the array into the last line
// accounting for carrying. Return anything you did not carry.
//
// NOTE: num_lines is the number of lines you are adding together. The
// array has an extra line for you to put the result.
int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]) {
    // Put your code here.
    int carry = 0; //this is the value that's returned

    int i = num_digits - 1; 
    
    while (i >= 0 ) { 
        int total = carry; 
        int j = 0; 
        while (j < num_lines) { 
            total = total + array[j][i];
            //printf("the total value is %d", total);
            j++;
        }
        //printf("the total value is %d", total);
        //make the bottom row the calculated values 
         if (total <= 9) { 
           // printf("the value is %d",array[num_lines][j] );
           // printf("the total value is %d", total);
            array[num_lines][i] = total;
            carry = 0;
        } else if (total > 9) { 
            carry = total / 10; 
            array[num_lines][i] = total % 10; 
        }
        
        i--;
    }
    return carry;
}
