#include <stdio.h> 

#define NUM_SCORES 4 

int main (void) { 
    int scores[NUM_SCORES] = {0};
    
    scores [0] = 55; 
    scores [1] = 76; 
    scores [2] = 98;
    scores [3] = 44;
    
    //counter 
    int i = 0; 
    while (i < NUM_SCORES) {
        printf("Player %d has scored %d. \n", i, scores[i]); 
        i++;
    }
    
    int highest = 0; 
    int highest_player = -1;
    i = 0;
    while (i < NUM_SCORES) { 
        if (scores[i] > highest) { 
            highest = scores[i]; 
            highest_player = i;
        }
        i++;
    }
    printf("Player %d scored the highest with %d", highest_player, highest);
    
    return 0; 
}
