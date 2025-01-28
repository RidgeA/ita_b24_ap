#include "stdio.h"
#include <stdlib.h>

int main() {
    int* arr = malloc(10 * sizeof(int));

    arr[0] = 1;
    arr[1] = 2;

    free(arr);
}

