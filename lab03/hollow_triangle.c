//z5361475

#include <stdio.h> 

int main (void) { 
    int number;
    int counter = 1;
    printf("Enter size: "); 
    scanf("%d", &number); 
    while (counter <= number-1) {
        int i = 0; 
        printf("*");
        while (i <= number) {
            if (i == counter - 2 ) {
                printf("*");
            } else {
                printf(" ");
            }
            i++;
        }
        printf("\n"); 
        counter ++;       
    }
    int j = 1;
    while (j <= number) {
        printf("*");
        if (j == number) {
            printf("\n");
        }
        j ++;
        
    }
    return 0;
}

