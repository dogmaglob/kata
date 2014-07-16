#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list_of_ints.h"

typedef struct _double_linked_list_of_ints_node {
    int value;
    struct _double_linked_list_of_ints_node * next;
    struct _double_linked_list_of_ints_node * prev;
} double_linked_list_of_ints_node;

double_linked_list_of_ints create_double_linked_list_of_ints(int value) {
    double_linked_list_of_ints_node * n = malloc(sizeof(double_linked_list_of_ints_node));
    n->value = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void add_to_double_linked_list_of_ints(double_linked_list_of_ints linked_list, 
                                       int value) {
    double_linked_list_of_ints_node * n = create_double_linked_list_of_ints(value);
    while (linked_list->next) {
        linked_list = linked_list->next;
    }
    linked_list->next = n;
    n->prev = linked_list;
}

void print_double_linked_list_of_ints(double_linked_list_of_ints linked_list) {
    printf("Forward\n");
    printf("%d", linked_list->value);
    while (linked_list->next) {
        linked_list = linked_list->next;
        printf("-->%d", linked_list->value);
    }
    printf("\n\n");
    printf("Reverse\n");
    printf("%d", linked_list->value);
    while (linked_list->prev) {
        linked_list = linked_list->prev;
        printf("-->%d", linked_list->value);
    }
    printf("\n\n");
}

