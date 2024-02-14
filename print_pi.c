// Prints the first n digits of pi, where n is specified 
// by the user

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    printf("How many digits of pi would you like to print? ");
    //TODO: Insert your code here
    int counter = 0;
    scanf("%d", no_of_digitis);
    while (counter < no_of_digitis) { 
        printf("%d", pi[counter]);
        counter++;
    }
    printf("\n");
    return 0;
}
