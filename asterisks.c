#include <stdio.h> 

int main (void) { 
    int number; 
    printf("Please enter an integer: ");
    scanf("%d", &number);
    int i = 1; 
    while (i <= number) { 
        printf("*****\n");
        i = i + 1;
    }
    return 0;
}
