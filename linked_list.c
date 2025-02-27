#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int num;
    struct node *next;
} node;

typedef struct
{
    node *head;
} linked_list;

/*
 * Створює новий порожній зв'язний список
 *
 * Повертає:
 * - Вказівник на новий список
 * - NULL у випадку помилки виділення пам'яті
 *
 * Приклад використання:
 * struct linked_list* list = create_list();
 * if (list == NULL) {
 *     // обробка помилки
 * }
 */
linked_list *create_list()
{
    linked_list *list = malloc(sizeof(linked_list));

    if (list == NULL)
    {
        return NULL;
    }

    return list;
}

/*
 * Додає новий елемент на вказану позицію
 *
 * Параметри:
 * list: вказівник на список
 * value: значення для додавання
 * index: позиція для вставки (0-based)
 *
 * Особливості:
 * - Якщо index <= 0, додає на початок
 * - Якщо index >= розмір списку, додає в кінець
 *
 * Приклад:
 * // list: null
 * insert(list, 1, 0); // 1(next:null)
 * insert(list, 2, 0); // 2(next:1) -> 1(next:null)
 * // list: 10 -> 20 -> 30
 * insert(list, 25, 1);    // 10 -> 25 -> 20 -> 30
 * insert(list, 5, 0);     // 5 -> 10 -> 25 -> 20 -> 30
 * insert(list, 40, 999);  // додасть в кінець: 5 -> 10 -> 25 -> 20 -> 30 -> 40
 */
void insert(linked_list *list, int value, int index)
{

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        // todo
    }
    n->num = value;

    if (list->head == NULL || index <= 0)
    {
        n->next = list->head;
        list->head = n;
        return;
    }

    int i = 0;
    node *current = list->head;
    while (current->next != NULL && i < index - 1)
    {
        current = current->next;
        i++;
    }
    n->next = current->next;
    current->next = n;
}

/*
 * Видаляє елемент з вказаної позиції
 *
 * Параметри:
 * list: вказівник на список
 * index: позиція елемента для видалення (0-based)
 *
 * Приклад:
 * // list: 10 -> 20 -> 30 -> 40
 * delete(list, 1);  // 10 -> 30 -> 40
 * delete(list, 0);  // 30 -> 40
 */
void delete(linked_list *list, int index)
{
    if(list->head == NULL){
        return;
    }

    if(index == 0){
        node *previous_head = list->head;
        list->head = list->head->next;
        free(previous_head);
        return;
    }

    int i=0;
    node *current = list->head;
    while (current!=NULL && i<index-1)
    {
        current=current->next;
        i++;
    }

    node *deleted_node = current->next;
    if(deleted_node !=NULL){
        current->next=deleted_node->next;
        free(deleted_node);
        return;
    }
    current->next=NULL;
    
}

/*
 * Шукає елемент у списку
 *
 * Параметри:
 * list: вказівник на список
 * value: значення для пошуку
 * index: вказівник на змінну, куди буде записана позиція знайденого елемента
 *
 * Повертає:
 * - true: якщо елемент знайдено
 * - false: якщо елемент не знайдено
 */
bool search(linked_list *list, int value, int *index)
{
}

/*
 * Повертає кількість елементів у списку
 *
 * Параметри:
 * list: вказівник на список
 *
 * Повертає:
 * - Кількість елементів у списку
 */
int get_size(linked_list *list)
{
}

/*
 * Виводить всі елементи списку
 *
 * Параметри:
 * list: вказівник на список
 *
 * Формат виводу:
 * List: value1 -> value2 -> ... -> NULL
 */
void print_list(linked_list *list)
{
    node *current = list->head;
    while (current != NULL)
    {
        printf("%d -> ", current->num);
        current = current->next;
    }
    printf("Null \n");
}

/*
 * Звільняє пам'ять, виділену під список
 *
 * Параметри:
 * list: вказівник на список
 */
void free_list(linked_list *list)
{
    node *current = list->head;

    while (current != NULL)
    {
        node *next_node = current->next;
        free(current);
        current = next_node;
    }

    free(list);
}

/*
 * Приклад використання всіх функцій зв'язного списку
 */
int main()
{
    linked_list *list = create_list();

    insert(list, 0, 0);
    insert(list, 1, 0);
    insert(list, 2, 0);
    insert(list, 3, 0);
    insert(list, 4, 0);
    insert(list, 5, 2);
    insert(list, 6, 999);
    delete(list, 6);
    delete(list, 1);
    delete(list, 0);
    print_list(list);
    free_list(list);
    return 0;
}