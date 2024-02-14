//This code was written by PENGPENG-DUAN(z5361475)
//on 20-07-2021.
#include <stdio.h> 
void letter(char word1[]);
//void make_lowercase(int length, char word[]); 
int main (int argc, char *argv[]) {
    int i = 1; 
    while (i < argc ) { 
        //if (argv[i] < )
        letter(argv[i]);
        //printf("%s\n", argv[i]); 
        i++;
    }


    //make_lowercase(argc, argv[1]);
    printf("\n");
    return 0;
    
}
void letter(char word1[]) { 
    int i = 0;
    while (word1[i] != '\0') { 
        if (word1[i] >= 'A' && word1[i] <= 'Z') { 
            int alphabet_position_lower = word1[i] - 'A';
            int ascii = 'a' + alphabet_position_lower;
            putchar(ascii);
        } else if (word1[i] == '\n') { 
            putchar(32);
        }
        else { 
            printf("%c", word1[i]);
        }
        i++;
    }
}

\