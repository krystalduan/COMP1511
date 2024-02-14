//z5361475

#include <stdio.h> 

# define MAX_DIGITS 10

int main (void) { 
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int number = 0;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &number);
    
    int i = 0; 
    while (i < number) {
        printf("%d", pi[i]);
        i++;
        if (i == 1 && number > 1 ) { 
            printf("."); 
        }
    }
    printf("\n");
    return 0;
}
