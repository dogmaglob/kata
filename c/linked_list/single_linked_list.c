#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node * next;
} node;

typedef struct _single_linked_list {
    node * head;
} single_linked_list;

single_linked_list * create_single_linked_list() {
    single_linked_list * l = malloc(sizeof(single_linked_list));
    l->head = NULL;
    return l;
}

void append_single_linked_list(single_linked_list * l, int v) {
    node * new = malloc(sizeof(node));
    new->value = v;
    new->next = NULL;
    if (!l->head) {
        l->head = new;
        return;
    }
    node * runner = l->head;
    while (runner->next) {
        runner = runner->next;
    }
    runner->next = new;
}

void print_single_linked_list(single_linked_list * l) {
    node * runner = l->head;
    if (!runner) {
        printf("empty list\n");
        return;
    }
    printf("%d", runner->value);
    while (runner->next) {
        runner = runner->next;
        printf("-->%d", runner->value);
    }
    printf("\n");
}

void free_single_linked_list(single_linked_list * l) {
    node * runner = l->head;
    while (runner) {
        node * tmp = runner;
        runner = runner->next;
        free(tmp);
    }
    free(l);
}

void delete_node(single_linked_list * l, int v) {
    node * runner = l->head;
    node * trailing = NULL;
    while (runner->value != v) {
        if (!runner->next) { //abort if not found
            return;
        }
        trailing = runner;
        runner = runner->next;
    }
    if (trailing) {
        trailing->next = runner->next;
    } else {
        l->head = runner->next;
    }
    free(runner);
}
    
int main(void) {
    single_linked_list * l = create_single_linked_list();
    append_single_linked_list(l, 1);
    print_single_linked_list(l);
    append_single_linked_list(l, 2);
    print_single_linked_list(l);
    append_single_linked_list(l, 3);
    print_single_linked_list(l);
    delete_node(l, 2);
    delete_node(l, 2);
    delete_node(l, 1);
    delete_node(l, 3);
    append_single_linked_list(l, 4);
    print_single_linked_list(l);
    free_single_linked_list(l);
}

