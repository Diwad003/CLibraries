#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <stdbool.h>

typedef void (*kill_function)(void*);
typedef int (*compare_function)(void*, void*);

typedef struct cell {
    struct cell* next;
    struct cell* prev;

    void* val;
} cell;

typedef struct list {
    cell *head;
    cell *tail;
    kill_function kill_func;
    compare_function compare_func;
} list;

list* list_create(kill_function kill_func, compare_function compare_func);
int list_is_empty(list* l);
void list_insert(list* l, void* v, const int v_length);
void* list_inspect(cell* p);
cell* list_start(list* l);
cell* list_end(list* l);
cell* list_next(list* l, cell* p);
cell* list_prev(list* l, cell* p);
void list_remove(list* l, cell *p);
cell* list_find(list* l, void* v);
void list_destroy(list* l);
#endif