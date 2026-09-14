#include "node.h"
#include <stdlib.h>

typedef struct {
  Node *head;
  Node *tail;
  int size;
} int_single_linkedlist;

typedef struct {
  DoubleNode *head;
  DoubleNode *tail;
  int size;
} int_double_linkedlist;

void init_int_single_linkedlist(int_single_linkedlist *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void init_int_double_linkedlist(int_double_linkedlist *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}
