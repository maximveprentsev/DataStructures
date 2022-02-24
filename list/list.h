#pragma once

struct ListItem
{
    int data;
    struct ListItem* next;
};

void print_separator();
void append_new_item(struct ListItem** head_item, int data);
int get_length(struct ListItem* head_item);
int get_item_data(struct ListItem* head_item, int index);
void list_iterate(struct ListItem* head_item, void (*callback) (struct ListItem*));
void print_ListItem(struct ListItem* item);
void print_list(struct ListItem* head_item);