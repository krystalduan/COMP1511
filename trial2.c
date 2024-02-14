// exam_q3.c
//
// This program was written by z5361475
// on 18-08-2021


#include <stdio.h>

#define MAX_SIZE 10000

int main(void) {
    int i = 0;
    int input = 1;
    char array[MAX_SIZE] = {};
    scanf("%d", &input);
    while (input != 0) { 
        array[i] = input; 
        //printf("%d\n", array[i]);
        i++;
        scanf("%d", &input);
        printf("%d\n", input);
        
    }
    int counter = 0;
    while (counter < i) { 
        printf("%d ", array[counter]);
        counter = counter + 2;
    }
    counter = 1;
    while (counter < i) { 
        printf("%d ", array[counter]);
        counter = counter + 2;
    }
    printf("\n");
    // PUT YOUR CODE HERE
    // You may define your own functions and call them

    return 0;
}
