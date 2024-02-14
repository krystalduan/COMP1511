//This code was written by PENGPENG-DUAN on 15-08-2021
// (z5361475)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_second_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_second_last(head);
    print_list(new_head);

    return 0;
}


//
// Delete the second last node in the list.
// The deleted node is freed.
// The head of the list is returned.
//
struct node *delete_second_last(struct node *head) {
    if (head == NULL) { 
        return NULL;
    } else if (head->next == NULL) { 
        return head;
    } else if (head->next->next == NULL) {
        struct node *temp = head->next; 
        free(head);
        return temp;
    } else { 
        struct node *n = head; 
        struct node *new = NULL;
        while (n->next->next != NULL) { 
            //printf("n->next is %d", n->next->data);
            new = n;
            n = n->next;
            // printf("n->next is %d", n->data);
        }
        new->next = n->next;
        // printf("replacement is %d", new->data);
        // replacement = n->next;
        free(n);
    
/*
    printf("it starts from %d\n", head->data);
        while (head != NULL) { 
            printf("head is %d\n", head->data); 
            head = head->next;
        }
*/

    // printf("it ends from %d\n", head->data);
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

