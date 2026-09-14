#include "linkedlist.h"
#include "node.h"
#include <stdlib.h>

Node *get_first_value_int_single_linkedlist(int_single_linkedlist list,
                                            int value) {
  Node *check_node = list.head;
  while (check_node != NULL) {
    if (check_node->value == value)
      break;
    check_node = check_node->next;
  }
  return check_node;
}

Node *get_by_index_int_single_linkedlist(int_single_linkedlist list,
                                         int index) {
  Node *ret_node = list.head;
  for (int i = 0; i < index; ++i) {
    ret_node = ret_node->next;
  }
  return ret_node;
}

DoubleNode *get_by_index_int_double_linkedlist(int_double_linkedlist list,
                                               int index) {
  DoubleNode *ret_node = list.head;
  for (int i = 0; i < index; ++i) {
    ret_node = ret_node->next;
  }
  return ret_node;
}

int get_index_of_first_occurance_int_single_linkedlist(
    int_single_linkedlist list, int value) {
  Node *current = list.head;
  int index = 0;

  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    current = current->next;
    index++;
  }

  return -1;
}

int get_index_of_first_occurance_int_double_linkedlist(
    int_double_linkedlist list, int value) {
  DoubleNode *current = list.head;
  int index = 0;
  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1;
}
