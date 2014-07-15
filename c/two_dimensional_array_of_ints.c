#include <stdio.h>
#include <stdlib.h>

/* Elements of the array are not initialized. */
int ** create_two_dimensional_array_of_ints(int number_of_rows, 
                                            int number_of_columns) {
    int ** a;
    a = malloc(number_of_rows * sizeof(int *));
    int i;
    for (i = 0; i < number_of_rows; i++) {
        a[i] = malloc(number_of_columns * sizeof(int));
    }
    return a;
}

void print_two_dimensional_array_of_ints(int ** array,
                                         int number_of_rows,
                                         int number_of_columns) {
    int i;
    for (i = 0; i < number_of_rows; i++) {
        int j;
        for (j = 0; j < number_of_columns; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void free_two_dimensional_array_of_ints(int ** array,
                                        int number_of_rows,
                                        int number_of_columns) {
    int i;
    for (i = 0; i < number_of_rows; i++) {
        free(array[i]);
    }
    free(array);
}

