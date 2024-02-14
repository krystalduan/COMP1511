//z5361475

#include <stdio.h> 

int main (void) { 
    double num_one, num_two, num_three; 
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &num_one, &num_two, &num_three); 
    if (num_one < num_two && num_two < num_three) { 
        printf("up\n"); 
    } else if (num_three < num_two && num_two < num_one) { 
        printf("down\n"); 
    } else { 
        printf("neither\n");
    }
    return 0;
}
