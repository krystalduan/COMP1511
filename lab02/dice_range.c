#include <stdio.h> 
int main (void) { 
    int sides; 
    int rolls;
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &sides); 
    printf("Enter the number of dice being rolled: "); 
    scanf("%d", &rolls); 
    if (sides < 1 || rolls < 1) { 
        printf("These dice will not produce a range. \n"); 
    }
    else {
        int dice_range_higher; 
        dice_range_higher = rolls*sides; 
        printf("Your dice range is %d to %d.\n", rolls,     dice_range_higher);
        double random; 
        random = 1; 
        double average; 
        average = random*(rolls + rolls*sides)/2; 
     printf("The average value is %lf\n", average); 
     }
    return 0; 
}
