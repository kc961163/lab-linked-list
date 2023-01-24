// Modify this file
// compile with: gcc linkedlist.c -o linkedlist.out

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// TODO: Create your node_t type here
typedef struct node {
    int year;
    int win;
    stuct node* next;
}node_t;

node_t* newnode(int win, int year, node_t* next) {
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    if (newnode == NULL) return 0;
    newnode->win = win;
    newnode->year = year;
    newnode->next = next;
    return newnode;
}

void free_node(node_t* node){
    if (node == NULL) return;
    free(node);
}

void print(node_t* node) {
    if (node == NULL) return;
    node_t* iter = node;
    while(iter != NULL){
        printf("%d %d",iter->win, iter->year);
        iter = iter->next;
    }
    printf("\n");
}

// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    // TODO: Implement me!
    node_t* head = newnode(10, 5, NULL);

    return 0;
}