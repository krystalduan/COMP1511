// Assignment 2 21T2 COMP1511: Pokedex
// pokedex.c
//
// This program was written by PENGPENG-DUAN(z5361475)
// on 06-08-2021
//
// Version 1.0.0: Release
// Version 1.0.1: Fixed references to create_new_dexnode in comments and error messages

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ext_save.h"

// Note you are not allowed to use the strstr function in this assignment
// There are some techniques we would like you to learn to code
// that this function makes easier.

// ----------------------------------------------
// Add any extra #includes your code needs here.
// ----------------------------------------------

#include "pokedex.h"


// ----------------------------------------------
// Add your own #defines here.
// ----------------------------------------------

#define MAX_NAME_LENGTH  100
#define MAX_LENGTH 100

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.
struct pokedex {
    struct dexnode *head;
    struct dexnode *selected_dexnode;
    struct dexnode *last_dexnode;
    int no_of_pokemon;
   /* int id; 
    char name[MAX_NAME_LENGTH];
    double height;
    double weight; 
    char type_one[MAX_LENGTH]; 
    char type_two[MAX_LENGTH]*/
    
    ;
};


// You don't have to use the provided struct dexnode, you are free to
// make your own struct instead.
//
// If you use the provided struct dexnode, you will need to add fields
// to it to store other information.
struct dexnode {
    Pokemon pokemon;
    int found;
    struct dexnode *next;
    struct dexnode *prev;
};


// ----------------------------------------------
// Add your own structs here.
// ----------------------------------------------




// ----------------------------------------------
// Add prototypes for your own functions here.
// ----------------------------------------------

static int does_pokemon_already_exist(Pokedex pokedex, int id); 
void print_name_if_not_found(Pokedex pokedex);

// Creates a new dexnode struct and returns a pointer to it.
static struct dexnode *create_new_dexnode(Pokemon pokemon);


// You need to implement the following functions in their stages.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


// Creates a new Pokedex, and returns a pointer to it.
// Note: you will need to modify this function.
Pokedex new_pokedex(void) {
    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex new_pokedex = malloc(sizeof(struct pokedex));
    assert(new_pokedex != NULL);

    // Set the head of the linked list to be NULL.
    // (i.e. set the Pokedex to be empty)
    new_pokedex->no_of_pokemon = 0;
    new_pokedex->head = NULL;
    new_pokedex->selected_dexnode = NULL;
    new_pokedex->last_dexnode = NULL;

    // TODO: Add your own code here.

    return new_pokedex;
}

// Create a new dexnode struct and returns a pointer to it.
//
// This function should allocate memory for a dexnode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static struct dexnode *create_new_dexnode(Pokemon pokemon) {
    struct dexnode *new; 
    new = malloc(sizeof(struct dexnode)); 
    assert(new != NULL);
    new->next = NULL; 
    new->prev = NULL;
    new->found = 1;
    new->pokemon = pokemon; 

    //printf("The create_new_dexnode function has not been implemented yet!\n");

    return new;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    
    //struct dexnode *new_dexnode = new_
  //pokedex->head = create_new_dexnode;
    //printf("%d", pokemon->pokemon_id);

    //create a new pokemon to go into new_dexnode
   struct dexnode *new_dexnode = create_new_dexnode(pokemon);
   /* if (pokedex->head == NULL) { 
        pokedex->head = new_dexnode;
        pokedex->selected_dexnode = new_dexnode;
        pokedex->last_dexnode = new_dexnode;
    } else { 
        struct dexnode  *new = pokedex->last_dexnode;
       // struct pokenode *n = pokedex->last_dexnode->next;
        new->next = new_dexnode;
        //new->prev = pokedex->selected_dexnode;
        //new->selected_dexnode = new_dexnode;
    }*/

    if (pokedex->no_of_pokemon == 0) { 
        pokedex->head = new_dexnode;
        pokedex->selected_dexnode = new_dexnode;
    }
    if (pokedex->last_dexnode != NULL && pokedex->head != NULL) { 
        pokedex->last_dexnode->next = new_dexnode;
    }

    pokedex->last_dexnode = new_dexnode;
    pokedex->no_of_pokemon = pokedex->no_of_pokemon + 1;


    //printf("the number of pokemon is %d\n", pokedex->no_of_pokemon);
      
    //debug statement
   // printf("%d", pokemon_id(new_dexnode->pokemon));

    // Note: you should use the create_new_dexnode function here, and add
    // the newly-created dexnode to the end of the linked list of
    // dexnodes in the Pokedex.
   
}

