#ifndef RETRIEVE_LINKEDLIST_H
#define RETRIEVE_LINKEDLIST_H

#include "linkedlist.h"
#include "node.h"

Node *get_first_value_int_single_linkedlist(int_single_linkedlist list,
                                            int value);
Node *get_by_index_int_single_linkedlist(int_single_linkedlist list, int index);
int get_index_of_first_occurance_int_single_linkedlist(
    int_single_linkedlist list, int value);
DoubleNode *get_by_index_int_double_linkedlist(int_double_linkedlist list,
                                               int index);
int get_index_of_first_occurance_int_double_linkedlist(
    int_double_linkedlist list, int value);

#endif
