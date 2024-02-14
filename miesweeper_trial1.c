// Assignment 1 21T2 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by PENGPENG-DUAN (z5361475)
// on 01-07-21
//
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
int check_validity(int a, int b);
int change_minefield_value(int minefield[SIZE][SIZE], int x, int y);

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
        if (pair_row >= 0 && pair_row <= SIZE && pair_column >= 0 && pair_column <= SIZE){
             minefield[pair_row][pair_column] = HIDDEN_MINE;
        }
        i++;
    }

    printf("Game Started\n");
    print_debug_minefield(minefield);

//Detect Row 
    int keep_looping = 1;
    while (keep_looping == 1) { 
        int initial = 0; 
        scanf("%d", &initial);
        if (initial == 1){
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
                    if (column_start <= counter  && minefield[row_no][counter] == 2){
                    total_mines++;
                    }
                    counter++;   
                } 
                printf("There are %d mine(s) in row %d, from column %d to %d\n", total_mines, row_no, column_start, column_end );
                print_debug_minefield(minefield);
            } else {
                printf("Coordinates not on map\n");
                print_debug_minefield(minefield);
            }
        } else if (initial == 2) {
            int row, column, size_of_square;
            scanf("%d %d %d", &row, &column, &size_of_square);
            int length_to_add = size_of_square/2;
            int square_start_column = column - length_to_add;
            int square_end_column = column + length_to_add;
            int square_start_row = row - length_to_add;
            int square_end_row = row + length_to_add;
            int total_mines_overall = 0;
            int row_counter = square_start_row;
            int validity = check_validity(row, column);
            if (validity == 1){
                while (row_counter <= square_end_row){
                    int column_counter = square_start_column;
                    int total_mines_in_row = 0;
                    while (column_counter <= square_end_column) {
                        if (row_counter >= 0 && column_counter >= 0 &&  minefield[row_counter][column_counter] == 2) {
                        total_mines_in_row++;
                        }
                        column_counter++;
                    } 
                row_counter++;
                total_mines_overall = total_mines_overall + total_mines_in_row;
              
                }
                printf("There are %d mine(s) in the square centered at row %d, column %d of size %d\n", total_mines_overall, row, column, size_of_square);
                print_debug_minefield(minefield);
        } else if (initial == 3) { 
                int row_three, column_three; 
                scanf("%d %d", &row_three, &column_three);
                int row_start = row_three - 1;
                int row_end = row_three + 1;
            //    int column_start = column - 1; 
             //   int column_end = column + 1;
                change_minefield_value(minefield[SIZE][SIZE], row_start, column);
                print_debug_minefield(minefield);
        }
            else {
                printf("Coordinates not on map\n");
                print_debug_minefield(minefield);
            }
        }
        
        else {
            keep_looping = 0;
        }
    }

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.


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
            printf("%d", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int check_validity(int a, int b) { 
    int validity;
    if (0 <= a &&  a < 8 && 0 <= b && b < 8) { 
        validity = 1;
    } else {
        validity = 0;
    }
    return validity;
}

int change_minefield_value(int minefield[SIZE][SIZE], int x, int y) {
    int validity = check_validity(x, y);
    if (validity == 1 && minefield[x][y] == 1)  { 
        minefield[x][y] = 2;
    }
    return minefield[x][y];
}