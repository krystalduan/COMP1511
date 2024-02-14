
// Assignment 1 21T2 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by PENGPENG-DUAN (z5361475)
// on 01-07-21
//
// This program creates a Minesweeper game
// This program will not work if you enter invalid numbers during the initial
// scanf process
// Version 1.0.0 (2021-06-19): Assignment released.
#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE              8

// The possible command codes.
#define DETECT_ROW      1
#define DETECT_SQUARE   2
#define REVEAL_CROSS    3
#define GAME_MODE       4
#define FLAG_MINE       5
#define DEFUSE          6

// Add any extra #defines here.

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);
void print_gamemode_minefield(int minefield[SIZE][SIZE]);
void print_gamelost_minefield(int minefield[SIZE][SIZE]);
void print_minefield(int minefield[SIZE][SIZE], int x);
int initial_one(int minefield[SIZE][SIZE], int x, int gamemode_counter);
int initial_two(int minefield[SIZE][SIZE], int x, int gamemode_counter);
int initial_three (int minefield[SIZE][SIZE], int x, int no_of_mines, int gamemode_counter);
int check_validity(int a, int b);
void change_minefield_value(int minefield[SIZE][SIZE], int x, int y);
int game_won(int minefield[SIZE][SIZE], int no_of_mines);
int total_mines(int minefield[SIZE][SIZE], int square_start_row, 
    int square_end_row, int square_start_column, int square_end_column);

// Place your function prototyes here.

int main(void) {
    int minefield[SIZE][SIZE];
    int no_of_mines = 0;
    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
    scanf("%d", &no_of_mines);

    // TODO: Scan in the number of pairs of mines.
    int i = 0;
    printf("Enter pairs:\n");
    while (i < no_of_mines) {
        int pair_row = 0;
        int pair_column = 0;
        scanf("%d %d", &pair_row, &pair_column);
        if (pair_row >= 0 && pair_row <= SIZE && pair_column >= 0 
                && pair_column <= SIZE) {
            minefield[pair_row][pair_column] = HIDDEN_MINE;
        }
        i++;
    }
    //start the game
    printf("Game Started\n");
    print_debug_minefield(minefield);

    //keep the game going unless it is won/lost, however, this method
    //also means that the program will stop if the initial scanf value 
    //is incorrect (ie. not 1, 2, 3 or 4)
    int keep_looping = 1;
    int counter_for_help = 0;
    int gamemode_counter = 1;
    while (keep_looping == 1) { 
        int initial = 0; 
        scanf("%d", &initial);
        
        if (initial == 1 && counter_for_help < 3) {
            
            counter_for_help = initial_one(minefield, counter_for_help, gamemode_counter);
           
        } else if (initial == 2 && counter_for_help < 3) { 
            counter_for_help = initial_two(minefield, counter_for_help, gamemode_counter);
            
        } else if (initial == 3) { 
            keep_looping = initial_three(minefield, keep_looping, no_of_mines,
                 gamemode_counter);  
            
        } else if (counter_for_help == 3 && (initial == 2 || initial == 1)) { 
            int useless_one, useless_two, useless_three;
            scanf("%d %d %d", &useless_one, &useless_two, &useless_three);
            printf("Help already used\n");
            print_minefield(minefield, gamemode_counter);
        } else if (initial == 4) { 
            gamemode_counter++;
            gamemode_counter = gamemode_counter % 2;
            
            if (gamemode_counter == 0) { 
                printf("Gameplay mode activated\n");
                print_gamemode_minefield(minefield);
            } else if (gamemode_counter == 1) { 
                printf("Debug mode activated\n");
                print_debug_minefield(minefield);
            }
        }
        else {
            keep_looping = 0;
        }
    }


    return 0;
}


// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}


// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
} 
// Print out the values of the minefiled if it's in gameplay mode
void print_gamemode_minefield(int minefield[SIZE][SIZE]) {
    printf("..\n");
    printf("\\/\n");
    int initial_column = 0;
    while (initial_column < SIZE + 4) { 
        if (initial_column < 4) { 
            printf(" ");
        } else if (4 <= initial_column && initial_column < SIZE + 4) { 
            printf("0%d ", initial_column - 4);
        }
        
        initial_column++;
    }
    printf("\n");
    initial_column = 0;
    while (initial_column < 28) { 
        if (initial_column < 3) { 
            printf(" ");
        } else if (3 <= initial_column && initial_column <= 28) { 
            printf("-");
        }
        initial_column++;
    }
    printf("\n");
    int row = 0;
    while (row < SIZE) {
        printf("0%d |", row);
        int column = 0;
        while (column < SIZE) {
            if (minefield[row][column] == VISIBLE_SAFE) {
                int row_start = row - 1;
                int row_end = row + 1;
                int column_start = column - 1; 
                int column_end = column + 1;
                int total_mines_to_print = total_mines(minefield, row_start, 
                    row_end, column_start, column_end);
                if (total_mines_to_print == 0) {
                    printf("  ");
                } else {
                    printf("0%d", total_mines_to_print);
                }
            }
            else { 
                printf("##");
            }
            if (column < SIZE - 1) {
                printf(" ");
            }
            
            column++;
        }
        printf("|\n");
        row++;
    }
    initial_column = 0;
    while (initial_column < 28) { 
        if (initial_column < 3) { 
            printf(" ");
        } else if (3 <= initial_column && initial_column <= 28) { 
            printf("-");
        }
        initial_column++;
    }
    printf("\n");
} 

//minefield that reveals mines after game is lost
void print_gamelost_minefield(int minefield[SIZE][SIZE]) { 
    printf("xx\n");
    printf("/\\\n");
    int initial_column = 0;
    while (initial_column < SIZE + 4) { 
        if (initial_column < 4) { 
            printf(" ");
        } else if (4 <= initial_column && initial_column < SIZE + 4) { 
            printf("0%d ", initial_column - 4);
        }
        initial_column++;
    }
    printf("\n");
    initial_column = 0;
    while (initial_column < 28) { 
        if (initial_column < 3) { 
            printf(" ");
        } else if (3 <= initial_column && initial_column <= 28) { 
            printf("-");
        }
        initial_column++;
    }
    printf("\n");
    int row = 0;
    while (row < SIZE) {
        printf("0%d |", row);
        int column = 0;
        while (column < SIZE) {
            if (minefield[row][column] == VISIBLE_SAFE) {
                int row_start = row - 1;
                int row_end = row + 1;
                int column_start = column - 1; 
                int column_end = column + 1;
                int total_mines_to_print = total_mines(minefield, row_start, 
                    row_end, column_start, column_end);
                if (total_mines_to_print == 0) {
                    printf("  ");
                } else {
                    printf("0%d", total_mines_to_print);
                }
            }
            else if (minefield[row][column] == 2) { 
                printf("()");
            }
            else { 
                printf("##");
            }
            if (column < SIZE - 1) {
                printf(" ");
            }
            
            column++;
        }
        printf("|\n");
        row++;
    }
    initial_column = 0;
    while (initial_column < 28) { 
        if (initial_column < 3) { 
            printf(" ");
        } else if (3 <= initial_column && initial_column <= 28) { 
            printf("-");
        }
        initial_column++;
    }
    printf("\n");
}

//check the validity of the numbers (0 < x < size)
int check_validity(int a, int b) { 
    int validity;
    if (0 <= a &&  a < 8 && 0 <= b && b < 8) { 
        validity = 1;
    } else {
        validity = 0;
    }
    return validity;
}

//give hint for initial = 2 (detect row)
int total_mines(int minefield[SIZE][SIZE], int square_start_row, int square_end_row, 
        int square_start_column, int square_end_column) {
    int row_counter = square_start_row;
    int total_mines_overall = 0;
    while (row_counter <= square_end_row && row_counter < SIZE) {
        int column_counter = square_start_column;
        int total_mines_in_row = 0;
        while (column_counter <= square_end_column && column_counter < SIZE) {
            if (row_counter >= 0 && column_counter >= 0 
                    && minefield[row_counter][column_counter] == 2) {
                total_mines_in_row++;
            }
            column_counter++;
        } 
        row_counter++;
        total_mines_overall = total_mines_overall + total_mines_in_row;
    }
    return total_mines_overall;
}

