#include <stdio.h> 
#define NUM_PLAYERS 4

int main (void) { 
    int array[NUM_PLAYERS] = {}; 
    int i = 0; 
//scanning in
    while (i < NUM_PLAYERS) {
        printf("Please enter player %d's score: ", i);
        scanf("%d", &array[i]);
        i++;
    }

// print highest 
    int j = 0;
    int highest = 1; 
    while (j < NUM_PLAYERS) { 
        if (highest < array[j]) { 
            highest = array[j];
        }
        j++;
    }
    printf("the highest score was %d\n", highest); 
//print total 
    j = 0;
    int total = 0; 
    while (j < NUM_PLAYERS) { 
        total = total + array[j];
        j++;
    } 
    
    printf("the total is %d\n", total);
    
    return 0;
}
