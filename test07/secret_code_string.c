#include <stdio.h> 
#include<stdlib.h>

void decode (char letter1[]);
int main (int argc, char *argv[]) { 

    
    decode(argv[1]);
}

void decode (char letter1[]) { 
    int i = 0; 
    int j = i + 1; 
    while (letter1[i] != '\0') { 
        int smaller = letter1[i];
        if (letter1[j] < letter1[i]) { 
            smaller = letter1[j];
        } else { 
            smaller = letter1[i];
        }
        printf("%d", smaller);
        i = i + 2; 
    }
    
    
}
