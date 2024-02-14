#include <stdio.h>
#define MAX_DIGITS 36
int main (void) {
    int array[MAX_DIGITS] = {0};
    int i = 0;
    int keep_looping = 1;
    while (i < MAX_DIGITS && keep_looping) {
        int scan; 
        int result = scanf("%d", &scan);
        if (result == 1){
            array[scan] = 1;
        } else {
            keep_looping = 0;
        }
        i++;
    }

    i = 0;
    while (i < 36) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    return 0;
}

