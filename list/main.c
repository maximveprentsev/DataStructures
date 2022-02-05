#include <stdio.h>
#include <stdlib.h>


struct ListItem
{
    int data;
    struct ListItem* next;
};

void append_new_item(struct ListItem* head_item, int data) {
    if (head_item == 0) {
        head_item = malloc(sizeof(struct ListItem));
        head_item->next = 0;
        head_item->data = data;
        return;
    }

    struct ListItem* current_item = head_item;
    while (current_item->next != 0) {
        current_item = current_item->next;
    }
    current_item->next = malloc(sizeof(struct ListItem));
    current_item->next->data = data;  
}

int main() {
    setbuf(stdout, NULL);

    struct ListItem* head_item = 0;
    head_item->next = 0;
    head_item->data = 0;

    for (int i = 0; i < 10; i++) {
        append_new_item(head_item, i);
    }

    
    struct ListItem* current_item = head_item;
    while (current_item != 0) {
        int num = current_item->data;
        printf("%d\n", num);
        current_item = current_item->next;
    }
    return 0;
}