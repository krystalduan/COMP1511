//this code was written by PENGPENG-DUAN on 12-08-2021
// (z5361475)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_last(head);
    print_list(new_head);

    return 0;
}


//
// Delete the last node in list.
// The deleted node is freed.
// The head of the list is returned.
//
struct node *delete_last(struct node *head) {
    struct node *current = head;
    struct node *prev = NULL;
    if (current == NULL) { 
        return NULL;
    }
    while (current->next != NULL) { 
        prev = current;
        //printf("prev is %d", prev->data);
        current = current->next;
    }
    /*prev->next = current->next; 
    free(current); */

    if (prev == NULL) { 
        free(current);
        return NULL;
    } else { 
        prev->next = current->next; 
        free(current);
        return head;
    }
    // PUT YOUR CODE HERE (change the next line!)
  
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

