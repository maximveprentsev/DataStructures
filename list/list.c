#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_separator() {
    printf("\n\n~~~~~~~~~~~~~~~\n\n");
}

void append_new_item(struct ListItem** head_item, int data) {  // Add new item
    if (*head_item == 0) {
        *head_item = malloc(sizeof(struct ListItem));
        (*head_item)->next = 0;
        (*head_item)->data = data;
        return;
    }

    struct ListItem* current_item = *head_item;
    while (current_item->next != 0) {
        current_item = current_item->next;
    }
    current_item->next = malloc(sizeof(struct ListItem));
    current_item->next->data = data;  
}

int get_length(struct ListItem* head_item) {  // Get length
    struct ListItem* current_item = head_item;
    int count = 0;
    while (current_item != 0) {
        count += 1;
        current_item = current_item->next;
    }

    return count;
}

int get_item_data(struct ListItem* head_item, int index) { // Get item data by index
    struct ListItem* current_item = head_item;
    int i = 0;
    while (i != index) {
        i += 1;
        current_item = current_item->next;
    }

    return current_item->data;
}

void list_iterate(struct ListItem* head_item, void (*callback) (struct ListItem*)) {
    struct ListItem* current_item = head_item;
    while (current_item != 0) {
        (*callback)(current_item);
        current_item = current_item->next;
    }
}

void print_ListItem(struct ListItem* item) {
    printf("%d ", item->data);
}

void print_list(struct ListItem* head_item) {
    list_iterate(head_item, print_ListItem);
    printf("\n");
}