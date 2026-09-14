#include "insert.h"
#include "linkedlist.h"
#include "node.h"
#include <stdio.h>

void print_int_single_linkedlist(int_single_linkedlist list) {
  Node *current = list.head;
  while (current != NULL) {
    printf("(%d)->", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

void print_int_double_linkedlist(int_double_linkedlist list) {
  DoubleNode *current = list.head;
  while (current != NULL) {
    printf("(%d) <--> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

void accept_int_single_linked_list(int_single_linkedlist *list) {
  int value, size;
  printf("Enter the size of linkedlist you want to create:");
  scanf("%d", &size);
  for (int i = 0; i < size; ++i) {
    printf("Enter the Node[%d] value:", i);
    scanf("%d", &value);
    append_to_int_single_linkedlist(list, value);
  }
  list->size = size;
}

void accept_int_double_linked_list(int_double_linkedlist *list) {
  int value, size;
  printf("Enter the size of linkedlist you want to create:");
  scanf("%d", &size);
  for (int i = 0; i < size; ++i) {
    printf("Enter the Node[%d] value:", i);
    scanf("%d", &value);
    append_to_int_double_linkedlist(list, value);
  }
  list->size = size;
}
