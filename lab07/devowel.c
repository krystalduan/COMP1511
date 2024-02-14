//This code was written by PENGPENG-DUAN (z5361475) 
//on 19-072021

//THis code takes in words and then prints the words 
//without the vowels 

#include<stdio.h> 
int main (void) { 
    int character = getchar(); 
    //int keep_looping = 0; 
    while (character != EOF) { 
        if (character != 'a' && character != 'e' && 
        character != 'i' && character != 'o' && character != 'u') { 
            putchar(character);
        } 
        character = getchar();
    }
    return 0; 
}