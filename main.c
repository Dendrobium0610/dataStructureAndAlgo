#include "linkedList.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    
    int32_t arr[] = {1,2,3,4,5};
    list_t *list = newList(arr);
    list->Show(list);

    printf("%d\n", list->GetLen(list));

    // printf("%ld", sizeof(arr)/sizeof(arr[0]));
    // for(int idx = 1; idx < sizeof(arr)/sizeof(arr[0]); idx++){
    //     printf("%d\n", idx);
    // }
    return 0;
}
