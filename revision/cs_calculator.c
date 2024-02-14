#include <stdio.h>

int main (void) { 
    int first_number; 
    scanf("%d", &first_number);
    if (first_number == 1) { 
        int second_number;
        scanf(" %d", &second_number);
        int result = second_number * second_number;
        printf("%d", result);
    } else if (first_number == 2) { 
        int second_number, third_number;
        scanf(" %d %d", &second_number, &third_number);
    }
}