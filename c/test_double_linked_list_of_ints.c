#include "double_linked_list_of_ints.h"

int main(void) {
    double_linked_list_of_ints ll = create_double_linked_list_of_ints(1);
    print_double_linked_list_of_ints(ll);
    add_to_double_linked_list_of_ints(ll, 2);
    print_double_linked_list_of_ints(ll);
    add_to_double_linked_list_of_ints(ll, 3);
    print_double_linked_list_of_ints(ll);
}
