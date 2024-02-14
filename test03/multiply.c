//z5361475

#include <stdio.h> 

int main (void) { 
    int number_one, number_two, total;
    scanf("%d %d", &number_one, &number_two);
    total = number_one * number_two;
    if (total == 0) { 
        printf("zero\n");
    } else if (total > 1) { 
        printf("%d\n", total);
    } else { 
        printf("%d\n", total * -1); 
    }
    
    return 0;
}
