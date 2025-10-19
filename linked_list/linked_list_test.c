#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void kill_func(void* v){
    free(v);
}

int compare_func(void* s0, void* s1){
    return strcmp((char*)s0, (char*)s1) == 0;
}

void print_func(list* l){
    cell* current = list_start(l);
    do{
        printf("%s\n", (char*)list_inspect(current));
    }while((current = list_next(l, current)) != NULL);
}

int main(void){
    
    list* l = list_create(&kill_func, &compare_func);
    printf("list is empty %d\n", list_is_empty(l));
    
    char* data = malloc(100*sizeof(char));
    strcpy(data,"hej 0");
    list_insert(l, (void*)data, sizeof(data));
    strcpy(data,"hej 1");
    list_insert(l, (void*)data, sizeof(data));
    strcpy(data,"hej 2");
    list_insert(l, (void*)data, sizeof(data));
    strcpy(data,"hej 3");
    list_insert(l, (void*)data, sizeof(data));

    printf("list is empty %d\n", list_is_empty(l));
    
    strcpy(data,"hej 0");
    cell* e = list_find(l, data);
    printf("\n%s",(char*)(e->val));

    printf("\n");
    print_func(l);
    printf("\n");

    strcpy(data,"hej 0");

    print_func(l);

    list_destroy(l);
    free(data);

    return 0;
}
