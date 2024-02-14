//z5361475

#include <stdio.h> 


  int main (void) { 
    printf("Enter instruction:");
    int initial;
    while (scanf("%d", &initial) == 1) { 
        if (initial == 1) { 
            int number;
            scanf("%d", &number); 
            printf("%d\n", number * number); 
        } else if (initial == 2) { 
            int number_one, number_two;
            scanf("%d %d", &number_one , &number_two); 
            int i = 0;
            int total = 1;
            while (i < number_two) { 
                total = total * number_one;
                i++;
            }
            printf("%d\n", total);
        }
        printf("Enter instruction:");
    }
    return 0;
}
