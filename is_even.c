#include <stdio.h>

int is_even(int num);
int main (void) { 
    int num;
    printf("Enter number:"); 
    scanf("%d\n", &num);
    is_even (num); 
    printf("%d\n", even_or_odd);
    return 0;
        
}
int even_or_odd = 1; 
int is_even(int num) {
    if (num % 2 == 1) { 
        even_or_odd = 0; 
    }
    return even_or_odd; 
}
