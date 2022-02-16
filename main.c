#include "linkedList.h"
#include <stdio.h>


int main(int argc, char *argv[]){
    
    int arr[5] = {1,2,3,4,5};

    list_t *list = newList(arr, 5);
    list->Show(list);
    printf("%d\n", list->GetLen(list));

    list->Append(list, 22);
    list->Show(list);
    printf("%d\n", list->GetLen(list));

    list->Remove(list, 1);
    list->Show(list);
    printf("%d\n", list->GetLen(list));

    // printf("%ld", sizeof(arr)/sizeof(arr[0]));
    // for(int idx = 1; idx < sizeof(arr)/sizeof(arr[0]); idx++){
    //     printf("%d\n", idx);
    // }
    return 0;
}
