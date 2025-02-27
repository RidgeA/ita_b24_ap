#include "stdio.h"
#include <stdlib.h>

int binary_search(int* arr, int len, int value) {
    int i= (len-1)/2;
    int min_i=0, max_i = len-1;
    while(arr[i]!=value){
        // printf("min = %d, max = %d, i=%d\n", min_i, max_i, i);
        if(arr[i]>value){
            max_i=i-1;
        }
        else{
            min_i=i+1;
        }
        i= (max_i+min_i)/2;
        if(max_i<i || min_i >i){
            return -1;
        }
    }
    return i;
}

int main() {

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    for (int i = 0; i < 11; i++) {
        int index = binary_search(arr, 11, i);
        if (i != index) {
            printf("Value: %d, index: %d", i, index);
        }
    }

    int index = binary_search(arr, 11, 11);
    printf("Index = %d\n", index);

    index = binary_search(arr, 11, -1);
    printf("Index = %d\n", index);
    
    return 0;
}