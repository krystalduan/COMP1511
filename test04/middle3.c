//z5361475
#include <stdio.h>

int main (void) {
    int num_one, num_two, num_three;
    printf("Enter integer: "); 
    scanf("%d", &num_one);
    printf("Enter integer: "); 
    scanf("%d", &num_two);
    printf("Enter integer: "); 
    scanf("%d", &num_three);

    if (num_one <= num_two && num_two <= num_three) { 
        printf("Middle : %d\n", num_two);
    }   else if (num_one <= num_three && num_three <= num_two) { 
        printf("Middle : %d\n", num_three);
    }   else if (num_two <= num_one && num_one <= num_three) { 
        printf("Middle : %d\n", num_one);
    }   else if (num_three <= num_one && num_one <= num_two) { 
        printf("Middle : %d\n", num_one);
    }   else if (num_three <= num_two && num_two <= num_one) { 
        printf("Middle : %d\n", num_two);
    }   else if (num_two <= num_three && num_three <= num_one) { 
        printf("Middle : %d\n", num_three);
    }
    return 0;
}