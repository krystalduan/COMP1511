//playing around
#include <stdio.h>

int main (void) { 
    int size; 
    printf("Please enter a size: ");
    scanf("%d", &size);
    int row = 0;
    while (row < size) {
        int column = 0; 
        while (column < size) {
            int total = size - row - 1;
            if (row <= column && column <= total && row != 0 && row != size - 1) {
                printf("%d", row);
            } else if (total <= column && column <= row && row != 0 && row != size - 1) {
                printf("%d", size - row - 1);
            } else {
                printf("-");
            }
            column ++; 
        }   
        
        printf("\n");
        row ++;
    }
    return 0;
}