//change the values in minefield array for when inital = 3 (reveal cross)
void change_minefield_value(int minefield[SIZE][SIZE], int row, int column) {
    int validity = check_validity(row, column);
    int row_start = row - 1;
    int row_end = row + 1;
    int column_start = column - 1; 
    int column_end = column + 1;
    if (validity == 1) {
        int total_mines_overall = total_mines(minefield, row_start, row_end, 
            column_start, column_end);
        if (total_mines_overall == 0 ) { 
            minefield[row][column] = VISIBLE_SAFE;
        }
    }       
}
//find out if the game has been won 
int game_won(int minefield[SIZE][SIZE], int no_of_mines) {
    int game_has_been_won;
    int i = 0; 
    int total_revealed_squares = 0;
    while (i < SIZE) {
        int j = 0; 
        int revealed_squares_in_row = 0;
        while (j < SIZE) { 
            if (minefield[i][j] == VISIBLE_SAFE) { 
                revealed_squares_in_row++;
            }
            j++;
        }
        i++;
        total_revealed_squares = total_revealed_squares + revealed_squares_in_row;
    }
    if (total_revealed_squares == 64 - no_of_mines) { 
        game_has_been_won = 1;
    } else { 
        game_has_been_won = 0;
    }
    return game_has_been_won;
}
// function for when the initial scanf is equal to one
int initial_one(int minefield[SIZE][SIZE], int x, int gamemode_counter) {
    int row_no = 0;
    int column_start = 0;
    int column_length = 0;
    scanf("%d %d %d", &row_no, &column_start, &column_length);
    int column_end = column_start + column_length -1;
    int validity = check_validity(row_no, column_start);
    if (validity == 1 && column_end < SIZE) {
        int counter = 0;
        int total_mines = 0; 
        while (counter <= column_end) {
            if (column_start <= counter && minefield[row_no][counter] == 2) {
                total_mines++;
            }
            counter++;   
        } 

        printf("There are %d mine(s) in row %d, from column %d to %d\n", total_mines, 
            row_no, column_start, column_end );
        print_minefield(minefield, gamemode_counter);
        x++;
    } else if (validity != 1 && gamemode_counter == 0) { 
        printf("Coordinates not on map\n");
        print_gamemode_minefield(minefield);
    }
    else {
        printf("Coordinates not on map\n");
        print_debug_minefield(minefield);
    } 
    return x;
}

// function for when the initial scanf is equal to two
int initial_two(int minefield[SIZE][SIZE], int x, int gamemode_counter){
    int row, column, size_of_square;
    scanf("%d %d %d", &row, &column, &size_of_square);
    int length_to_add = size_of_square/2;
    int square_start_column = column - length_to_add;
    int square_end_column = column + length_to_add;
    int square_start_row = row - length_to_add;
    int square_end_row = row + length_to_add;
    int validity = check_validity(row, column);
    if (validity == 1) {
        int total_mines_overall = total_mines(minefield, 
            square_start_row, square_end_row, square_start_column, square_end_column); 
        printf("There are %d mine(s) in the square centered at row %d, column %d of size %d\n", total_mines_overall, 
            row, column, size_of_square);
        //counter for help 
        x++;
        print_minefield(minefield, gamemode_counter);        
    } else if (validity != 1 && gamemode_counter == 0) { 
        printf("Coordinates not on map\n");
        print_gamemode_minefield(minefield);
    } else {
        printf("Coordinates not on map\n");
        print_debug_minefield(minefield);
    }
    return x;
}

// function for when the initial scanf is equal to three
int initial_three (int minefield[SIZE][SIZE], int x, 
        int no_of_mines, int gamemode_counter) { 
    int row_three, column_three; 
    scanf("%d %d", &row_three, &column_three);
    int row_start = row_three - 1;
    int row_end = row_three + 1;
    int column_start = column_three - 1; 
    int column_end = column_three + 1;
    int validity = check_validity(row_three, column_three);     
    if (validity == 1 && minefield[row_three][column_three] == 2) { 
        printf("Game over\n");
        if (gamemode_counter == 1) {
            print_debug_minefield(minefield);
        } else if (gamemode_counter == 0) { 
            print_gamelost_minefield(minefield);
        }
        x = 0;
    } else if (validity == 1) { 
        minefield[row_three][column_three] = VISIBLE_SAFE;
        change_minefield_value(minefield, row_start, column_three);
        change_minefield_value(minefield, row_end, column_three);
        change_minefield_value(minefield, row_three, column_start);
        change_minefield_value(minefield, row_three, column_end);
                
        int stop_game = game_won(minefield, no_of_mines);
        if (stop_game == 1) { 
            printf("Game Won!\n");
            print_minefield(minefield, gamemode_counter);
            x = 0; 
        } else {
            print_minefield(minefield, gamemode_counter);
        }
    } else if (validity == 0) {
        printf("Coordinates not on map\n");
        print_minefield(minefield, gamemode_counter);
    }
    return x;
}

void print_minefield(int minefield[SIZE][SIZE], int x) {
    if (x == 1) {
        print_debug_minefield(minefield);
    } else if (x == 0) { 
        print_gamemode_minefield(minefield);
    }
}
