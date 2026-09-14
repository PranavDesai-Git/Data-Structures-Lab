#ifndef INSERT_INT_LINKED_LIST_H
#define INSERT_INT_LINKED_LIST_H

#include "linkedlist.h"

int append_to_int_single_linkedlist(int_single_linkedlist *list, int value);

int append_to_int_double_linkedlist(int_double_linkedlist *list, int value);

int insert_after_int_single_linked_list(int_single_linkedlist *list, Node *node,
                                        int value);

#endif
