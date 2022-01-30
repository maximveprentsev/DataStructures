#include <stdio.h>
#include <stdlib.h>

struct ListItem
{
    int data;
    struct ListItem* next;
};

int main() {
    struct ListItem head_item;

    struct ListItem* prev_item = &head_item;
    for (int i = 0; i < 9; i++) {
        struct ListItem* next_item = malloc(sizeof(struct ListItem));
        prev_item->next = next_item;
        prev_item->data = i;
        prev_item = prev_item->next;
    }
    prev_item->data = 9;

    struct ListItem* current_item = &head_item;
    while (current_item != 0) {
        int num = current_item->data;
        printf("%d\n", num);
        current_item = current_item->next;
    }
    return 0;
}