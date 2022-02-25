#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
    if (head_item == 0) {
        return 0;
    }
    struct ListItem* current_item = head_item;
    int count = 0;
    for (; current_item != 0; count++) {
        current_item = current_item->next;
    }
    return count;
}

int get_item_data(struct ListItem* head_item, int index, int* error) {  // Get item data by index
    *error = 0;
    if (index < 0 || index >= get_length(head_item)) {
        *error = 1;
        return 0;
    }

    struct ListItem* current_item = head_item;
    for (int i = 0; i != index; i++) {
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

int is_index_in_range(struct ListItem* head_item, int index, int* error) {
    if (index < 0 || index >= get_length(head_item)) {
        *error = 1;
        return 0;
    }
    *error = 0;
    return 1;

}

void insert_item(struct ListItem** head_item, int index, int data, int* error) {
    if (! is_index_in_range(*head_item, index, error)) {
        return;
    }

    if (index == 0) {
        struct ListItem* next_item = *head_item;
        *head_item = malloc(sizeof(struct ListItem));
        (*head_item)->next = next_item;  // Don't work without the brackets
        (*head_item)->data = data;
        return;
    }

    struct ListItem* current_item = *head_item;
    int i = 0;
    for (; i != index - 1; i++) {
        current_item = current_item->next;
    }
    struct ListItem* next_item = current_item->next;
    current_item->next = malloc(sizeof(struct ListItem));
    current_item->next->data = data;
    current_item->next->next = next_item;
}

void remove_element(struct ListItem** head_item, int index, int* error) {
    if (! is_index_in_range(*head_item, index, error)) {
        return;
    }

    if (index == 0) {
        *head_item = (*head_item)->next;
    }

    struct ListItem* current_item = *head_item;
    int i = 0;
    for (; i < index - 1; i++) {
        current_item = current_item->next;
    }
    current_item->next = current_item->next->next;
}