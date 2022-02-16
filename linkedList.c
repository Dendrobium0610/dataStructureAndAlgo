#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_


#include "linkedList.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


list_t* newList(int32_t *arr, uint32_t arrLen){
    if (!arr) return NULL;
    node_t *head = (node_t*)malloc(sizeof(node_t));
    if(!head)  return NULL;
    
    node_t *curr = head;
    head->prev = head->next = NULL;
    head->val = arr[0];

    list_t *Obj = (list_t*)malloc(sizeof(list_t));
    if(!Obj) return NULL;
    
    Obj->head = head;
    Obj->len = 1;
    Obj->Append = &appendNode;
    Obj->Remove = &removeNode;
    Obj->Show = &showList;
    Obj->GetLen = &getLen;

    for(int idx = 1; idx < arrLen; idx++){
        node_t *newNode = (node_t*)malloc(sizeof(node_t));
        if(!newNode) {
            fprintf(stderr, "memory allocation failed.");
        }        
        Obj->len++;
        newNode->val = arr[idx];
        newNode->next = NULL;
        newNode->prev = curr;
        curr->next = newNode;
        curr = curr->next;
    }
    

    return Obj;
}


static void showList(list_t *Obj){
    node_t *curr = Obj->head;
    printf("[");
    while(curr){
        printf("%d, ", curr->val);
        curr = curr->next;
    }
    printf("]\n");
}


static void appendNode(list_t *Obj, int32_t val){
    node_t *indirect = Obj->head;
        
    while(indirect->next){
       indirect = indirect->next; 
    }

    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->prev = newNode->next = NULL;
    newNode->val = val;
    indirect->next = newNode;
    Obj->len++;
}


static void removeNode(list_t *Obj, uint32_t number){
    uint32_t cnt=1;
    node_t **indirect = &Obj->head;
    while(cnt < number-1){
        indirect = &(*indirect)->next;
        cnt++;
    }
    node_t *target = (*indirect)->next;
    (*indirect)->next = target->next;
    (*indirect)->next->prev = (*indirect);    
    target->next = NULL;
    free(target);
    Obj->len--;
}


void deleteList(list_t *Obj){
    node_t *curr = Obj->head, *tmp;

    while(curr){
        tmp = curr;
        tmp->next = tmp->prev = NULL;
        curr = curr->next;
    }
    free(Obj);
}


static uint32_t getLen(list_t *Obj){
    return Obj->len;
}


#endif
