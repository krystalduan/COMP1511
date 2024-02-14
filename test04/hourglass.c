//z5361475
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
            if (row == 0) {
                printf("-");
            } else if (row == size - 1) {
                printf("-");
            } else if (row <= column && column <= total) {
                printf("%d", row);
            } else if (total <= column && column <= row) {
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