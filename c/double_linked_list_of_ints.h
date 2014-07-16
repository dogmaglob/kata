typedef struct _double_linked_list_of_ints_node * double_linked_list_of_ints;

double_linked_list_of_ints
create_double_linked_list_of_ints(int value);

void 
add_to_double_linked_list_of_ints(double_linked_list_of_ints linked_list,
                                  int value);

void
print_double_linked_list_of_ints(double_linked_list_of_ints linked_list);

