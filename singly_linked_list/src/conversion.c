#include "linkedlist.h"
#include "node.h"
#include <stdlib.h>

void single_to_circular(int_single_linkedlist *list) {
  list->tail->next = list->head;
}

int_double_linkedlist single_to_double(int_single_linkedlist list) {
  int_double_linkedlist ret_list;
  init_int_double_linkedlist(&ret_list);
  
  if (list.size == 0 || list.head == NULL) {
    return ret_list; 
  }

  ret_list.size = list.size;
  
  DoubleNode *head_node = malloc(sizeof(DoubleNode));
  if (head_node == NULL) {
    ret_list.size = 0;
    return ret_list;
  }
  
  head_node->value = list.head->value;
  head_node->prev = NULL;
  head_node->next = NULL;
  ret_list.head = head_node;

  Node *sll_track = list.head->next;
  DoubleNode *prev_node = ret_list.head;
  
  for (int i = 1; i < list.size && sll_track != NULL; ++i) {
    DoubleNode *new_node = malloc(sizeof(DoubleNode));
    if (new_node == NULL) {
      break; 
    }
    
    new_node->value = sll_track->value;
    new_node->next = NULL;
    new_node->prev = prev_node;
    
    prev_node->next = new_node;
    prev_node = new_node;
    
    sll_track = sll_track->next;
  }
  return ret_list;
}
