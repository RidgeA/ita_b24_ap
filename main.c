#include "stdio.h"
#include <stdlib.h>

int main() {
    int* arr = malloc(10 * sizeof(int));

    arr[0] = 1;
    arr[1] = 2;

    free(arr);
}

/* 

key     -> value
"lorem" -> 2
"ipsum" -> 1

432156 % 100 -> 56

123456 % 100 -> 56
(123456 / 100) % 100 = 1234 % 100 = 34

int hash(key string) {
 //"lorem" -> 34 65 23 16 12 -> 2354 % 100 -> 54
 //"ipsum" ->        ...     -> 2354      -> 4
 // crc32
 // md5
}

typedef struct {
    key string
    value int
} map_item;

typedef []map_item bucket;

typedef struct {
    
    // h(key) % 100 : (h(key) / 100) % 100 : map_item
    data [][]bucket;

    // keys_and_values []map_item;
} map;

bool has(map, key) {}

void set(map, key, value) {
    idx = h(key)
    data[idx] = {key:key, value:value}
}

int get(map, key) {
    idx = h(key)
    map_item_candidates = map[idx]

    foreach (candidate in map_item_candidates) {
        if (candidate.key == key) {
            return candidate.value;
        }
    }
}

map = new_map();
words []string = ["lorem", "ipsum", "sit", "lorem", ...]
foreach (word in words) {
    if (!has(map, word)) {
        set(map, word, 1)
    } else {
        c = get(map, word)
        c = c + 1
        set(map, word, c)
    }
}


 */