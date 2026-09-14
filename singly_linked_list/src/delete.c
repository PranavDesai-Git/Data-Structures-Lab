#include "linkedlist.h"
#include "node.h"
#include <stdlib.h>

void delete_node_int_single_linkedlist(int_single_linkedlist *list,
                                       Node *delete_node, Node *prev_node) {
  prev_node->next = delete_node->next;
  free(delete_node);
  (list->size)--;
}

void delete_node_int_double_linkedlist(int_double_linkedlist *list,
                                       DoubleNode *delete_node,
                                       DoubleNode *prev_node) {
  prev_node->next = delete_node->next;
  prev_node->next->prev = prev_node;
  free(delete_node);
  (list->size)--;
}

void delete_at_index_int_double_linkedlist(int_double_linkedlist *list,
                                           int index) {
  if (list == NULL || index < 0 || index >= list->size) {
    return;
  }
  DoubleNode *current = list->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  if (current->prev != NULL) {
    current->prev->next = current->next;
  } else {
    list->head = current->next;
  }
  if (current->next != NULL) {
    current->next->prev = current->prev;
  } else {
    list->tail = current->prev;
  }
  free(current);
  (list->size)--;
}
