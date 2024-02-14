//this code was written by PENGPENG-DUAN (z5361475)
//on 22-07-2021
#include <stdio.h> 
#include <stdlib.h> 

#define ALPHABET 26

int shift_function(int shift, int character); 

int main (int argc, char *argv[]) {
    if (argc != 2) { 
        printf("number not detected");
    }
    //convert argv into an int using atoi
    int shift_size = atoi(argv[1]); 

    if (shift_size < 0) {
        shift_size = (shift_size % ALPHABET) + ALPHABET;
    }
    int character = getchar();

    while (character != EOF) {
        int new_character = shift_function(shift_size, character);
        putchar(new_character);
        character = getchar();
    }


    
    return 0;

}

int shift_function (int shift, int character) { 
    if ('A' <= character && character <= 'Z') { 
        character = ((character - 'A' + shift) % ALPHABET+ 'A');
        return character; 
    } else if ('a' <= character && character <= 'z') { 
        character = ((character - 'a' + shift) % ALPHABET+ 'a');
        return character;
    } else { 
        return character; 
    }
    //return shift;
}



