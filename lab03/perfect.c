#include <stdio.h> 

int main (void) { 
    int number = 0; 
    printf("Enter number: ");
    scanf("%d", &number); 
    printf("The factors of %d are: \n", number);
    int sum = 0; 
    int i = 1;
    while (i <= number) {
        if (number % i == 0) { 
            printf("%d \n", i); 
            sum = sum + i; 
        }
        i = i + 1;
    }
    printf("Sum of factors = %d\n", sum); 
    if (number == sum - number) {
        printf("%d is a perfect number\n", number);
    } else {
        printf("%d is not a perfect number\n", number);
    }
    return 0;
}
