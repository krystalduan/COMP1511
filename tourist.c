#include <stdio.h> 
#define MAP_ROWS 10
#define MAP_COLUMNS 10

void print_map (int map[MAP_ROWS][MAP_COLUMNS], int t_row, int t_column);

int main (void) {
    int map[MAP_ROWS][MAP_COLUMNS] = {0};
    
    int keep_looping = 1; 
    int tourist_row = 3; 
    int tourist_column = 5;
    while (keep_looping) {
        print_map(map, tourist_row, tourist_column);
        map[tourist_row][tourist_column] = 1;
        printf("Type in 2, 4, 6, 8 to move in that direction: ");
        int direction; 
        scanf("%d", &direction);
        if (direction == 2) { 
            tourist_row++;
        } else if (direction == 4) {
            tourist_column--;
        } else if (direction == 6) {
            tourist_column++;
        } else if (direction == 8) { 
            tourist_row--;
        }
    }
}

void print_map (int map[MAP_ROWS][MAP_COLUMNS], int t_row, int t_column) { 
    int row = 0; 
    while (row < MAP_ROWS) {
        int column = 0;
        while (column < MAP_COLUMNS) {
            if (row == t_row && column == t_column) {
                printf("T");
            } else {
                printf("%d", map[row][column]);
            }
            column++;
        }
        printf("\n");
        row++;
    }
}