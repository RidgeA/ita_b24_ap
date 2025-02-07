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
 * position: позиція для вставки (0-based)
 *
 * Особливості:
 * - Якщо position = 0, додає на початок
 * - Якщо position >= розмір списку, додає в кінець
 * - Якщо position < 0, повертає помилку
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
void insert(linked_list *list, int value, int position)
{

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        // todo
    }
    n->num = value;

    if (position <= 0)
    {
        node *priviously_head = list->head;
        list->head = n;
        n->next = priviously_head;
    }
}

/*
 * Видаляє елемент з вказаної позиції
 *
 * Параметри:
 * list: вказівник на список
 * position: позиція елемента для видалення (0-based)
 *
 * Особливості:
 * - Якщо список порожній, виводить повідомлення про помилку
 * - Якщо position < 0 або position >= розмір списку, повертає помилку
 *
 * Приклад:
 * // list: 10 -> 20 -> 30 -> 40
 * delete(list, 1);  // 10 -> 30 -> 40
 * delete(list, 0);  // 30 -> 40
 */
void delete(linked_list *list, int position)
{
}

/*
 * Шукає елемент у списку
 *
 * Параметри:
 * list: вказівник на список
 * value: значення для пошуку
 * position: вказівник на змінну, куди буде записана позиція знайденого елемента
 *
 * Повертає:
 * - true: якщо елемент знайдено
 * - false: якщо елемент не знайдено
 */
bool search(linked_list *list, int value, int *position)
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
    print_list(list);
    free_list(list);
    /**
        // Додавання елементів
        insert(list, 10, 0);  // 10
        insert(list, 20, 1);  // 10 -> 20
        insert(list, 30, 1);  // 10 -> 30 -> 20
        insert(list, 40, 3);  // 10 -> 30 -> 20 -> 40

        printf("Після додавання елементів:\n");
        print_list(list);

        // Пошук елементів
        int position;
        if (search(list, 30, &position)) {
            printf("Елемент 30 знайдено на позиції: %d\n", position);
        }

        // Видалення елементів
        printf("\nВидалення елемента з позиції 1:\n");
        delete(list, 1);
        print_list(list);

        printf("\nВидалення елемента з початку (позиція 0):\n");
        delete(list, 0);
        print_list(list);

        printf("\nРозмір списку: %d\n", get_size(list));

        free_list(list);

    */
    return 0;
}