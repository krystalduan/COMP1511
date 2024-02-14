//this code was written by PENGPENG-DUAN (z5361475)
//on 22-07-2021
#include <stdio.h> 

int encrypt(int character, char word[]); 

int main (int argc, char *argv[]) { 
    //doesn't have 2 inputs
    if (argc != 2) { 
        printf("Not supported");
    }

    int character = getchar();
    while (character != EOF) { 
        int new_character = encrypt(character, argv[1]);
        putchar(new_character);
        character = getchar();
    }
}

//function 
int encrypt(int character, char word[]) { 
    if ('A' <= character && character <= 'Z') { 
        character = word[character - 'A'] - 'a' + 'A';
        return character; 
    } else if ('a' <= character && character <= 'z') { 
        character = word[character - 'a']; 
        return character;
    } else { 
        return character; 
    }
}
