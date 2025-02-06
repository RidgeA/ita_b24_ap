#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 8

// Простий динамічний масив цілих чисел
typedef struct
{
    int size;
    int *array;
    int capacity;
} dynamic_int_array;

// Створює новий масив
dynamic_int_array *new_dynamic_array()
{
    dynamic_int_array *i = malloc(sizeof(dynamic_int_array));
    if (i == NULL)
        return NULL;

    i->size = 0;
    i->capacity = INITIAL_CAPACITY;
    i->array = malloc(sizeof(int) * i->capacity);

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
    if (arr->size >= arr->capacity)
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
        arr->capacity = capacity;
    }
    arr->array[arr->size] = value;
    arr->size++;
    
    return arr->size;
}


// Видаляє елемент та зсуває решту вліво
// [1, 2, 3, 4, 5] => delete(3) => [1, 2, 3, 5]
int delete(dynamic_int_array *arr, int index)
{
//    arr->array[0] = arr->array[1]
//    arr->array[1] = arr->array[2]

    for (int i = index; i < arr->size; i++) {
        arr->array[i] = arr->array[i+1];
        // *(arr->array+i) = *(arr->array+(i+1))    
        // printf("%d", *(arr->array+i));
    }
    arr->size--;
    return arr->size;
}

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
    
    for (int i = 0; i < 5; i++) {
        append(arr, i);
    }
    print_array(arr);
    delete(arr, 3);
    delete(arr, 3);
    print_array(arr);
    free_array(arr);


}