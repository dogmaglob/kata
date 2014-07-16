#include <stdio.h>
#include <stdlib.h>

typedef struct _single_linked_list_node {
    int value;
    struct _single_linked_list_node * next;
} single_linked_list_node;

typedef single_linked_list_node * single_linked_list;

single_linked_list create_single_linked_list_of_ints(int value) {
    single_linked_list_node * n = malloc(sizeof(single_linked_list_node));
    n->value = value;
    n->next = NULL;
    return n;
}

void add_to_single_linked_list_of_ints(single_linked_list linked_list, 
                                       int value) {
    single_linked_list_node * n = create_single_linked_list_of_ints(value);
    while (linked_list->next) {
        linked_list = linked_list->next;
    }
    linked_list->next = n;
}

void print_single_linked_list_of_ints(single_linked_list linked_list) {
    printf("%d", linked_list->value);
    while (linked_list->next) {
        linked_list = linked_list->next;
        printf("-->%d", linked_list->value);
    }
    printf("\n");
}

int main(void) {
    single_linked_list ll = create_single_linked_list_of_ints(1);
    print_single_linked_list_of_ints(ll);
    add_to_single_linked_list_of_ints(ll, 2);
    print_single_linked_list_of_ints(ll);
    add_to_single_linked_list_of_ints(ll, 3);
    print_single_linked_list_of_ints(ll);
}


