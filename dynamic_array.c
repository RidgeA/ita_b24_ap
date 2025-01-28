#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 8

// Простий динамічний масив цілих чисел
typedef struct
{
    int size;
    int *array;
} dynamic_int_array;

// Створює новий масив
dynamic_int_array *new_dynamic_array()
{
    dynamic_int_array *i = malloc(sizeof(dynamic_int_array));
    if (i == NULL)
        return NULL;

    i->size = 0;
    i->array = malloc(sizeof(int) * INITIAL_CAPACITY);
    if (i->array == NULL)
    {
        free(i);
        return NULL;
    }
    return i;
}

// Додає число в кінець масиву
int append(dynamic_int_array *arr, int value)
{
    if (arr->size == INITIAL_CAPACITY)
    {
        int capacity = arr->size * 2;
        int *copy_array;
        // copy_array = malloc(sizeof(int)*capacity);
        // memcpy(copy_array,arr->array,sizeof(int)*arr->size);
        // free(arr->array)
        copy_array = realloc(arr->array, sizeof(int) * capacity);
        if (copy_array == NULL)
            return 0;
        arr->array = copy_array;
    }
    arr->array[arr->size] = value;
    arr->size++;
    return arr->size;
}

/**
// Повертає елемент за індексом
int get(const dynamic_int_array *arr, size_t index)
{
}

// Видаляє елемент та зсуває решту вліво
int delete(dynamic_int_array *arr, size_t index)
{
}
*/

void free_array(dynamic_int_array *arr)
{
    if (arr != NULL)
    {
        free(arr->array);
        free(arr);
    }
}

// "[1 2 3]"
void print_array(const dynamic_int_array *arr)
{
    printf("[");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->array[i]);
    }
    printf("] \n");
}

int main(void)
{
    dynamic_int_array *arr = new_dynamic_array();
    
    for (int i = 0; i < 10000000; i++) {
        append(arr, i);
    }
    
    //print_array(arr);
    free_array(arr);
}