#include <stdio.h> 

int main (void) { 
    int c2 = getchar();
    printf("First %d\nSecond:\n", c2);
    char word[] = "hello";
    int i = 0; 
    while (word[i] != 0) { 
        printf("%d", word[i]);
        i++;
    }

    //printf("%s", word);
    fputs(word, stdout);
}