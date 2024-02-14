#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i = 0;
    while (i < argc) {
        int string_length = strlen(argv[i]);
        if (i == 2) {
            printf("argv[%d]'s third character is 'h'!\n", i);
        }
        i++;
    }
}