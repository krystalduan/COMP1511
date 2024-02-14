//z5361475
#include <stdio.h>

int main (void) {
    int initial_value;
    int i = 0;
    printf("How many numbers: ");
    scanf("%d", &initial_value);
    int total = 0; 
    while (i < initial_value) { 
        int num;
        scanf("%d", &num); 
        total = total + num; 
        i++;
    }
    printf("The sum is: %d\n", total);

    return 0;
}