#include <stdio.h> 
#include <stdlib.h> 

struct node { 
    struct node *next;
    int data; 
};

struct node *create_node(int d, struct node *n); 
void print_list(struct node *n); 

int main(void) { 
    struct node *print = create_node(42, NULL); 
    print = create_node(36, print);
    print = create_node(24, print);
    print = create_node(12, print);
    print_list(print);
    return 0; 
}

void print_list(struct node *n) { 
    while (n != NULL) { 
        printf("%d\n", n->data);
        n = n->next; 
    }
}

struct node *create_node (int d, struct node *n) { 
    struct node *new_node = malloc (sizeof (struct node));
    new_node->next = n; 
    new_node->data = d; 
    return new_node;
}