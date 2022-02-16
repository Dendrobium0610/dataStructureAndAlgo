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
    Obj->Insert = &insertNode;

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


static void removeNode(list_t *Obj, uint32_t position){
    //remove the element at position from list
    uint32_t cnt=1;
    node_t **indirect = &Obj->head, **prev, *target;
    while(cnt != position){
        prev = indirect;
        indirect = &(*indirect)->next;
        cnt++;
    }

    target = *indirect;   
    *indirect = target->next;
    (*indirect)->prev = *prev;
    target->next = NULL;
    free(target);
    Obj->len--;
}


void deleteList(list_t *Obj){
    node_t *curr = Obj->head, *target;

    while(curr){
        target = curr;
        target->next = target->prev = NULL;
        free(target);
        curr = curr->next;
    }
    free(Obj);
}


static uint32_t getLen(list_t *Obj){
    return Obj->len;
}


static void insertNode(list_t *Obj, uint32_t position, int32_t val){
    node_t **indirect = &Obj->head, **origin, **prev;

    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->val = val;
    newNode->next = newNode->prev = NULL;

    uint32_t cnt = 1;

    while(cnt != position){
        prev = indirect;
        indirect = &(*indirect)->next;
        cnt++;
    }
    origin = indirect;
    *indirect = newNode;
    (*indirect)->prev = *prev;
    (*indirect)->next = *origin;
    (*origin)->prev = *indirect;
}

