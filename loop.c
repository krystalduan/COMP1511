#include <stdio.h> 
 
int main (void) {
    int stop_loop, number; 
    printf("Enter numbers, 0 to stop\n"); 
    stop_loop = 0; 
    while (stop_loop != 1) { 
        scanf("%d", &number); 
        if (number == 0) { 
            stop_loop = 1; 
        }
        else if (number %2 ==1) { 
            printf("%d is odd. \n", number); 
        } else {
            printf("%d is even. \n", number);
        }
    }
    return 0; 
}
