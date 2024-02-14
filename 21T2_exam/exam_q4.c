// This program was written by z5361475
// on 18-08-2021

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};


// fix_counting is given a pointer to a linked list containing consecutive integers
// except there may be one missing integer
// fix_counting should return a pointer to a list
// with the missing integer added (if there was a missing integer)
struct node *fix_counting(struct node *head) {
    if (head->next == NULL) { 
        return head;
    }
    struct node *loop = head;
    int counter = 0;
    while (loop != NULL && loop->next != NULL) { 
        if (loop->data != loop->next->data - 1) { 
            counter++;
        }
        loop = loop->next;
    }
    //printf("counter is %d\n", counter);

    if (counter == 0) { 
        return head;
    } else { 
        struct node *current = head; 
        //struct node *prev = NULL;
        struct node *new = malloc(sizeof (struct node));
        while (current->data == current->next->data - 1) { 
            //prev = current;
            current = current->next;
        }
        //printf("prev is %d\n", prev->data);
        //printf("current is %d\n", current->data);
        new->next = current->next;
        new->data = current->data + 1;
        //printf("new is %d\n", new->data);
        //printf("new->next->data is %d\n", new->next->data);
        current->next = new;

        return head;
    }
    // PUT YOUR CODE HERE (change the next line!)
    return NULL;

}


///////////////////////////////////////////////////////////////
//
// YOU DO NOT NEED TO UNDERSTAND CODE BELOW THIS COMMENT
// 
// DO NOT CHANGE CODE BELOW THIS COMMENT
//
// IF YOU THINK YOU NEED TO CHANGE ANYTHING BELOW THIS COMMENT,
// YOU HAVE MISUNDERSTOOD THE QUESTION
//
///////////////////////////////////////////////////////////////

// DO NOT CHANGE THIS MAIN FUNCTION

struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

int main(int argc, char *argv[]) {

    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    struct node *new_head = fix_counting(head);
    print_list(new_head);

    return 0;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
