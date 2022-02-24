#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    setbuf(stdout, NULL);

    struct ListItem* head_item = 0;

    for (int i = 0; i < 10; i++) {
        append_new_item(&head_item, i);
    }


    print_list(head_item);

    print_separator();
    
    int count = get_length(head_item);
    printf("Count of elements in ListItem: %d\n", count);  // Вывод кол-ва элементов в списке

    print_separator();
    
    printf("Specify the index of an element to get its value:\n");
    int customer_index;
    scanf("%d", &customer_index);
    int data_by_index = get_item_data(head_item, customer_index);
    printf("%d\n", data_by_index);

    printf("\n");

    return 0;
}