//This code was written by PENGPENG-DUAN
//(z5361475) on 26-07-2021
#include <stdio.h> 

int main (void) { 
    int character_one = getchar(); 
    int character_two = getchar();
    while (character_one != EOF && 
        character_two != EOF
        ) { 
        int smaller; 
        if (character_one < character_two) { 
            smaller = character_one;
        } else { 
            smaller = character_two;
        }
        putchar(smaller); 
        
        character_one = getchar(); 
        character_two = getchar();
    }
    printf("\n");
}