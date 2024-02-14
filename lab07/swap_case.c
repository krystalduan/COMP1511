// Function to print out a string that has had it's cases swapped.
// swap_case.c
//
// This program was written by PENGPENG-DUAN (z5361475)
// on 19-07-2021
 
#include <stdio.h>

int swap_case(int character);

int main(void) {

    // TODO: Write this function, using the swap_case function.
    int value = getchar(); 
    while (value != EOF) { 
        int new_value = swap_case(value);
        putchar(new_value);
        value = getchar();
    }
   

    return 0;
}

int swap_case(int character) {
    // TODO: Write this function, which should:
    //  - return character in lower case if it is an upper case letter
    //  - return character in upper case if it is an lower case letter
    //  - return the character unchanged otherwise
    if (character >= 'a' && character <= 'z') { 
        int alphabet_position_lower = character - 'a';
        return 'A' + alphabet_position_lower;
    } else if (character >= 'A' && character <= 'Z') {
        int alphabet_position_upper = character - 'A';
        return 'a' + alphabet_position_upper;
    } else { 
        return character; 
    }
}

