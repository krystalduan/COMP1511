#include <stdio.h> 

int main (void) { 
    int number;
    int counter = 1;
    printf("Enter number: "); 
    scanf("%d", &number); 
    while (counter <= number) {
         int i = 0; 
        while (i < number) {
               if (i < number - counter ) {
                    printf("-");
               } else {
                    printf("*");
               }
                i++;
        }
        printf("\n"); 
        counter ++;       
    }
    return 0;
}


