#include <stdio.h> 

int main (void) {
    
    int value; 
    scanf("%d", &value); 
    int new_value = value % 26;
    printf("the modulus is %d", new_value);
    return 0;
}