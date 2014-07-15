#include "two_dimensional_array_of_ints.h"

void zero_multi_array(int ** a, int r, int c) {
    // first pass, note everywhere there is a zero
    int zr[r];
    int i;
    for (i = 0; i < r; i++) {
        zr[i] = 1;
    }
    int zc[c];
    int j;
    for (j = 0; j < c; j++) {
        zc[j] = 1;
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] == 0) {
               zr[i] = 0;
               zc[j] = 0;
            }
        }
    } 
    // second pass, zero out rows and columns
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            a[i][j] = a[i][j] * zr[i] * zr[j];
        }
    }
}

int main (void) {

    int ** ma = create_two_dimensional_array_of_ints(3, 3);
    
    ma[0][0] = 1;
    ma[0][1] = 2;
    ma[0][2] = 3;
    ma[1][0] = 4;
    ma[1][1] = 0;
    ma[1][2] = 6;
    ma[2][0] = 7;
    ma[2][1] = 8;
    ma[2][2] = 9;

    zero_multi_array(ma, 3, 3);

    print_two_dimensional_array_of_ints(ma, 3, 3);

    free_two_dimensional_array_of_ints(ma, 3, 3);
}
