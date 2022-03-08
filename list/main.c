#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    setbuf(stdout, NULL);

    struct ListItem* head_item = 0;  // Create some list with 10 elements
    for (int i = 0; i < 10; i++) {
        append_new_item(&head_item, i);
    }
    print_list(head_item);
    
    int count = get_length(head_item);  // Print lenght of the list
    printf("Count of elements in ListItem: %d\n", count);
    
    printf("Specify the index of an element to get its value: ");  // Get item by user's index
    int customer_index;
    scanf("%d", &customer_index);
    int error;
    int data_by_index = get_item_data(head_item, customer_index, &error);
    while (error) {  // Поиграл с циклом
        printf("Error: Index [%d] out of range. Please, try again: ", customer_index);
        scanf("%d", &customer_index);
        data_by_index = get_item_data(head_item, customer_index, &error);
    }
    printf("%d\n", data_by_index);

    printf("Input desired index and data for new element: ");  // Input new element by user's index
    int data;
    scanf("%d %d", &customer_index, &data);
    insert_item(&head_item, customer_index, data, &error);
    if (error == 1) {
        printf("Error: Index [%d] out of range\n", customer_index);
    }
    else {
        print_list(head_item);
    }

    printf("Input index to remove element: ");  //Remove element by index
    scanf("%d", &customer_index);
    remove_element(&head_item, customer_index, &error);
    if (error == 1) {
        printf("Error: Index [%d] out of range\n", customer_index);
    }
    else {
        print_list(head_item);
    }

    printf("FILTERED LIST: ");

    struct ListItem* filtered_list = list_filter(head_item, is_even);
    print_list(filtered_list);

    return 0;
}