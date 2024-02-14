#include <stdio.h>

#define MAX_CARDS 1024

int read_input(int deck[MAX_CARDS]);
void print_deck(int deck[MAX_CARDS], int length);
void swap_nums(int num1, int num2);
void shuffle(int deck[MAX_CARDS], int length);


int main(void) {
    int deck[MAX_CARDS] = {0};
    int num_cards = read_input(deck);
    shuffle(deck, num_cards);
    print_deck(deck, num_cards);
}


// Asks the user how many cards are in their deck
// Then reads that many cards (or MAX_CARDS if the user says too many)
// Returns how many cards were read in
int read_input(int deck[MAX_CARDS]) {
    // scan in the number of cards
    int num_cards;
    printf("How many cards are in your deck?\n");
    scanf("%d", &num_cards);

    // loop through the deck, writing in the numbers that user types in
    int i = 0;
    while (i < num_cards && i < MAX_CARDS) { // have read i cards
        scanf("%d", &deck[i]);
        i++;
    } // have read i cards

    return i;
}


// Prints out the first 'length' elements from the deck array
void print_deck(int deck[MAX_CARDS], int length) {
    int i = 0;
    while (i < length && i < MAX_CARDS) {
        printf("%d, ", deck[i]);
        i++;
    }
    printf("\n");
}


// Swaps the integers at the destinations of the pointers num1 and num2
void swap_nums(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}


// call swap multiple times on different pairs to shuffle the deck
void shuffle(int deck[MAX_CARDS], int length) {
    int i = 0;
    while (i < length) {
        // find another index to swap with
        int j = (i * 3) % length;
        swap_nums(deck[i], deck[j]);
        i++;
    }
}