// Print out all of the Pokemon in the Pokedex.
// ALL GOOD!
void print_pokedex(Pokedex pokedex) {
    struct dexnode *new = pokedex->head; 
    struct dexnode *new_selected_dexnode = pokedex->selected_dexnode;
    

    while (new != NULL && new_selected_dexnode != NULL) {
        if (pokedex->selected_dexnode->found == 1) {
            if (new->pokemon == new_selected_dexnode->pokemon) { 
                printf("--> ");
            } else { 
            printf("    ");
            }
            printf("#%03d: %s\n", pokemon_id(new->pokemon), pokemon_name(new->pokemon));
        } else if (pokedex->selected_dexnode->found == 0) {
            if (new->pokemon == new_selected_dexnode->pokemon) { 
                printf("--> ");
            } else { 
                printf("    ");
            }

            printf("#%03d: ", pokemon_id(new->pokemon)); 
            int i = 0;
            while (i < strlen(pokemon_name(new->pokemon))) { 

                printf("*");
                i++;
            }
            printf("\n");
        }
        //printf("#%03d: %s\n", pokemon_id(new->pokemon), pokemon_name(new->pokemon));
        //new_selected_dexnode = new_selected_dexnode->next;
        //pokedex->selected_dexnode = new;
         printf("head is %d\n", pokedex->head->found);
        printf("select is %d\n", pokedex->selected_dexnode->found);
        printf("select is %d\n", new_selected_dexnode->found);
        
        new = new->next;
        pokedex->selected_dexnode = new;
      
        // printf("select is %d\n", pokedex->selected_dexnode->found);
        //printf("select is %d\n", new_selected_dexnode->found);
        //new_selected_dexnode = new;
   }
   
}

// Print out the details of the currently selected Pokemon.
void detail_current_pokemon(Pokedex pokedex) {
    struct dexnode *n = pokedex->selected_dexnode;
    if (n->found == 1) {
        printf("ID: %03d\n", pokemon_id(n->pokemon));
        printf("Name: %s\n", pokemon_name(n->pokemon));
        printf("Height: %lf m\n", pokemon_height(n->pokemon));
        printf("Weight: %lf kg\n", pokemon_weight(n->pokemon));
    
        printf("Type: %s", type_code_to_str(pokemon_first_type(n->pokemon)));
        if (pokemon_second_type(n->pokemon) != type_str_to_code("None")) { 
            printf(" %s", type_code_to_str(pokemon_second_type(n->pokemon)));
        }
    } else if (n->found == 0) { 
        printf("ID: %03d\n", pokemon_id(n->pokemon));
        printf("Name: ");
        print_name_if_not_found(pokedex);
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    }
    
   /* pokemon_type second_type = pokemon_second_type(n->pokemon);
    if (second_type != NONE_TYPE) { 
        printf(" %s", type_code_to_str(pokemon_second_type(n->pokemon)));
    }*/
    //printf("\n");
    
    //    type_code_to_str(pokemon_second_type(n->pokemon)));
  // fprintf(stderr, "exiting because you have not implemented the detail_pokemon function\n");
    //exit(1);
}

// Return the currently selected Pokemon.
// ALL GOOD!
Pokemon get_current_pokemon(Pokedex pokedex) {
    Pokemon got_current_pokemon = NULL; 
    got_current_pokemon = pokedex->selected_dexnode->pokemon;

    return got_current_pokemon;
}

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    struct dexnode *select_next = pokedex->selected_dexnode;
    if (select_next->next != NULL && select_next != NULL) { 
        pokedex->selected_dexnode = pokedex->selected_dexnode->next;
    }
    //fprintf(stderr, "exiting because you have not implemented the next_pokemon function\n");
    //exit(1);
}

// Change the currently selected Pokemon to be the previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    // struct dexnode *select_prev = pokedex->selected_dexnode;
    struct dexnode *current_dexnode = pokedex->head;
   /* while(current_dexnode->next != pokedex->selected_dexnode) {
        if (current_dexnode != NULL && current_dexnode->next != NULL) {
            current_dexnode = current_dexnode->next;
        }

    }
     pokedex->selected_dexnode = current_dexnode; 
   */ 
        while(current_dexnode != NULL && current_dexnode->next != pokedex->selected_dexnode) { 
            current_dexnode = current_dexnode->next;
        }
        if (current_dexnode == NULL) { 
            pokedex->selected_dexnode = pokedex->head;    
        } else {
            pokedex->selected_dexnode = current_dexnode;    
        }
       // pokedex->selected_dexnode = current_dexnode;        
    
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void jump_pokemon(Pokedex pokedex, int id) {
    struct dexnode *current_dexnode = pokedex->head;
    while (current_dexnode != NULL) { 
        if (pokemon_id(current_dexnode->pokemon) == id) { 
            pokedex->selected_dexnode = current_dexnode;
        }
        current_dexnode = current_dexnode->next;
    }
    
}

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Sets the currently selected pokemon's "found" status
// ALL GOOD!
void set_current_pokemon_found(Pokedex pokedex, int found) {
    if (found == 1) { 
        pokedex->selected_dexnode->found = 1;
    } else if (found == 0) {
        pokedex->selected_dexnode->found = 0;
    }
    printf("head is %d\n", pokedex->head->found);
    printf("select is %d\n", pokedex->selected_dexnode->found);
    //fprintf(stderr, "exiting because you have not implemented the set_current_pokemon_found function\n");
   // exit(1);
}

