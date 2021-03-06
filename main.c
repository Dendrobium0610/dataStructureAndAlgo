#include "linkedList.h"
#include <stdio.h>


int main(int argc, char *argv[]){
    
    int arr[5] = {1,2,3,4,5};

    list_t *list = newList(arr, 5);
    list->Show(list);
    printf("list length: %d\n", list->GetLen(list));

    list->Append(list, 22);
    list->Show(list);
    printf("list length: %d\n", list->GetLen(list));

    list->Remove(list, 1);
    list->Show(list);
    printf("list length: %d\n", list->GetLen(list));

    list->Insert(list, 1, 10);
    list->Show(list);
    printf("list length: %d\n", list->GetLen(list));

    deleteList(list);
    list = NULL;
    return 0;
}
