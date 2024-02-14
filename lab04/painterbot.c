//z5361475

#include <stdio.h> 
#define MAX_DIGITS 36
int main (void) { 
    int array[MAX_DIGITS] = {0};
    int scanned_in_value; 
    while (scanf("%d", &scanned_in_value) == 1) {
        array[scanned_in_value] = 1; 
    }
    
    int i = 0;  
    while (i < MAX_DIGITS) {
        printf("%d ", array[i]); 
        i++;
    }
    printf("\n");
    return 0; 
}
