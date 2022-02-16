#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdint.h>

typedef struct node node_t;
typedef struct list list_t;

typedef void (*fptrAppend)(list_t *Obj, int32_t val);
typedef void (*fptrRemove)(list_t *Obj, uint32_t number);
typedef void (*fptrShow)(list_t *Obj);
typedef uint32_t (*fptrGetLen)(list_t *Obj);

list_t* newList(int32_t *arr, uint32_t arrLen);
void deleteList(list_t *list);

static void showList(list_t *Obj);
static void appendNode(list_t *Obj, int32_t val);
static void removeNode(list_t *Obj, uint32_t number);
static uint32_t getLen(list_t *Obj);



struct node{
    int32_t     val;
    struct node *next;
    struct node *prev;
};


struct list{
    node_t     *head;
    uint32_t   len;

    fptrAppend Append;
    fptrRemove Remove;
    fptrShow   Show;
    fptrGetLen GetLen;
};
#endif
