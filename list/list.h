#pragma once

struct ListItem
{
    int data;
    struct ListItem* next;
};

void append_new_item(struct ListItem** head_item, int data);
int get_length(struct ListItem* head_item);
int get_item_data(struct ListItem* head_item, int index, int* error);
void list_iterate(struct ListItem* head_item, void (*callback) (struct ListItem*));
void print_ListItem(struct ListItem* item);
void print_list(struct ListItem* head_item);
int is_index_in_range(struct ListItem* head_item, int index, int* error);
void insert_item(struct ListItem** head_item, int index, int data, int* error);
void remove_element(struct ListItem** head_item, int index, int* error);