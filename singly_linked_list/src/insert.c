#include "linkedlist.h"
#include "node.h"
#include <assert.h>
#include <stdlib.h>

int append_to_int_single_linkedlist(int_single_linkedlist *list, int value) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL)
    return 1;
  new_node->next = NULL;
  new_node->value = value;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
  return 0;
}

int append_to_int_double_linkedlist(int_double_linkedlist *list, int value) {
  DoubleNode *new_node = malloc(sizeof(DoubleNode));
  if (new_node == NULL)
    return 1;
  new_node->next = NULL;
  new_node->prev = list->tail;
  new_node->value = value;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
  return 0;
}

int insert_after_int_double_linkedlist(DoubleNode *node, int value) {
  assert(node != NULL);
  DoubleNode *new_node = malloc(sizeof(DoubleNode));
  if (new_node == NULL)
    return 1;
  new_node->value = value;
  new_node->next = node->next;
  node->next = new_node;
  new_node->prev = node;
  return 0;
}

int insert_after_int_single_linked_list(int_single_linkedlist *list, Node *node,
                                        int value) {
  assert(node != NULL);
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    return 1;
  }
  new_node->value = value;
  new_node->next = node->next;
  node->next = new_node;
  list->size++;
  return 0;
}
