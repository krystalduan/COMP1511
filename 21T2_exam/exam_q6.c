// exam_q6.c
//
// This program was written by z5361475
// on 18-08-2021


#include <stdio.h>
#include <stdlib.h>

// Do not edit this struct. You may use it exactly as
// it is but you cannot make changes to it

// A node in a linked list
struct node {
    int height;
    struct node *next;
};

// ADD ANY FUNCTION DECLARATIONS YOU WISH TO USE HERE

struct node *mountaineer(struct node *head) {
    // TODO: COMPLETE THIS FUNCTION
    //find the highest height 
    struct node *loop = head; 
    int highest_height = 0;
    int counter = 0;
    while (loop != NULL) {
        if (loop->height > highest_height) { 
            highest_height = loop->height;
        } 
        loop = loop->next;
        counter++;
    }
    printf("highest is %d\n", highest_height);
    //make new list to return 
    struct node *new_list = malloc(sizeof(struct node));
    new_list->height = highest_height;

    
    /*while (current->height != highest_height) { 
        current = current->next; 
    }*/
    int temp_highest_height = highest_height;
   /* while (current->height < temp_highest_height) { 
        printf("temp height is %d\n", temp_highest_height);
        temp_highest_height = current->height;
        new_list->next = current;
        //current = current->next;
    }*/
    //THIS IS THE ONE
    //GARRRGHGHGHGHGHGGHGH
    int i = 0;
    while (i < counter) {
        struct node *current = head; 
        //while ()
        if (current->next->height > temp_highest_height) { 
            printf("temp height is %d\n", temp_highest_height);
            temp_highest_height = current->height;
            free(current->next);
            new_list->next = current;
        }
        current = current->next;
        i++;
    }
    /*struct node *current = head; 
    if (current->next->height > temp_highest_height) { 
        printf("temp height is %d\n", temp_highest_height);
        temp_highest_height = current->height;
        free(current->next);
        new_list->next = current;
    }*/
    //debug statements
    while (new_list != NULL) { 
        printf("height is %d\n", new_list->height);
        new_list = new_list->next;
    }
    return new_list;
    
    
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

void print_and_free_list(struct node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d, ", head->height);
    print_and_free_list(head->next);
    free(head);
}

struct node *make_list(int length, char *argv[]) {
    struct node *head = malloc(sizeof (struct node));
    struct node *n = head;
    int i = 0;
    while (i < length) {
        n->height = strtol(argv[i + 1], NULL, 10);
        if (i < length - 1) {
            // there are more nodes to make
            n->next = malloc(sizeof (struct node));
            n = n->next;
        } else {
            n->next = NULL;
        }
        i++;
    }
    return head;
}

int main(int argc, char *argv[]) {
    struct node *head = make_list(argc - 1, argv);
    struct node *return_path = mountaineer(head);
    printf("Given stopping points: ");
    print_and_free_list(head);

    printf("Return stopping points: ");
    print_and_free_list(return_path);
    return 0;
}
