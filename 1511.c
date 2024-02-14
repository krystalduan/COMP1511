#include <stdio.h> 
int main(void) {
    int array[10] = {}; 

   // printf("enter 5 numbers");
   int i = 0; 
    int keep_looping = 1; 
    while (keep_looping) { 
        printf("enter 5 numbers");
        int things_read = scanf("%d", &array[i]);
        if (things_read != 1) {
            keep_looping = 0;
        }
    }
    while (i < 0) {
        printf("%d\n", array[i]);
        i++;
    }
    return 0;
}