// Add a pokemon before the current pokemon.
void insert_pokemon_before_current(Pokedex pokedex, Pokemon pokemon) {
    struct dexnode *current= pokedex->selected_dexnode;
    struct dexnode *next_pokemon = NULL;
    while (current != NULL) { 
        //current->next = current;
        //next_pokemon->pokemon = current->pokemon;
        next_pokemon = current;
        current->next->pokemon = current->pokemon;
        current->pokemon = pokemon;
        current = current->next;
        //new_pokemon = new_pokemon->next;
    }
    //next_pokemon->next->pokemon = next_pokemon->pokemon;
    /*if (current->next == NULL) { 
        current->pokemon
    }*/
    /*if (prev_pokemon == NULL) {
    }*/

    //fprintf(stderr, "exiting because you have not implemented the insert_pokemon_before_current function\n");
    //exit(1);
}

// Return the total number of Pokemon in the Pokedex.
int count_pokemon_of_type(Pokedex pokedex, char *type) {

    fprintf(stderr, "exiting because you have not implemented the count_pokemon_of_type function\n");
    exit(1);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////


// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the remove_pokemon function\n");
    exit(1);
}

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    struct dexnode *n = pokedex->head; 
    struct dexnode *n_next;
    while (n != NULL) { 
        destroy_pokemon(n->pokemon);
        n_next = n->next;
        free(n);
        n = n_next;
    }
    free(pokedex);
    pokedex = NULL;
    // Note: there is no fprintf or exit(1) in this function, as the
    // Stage 1 autotests call destroy_pokedex but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1, rather than exit).
}

// Prints out all types of found Pokemon stored in the Pokedex
void show_types(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the show_types function\n");
    exit(1);
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
   //int counter = 0;

    fprintf(stderr, "exiting because you have not implemented the count_found_pokemon function\n");
    exit(1);
}

// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    struct dexnode *new = pokedex->head;
    int counter = 0; 
    while (new != NULL) { 
        counter++;
        new = new->next;
    }
    return counter;
    
    //fprintf(stderr, "exiting because you have not implemented the count_total_pokemon function\n");
    //exit(1);
}

// NOTE: Make sure you submit ass2_pokedex before completing these.
//////////////////////////////////////////////////////////////////////
//                     Stage 4 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

/*
 * Saves a pokedex to a text file
 * Use the functions in ext_save.h to save the contents to a file
 */
void save_pokedex(Pokedex pokedex, char* filename) {
    fprintf(stderr, "exiting because you have not implemented the save_pokedex function\n");
    exit(1);

}

/*
 * Loads a pokedex from a text file
 * Use the functions in ext_save.h to load the text from a file
 */
Pokedex load_pokedex(char* filename) {
    fprintf(stderr, "exiting because you have not implemented the load_pokedex function\n");
    exit(1);

    return NULL;
}

//////////////////////////////////////////////////////////////////////
//                     Stage 5 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    fprintf(stderr, "exiting because you have not implemented the get_pokemon_of_type function\n");
    exit(1);
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the get_found_pokemon function\n");
    exit(1);
}

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    fprintf(stderr, "exiting because you have not implemented the search_pokemon function\n");
    exit(1);
}

// Free's the current sub-list and returns the original pokedex state, 
// prior to the search
Pokedex end_search(Pokedex sub_pokedex) {
    fprintf(stderr, "exiting because you have not implemented the end_search function\n");
    exit(1);
}

// Add definitions for your own functions here.
//Find out if the pokemon exists 
/*static int does_pokemon_already_exist(Pokedex pokedex, int id) { 
    struct dexnode *new = pokedex->head;

}*/
void print_name_if_not_found(Pokedex pokedex){
    struct dexnode *new = pokedex->selected_dexnode;
    int i = 0;
    while (i < strlen(pokemon_name(new->pokemon))) { 

        printf("*");
        i++;
    }
    printf("\n");
}
