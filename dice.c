#include <stdio.h> 

#define SECRET_TARGET 7 
#define MAX_DIE 6
#define MIN_DIE 1
int main (void) {
    int dice1;
    int dice2; 
    
    printf("Enter dice 1: ") ;
    scanf("%d", &dice1);
    
    if (dice1 < MIN_DIE || dice1 > MAX_DIE) { 
        dice1 = dice1 % MAX_DIE; 
        if (dice1 == 0) { 
            dice1 = MAX_DIE; 
        }
    }
    else {
        if (dice1 > MAX_DIE) {
        dice1 = MAX_DIE; 
        }
    }
    
    printf("enter dice 2: "); 
    scanf("%d", &dice2); 
    
    printf("dice1 = %d \n", dice1);
    
    int dice_sum = dice1 + dice2; 
    
  //  if (dice_sum == SECRET_NUMBER) { 
        printf("you rolled the secret number. \n"); 
    }
     
  //  if (dice_sum > SECRET_NUMBER) { 
        printf("you rolled BIGGER than the secret number. \n"); 
    }
    
 //   if (dice_sum < SECRET_NUMBER) { 
        printf("you rolled smaller than the secret number. \n"); 
    }
    
    
    
     printf("dice1 = %d \n", dice1);
    return 0;
    
}
