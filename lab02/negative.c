
#include <stdio.h>
int main (void) { 
    int number; 
    scanf("%d", &number);
        if (number > 0) { 
            printf("You have entered a positive number.\n");
         }
         if (number <0) { 
            printf("Don't be so negative!\n");
         }
         if (number == 0) { 
            printf( "You have entered zero.\n"); 
         }
    return 0;
}
