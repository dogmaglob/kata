#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node * next;
    struct _node * prev;
} node;

typedef node * double_linked_list;

double_linked_list create_double_linked_list(int v) {
    double_linked_list l = malloc(sizeof(node));
    l->value = v;
    l->next = NULL;
    l->prev = NULL;
    return l;
}

void append_double_linked_list(double_linked_list l, int v) {
    node * n = malloc(sizeof(node));
    n->value = v;
    n->next = NULL;
    while (l->next) {
        l = l->next;
    }
    l->next = n;
    n->prev = l;
}

void print_double_linked_list(double_linked_list l) {
    printf("Forward\n");
    printf("%d", l->value);
    while (l->next) {
        l = l->next;
        printf("-->%d", l->value);
    }
    printf("\n\n");
    printf("Reverse\n");
    printf("%d", l->value);
    while (l->prev) {
        l = l->prev;
        printf("-->%d", l->value);
    }
    printf("\n\n");
}

void free_double_linked_list(double_linked_list l) {
    while (l) {
        node * tmp = l;
        l = l->next;
        free(tmp);
    }
}

int main (void) {
    double_linked_list l = create_double_linked_list(1);
    print_double_linked_list(l);
    append_double_linked_list(l, 2);
    print_double_linked_list(l);
    append_double_linked_list(l, 3);
    print_double_linked_list(l);
}

