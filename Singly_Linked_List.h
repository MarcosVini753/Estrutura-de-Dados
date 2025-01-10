// Code by: Marcos Vinícius Moraes
// Date: 01/10/2025 
#ifndef Singly_Linked_List_h
#define Singly_Linked_List_h

#include <stdio.h>
#include <stdlib.h>

typedef struct SLL_node{
    int value;
    struct SLL_node *next;
} Node;

typedef struct Singly_Linked_List{
    Node *head;
    int size;
} SLL;

SLL new_SLL();
void SLL_insert(SLL *list, int value);
void SLL_print(SLL *list);
void SLL_free(SLL *list);
Node *SLL_last_node(SLL *list);
Node *find_node(SLL *list, int value);
void SLL_remove_node(SLL *list, Node *node);
#endif

#ifndef Singly_Linked_List_implementation
#define Singly_Linked_List_implementation

SLL new_SLL(){
    SLL tmp;
    tmp.head = NULL;
    tmp.size = 0;
    return tmp;
}
void SLL_insert(SLL *list, int value){
    Node *tmp = (Node *) malloc(sizeof(Node));
    if(!tmp) fprintf(stderr, "Erro: não foi possível alocar memória"), exit(1);
    tmp->value = value; tmp->next = NULL;
    if(list->head) tmp->next = list->head; 
    list->head = tmp;
    list->size++;
}
void SLL_print(SLL *list){
    Node *tmp = list->head;
    while (tmp) printf("%d ", tmp->value), tmp = tmp->next;
    printf("\n");
}
void SLL_free(SLL *list){
    Node *ant = NULL, *tmp = list->head;
    while (tmp) ant = tmp, tmp = tmp->next, free(ant);
    list->head = NULL;
    list->size = 0;
}
Node *SLL_last_node(SLL *list){
    Node *tmp = list->head;
    if(!tmp) return tmp;
    while (tmp->next) tmp = tmp->next;
    return tmp; 
}
Node *find_node(SLL *list, int value){
    Node *tmp = list->head;
    while(tmp && tmp->value != value) tmp = tmp->next;
    return tmp;
}
void SLL_remove_node(SLL *list, Node *node){
    Node *aux = list->head;
    if(!node || !aux) return;
    if(node == aux) list->head = aux->next, free(aux);
    else{
        while(aux->next != node) aux = aux->next;
        aux->next = node->next; free(node);
    }
    list->size--;

}

#endif