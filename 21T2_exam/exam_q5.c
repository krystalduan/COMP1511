// exam_q5.c
//
// This program was written by z5361475
// on 18-08-2021


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 

int main(int argc, char *argv[]) {
    int keep_looping = 0; 
    char word[100] = {};
    //char character_to_end_loop;
    scanf("%s", word);
    //char character_to_end_loop = word[0];
    
    while (keep_looping != EOF) { 
        /*char word[100] = {};
        scanf("%s", word);*/
        int length_comparison = strlen(argv[1]);
        int length_main = strlen(word);
        //printf("%s\n", word);
        int total_matches = 0;
        //printf("%s\n", argv[1]);
        //counter for match loop
        int counter = 1;
        while (counter < argc) { 
            length_comparison = strlen(argv[counter]);
            if (length_main >= length_comparison 
            && !strcmp(word + length_main - length_comparison, argv[counter])) {
                total_matches ++;
       
            }
            counter++;
        }
    
        //printf("counter is %d\n", total_matches);
        int i = 0; 
        while (i < total_matches) { 
            printf("%s\n", word);
            i++;

        }
        //scanf("%s", word);
        //character_to_end_loop = word[0];
        keep_looping = scanf("%s", word);
    }
    
    return 0;
}
