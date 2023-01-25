// Modify this file
// compile with: gcc linkedlist.c -o linkedlist.out

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// TODO: Create your node_t type here
typedef struct node {
    int year;
    int win;
    struct node* next;
}node_t;

node_t* newnode(int win, int year, node_t* next) {
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    if (newnode == NULL) return 0;
    newnode->win = win;
    newnode->year = year;
    newnode->next = next;
    return newnode;
}

void free_list(node_t* node){
    if (node == NULL) return;
    node_t* itr = node;
    while (itr != NULL){
        node_t* next = itr;
        itr = itr->next;
        free(next);
        
    }
    itr = NULL;
}

void print(node_t* node) {
    if (node == NULL) return;
    node_t* iter = node;
    while(iter != NULL){
        printf("%d %d ",iter->win, iter->year);
        printf("\n");
        iter = iter->next;
    }
    
}

node_t* build_list(int* wins, int* years, int size){

    node_t* dummy = (node_t*)malloc(sizeof(node_t));
    dummy->next = NULL;

    node_t* prev = dummy;

    for (int i = 0; i < size; i++){
        node_t* temp = newnode(wins[i], years[i], NULL);
        prev->next = temp;
        prev = prev->next;
    }
    node_t* head = dummy->next;
    free(dummy);
    return head;
     
}

// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    node_t* lists = build_list(test_wins, test_years, 5);

    print(lists);

    free_list(lists);

    // TODO: Implement me!
    // for(int i = 0; i < 5; i++){

    // }

    //node_t* head = newnode(10,2005,NULL);
    //node_t* node1 = newnode(20,2006, NULL);
    //printf("wins %d year %d ", head->win, head->year);
    //head->next = node1;
    //printf("%d %d\n", head->next->win, head->next->year);
    // node_t* node1 = newnode(test_wins[0], test_years[0], NULL);
    // node_t* node2 = newnode(test_wins[1], test_years[1], NULL);
    // node_t* node3 = newnode(test_wins[2], test_years[2], NULL);
    // node_t* node4 = newnode(test_wins[3], test_years[3], NULL);
    // node_t* node5 = newnode(test_wins[4], test_years[4], NULL);
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    // node5->next = NULL;

    //print(node1);




    return 0;
}