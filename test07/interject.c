// COMP1511 Week 7 Test: Interject
//
// This program was written by PENGPENG-DUAN (z5361475)
// on 27-07-2021
//
// This program adds interjections to strings.

#include <stdio.h>

#include <string.h>

#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.

void interject(char *str, char *interject, int index) {
    // TODO: complete this function
    int i = 0; 
    int j = 0;
    int length = strlen(interject);
    int length_of_string = strlen(str);
    //printf("%d\n", length);
    char str1[MAX_SIZE] = {};
    
    while (i < length + length_of_string) { 
        if (index <= i && i < index + length) {
            str1[j] = str[index + j];
            str[index + j] = interject[j];
            j++;
        } else if (
            index + length <= i /*&& index + length + length > i*/ ) { 
            str1[j] = str[i];
            str[i] = str1[j - length];
            j++;
            str[length + length_of_string] = '\0';
        } 
           

        i++; 
        
    }
}



// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}
