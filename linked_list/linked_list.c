#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

list* list_create(kill_function kill_func, compare_function compare_func){
    list* l = malloc(sizeof(list));
    cell* head = malloc(sizeof(cell));
    cell* tail = malloc(sizeof(cell));

    l->head = head;
    l->tail = tail;
    l->head->next = tail;
    l->tail->prev = head;
    l->kill_func = kill_func;
    l->compare_func = compare_func;
    return l;
}

int list_is_empty(list* l){
    return (l->head->next == l->tail);
}

void list_insert(list* l, void* v){
    cell *prev;
    cell *e = malloc(sizeof(cell));
    
    prev = l->tail->prev;
    e->val = v;
    e->prev = prev;
    e->next = l->tail;
    l->tail->prev = e;
    prev->next = e;
}

void *list_inspect(cell* p){
    return p->val;
}

cell* list_start(list* l){
    return l->head->next;
}

cell* list_end(list* l){
    return l->tail->prev;
}

cell* list_next(list* l, cell* p){
    if(l->tail == p->next){
        return NULL;
    }
    return p->next;
}

cell* list_prev(list* l, cell* p){
    if(l->head == p->prev){
        return NULL;
    }
    return p->prev;
}

void list_remove(list* l, cell *p){
    cell *ahead, *before;
    ahead = p->next;
    before = p->prev;

    ahead->prev = before;
    before->next = ahead;
    
    p->next = NULL;
    p->prev = NULL;

    free(p);
}

cell* list_find(list* l, void* v){
    cell* current = list_start(l);
    do{
        if(l->compare_func(current->val, v)){
            return current;
        }
    }while((current = list_next(l, current)) != NULL); 

    return NULL;
}

void list_destroy(list* l){
    cell* current = list_start(l)->next;
    do{
        l->kill_func(current->prev->val);
        free(current->prev);
        current = current->next;
    }while(current != l->tail);
    l->kill_func(current->prev->val);
    free(current->prev);

    free(l->head);
    free(l->tail);
    free(l);
}
