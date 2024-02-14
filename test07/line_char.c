#include <stdio.h> 
#include <stdlib.h> 
void function(char word[], int value, int length); 
int main (int argc, char *argv[]) { 
    
    int number = atoi(argv[2]);
       
    function(argv[1], number, argc);
}
    

void function(char word[], int value, int length) { 
    int i = 0; 
    while (i < length) { 
        if (i == value) { 
            printf("The character in position %d is %c", value, word[i]);

        } 
        i++;
    }
}