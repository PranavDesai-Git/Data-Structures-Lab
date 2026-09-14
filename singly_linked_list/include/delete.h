#ifndef DELETE_H
#define DELETE_H

#include "linkedlist.h"
#include "node.h"

void delete_node_int_single_linkedlist(int_single_linkedlist *list,
                                       Node *delete_node, Node *prev_node);
void delete_node_int_double_linkedlist(int_double_linkedlist *list,
                                       DoubleNode *delete_node,
                                       DoubleNode *prev_node);
void delete_at_index_int_double_linkedlist(int_double_linkedlist *list,
                                           int index);
#endif
