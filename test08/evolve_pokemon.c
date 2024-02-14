// String Equality
// Created by
// PENGPENG-DUAN (z5361475)
// Created on 2021-08-04

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50

// Do not edit this struct. You may use it exactly as it is
// but you cannot make changes to it
struct pokemon {
    char name[MAX_NAME_SIZE];
    struct pokemon *evolution;
};

// Create a pokemon 
struct pokemon *create_pokemon(char name[MAX_NAME_SIZE]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    struct pokemon *new_pokemon = malloc(sizeof(struct pokemon));
    strcpy(new_pokemon->name, name);
    //new_pokemon->name = name;
    return new_pokemon;
}

// Link a pokemon to another that it evolves into
void evolve_pokemon(struct pokemon *base, struct pokemon *evolution) {

    base->evolution = evolution;
    evolution->evolution = NULL;
}

// Print out the evolution of a pokemon
void print_evolution(struct pokemon *p) {
    struct pokemon *final = p;
    // PUT YOUR CODE HERE
    while (final != NULL) { 
        printf("%s\n", final->name);
        
        final = final->evolution;
    }
}

// This is a simple main function which could be used
// to test your pokemon functions.
// It will not be marked.
// Only your pokemon functions will be marked.

int main(void) {
    struct pokemon *pikachu = create_pokemon("Pikachu");
    struct pokemon *raichu = create_pokemon("Raichu");
    evolve_pokemon(pikachu, raichu);
    print_evolution(pikachu);
    return 0;
}
