#include "delete.h"
#include "insert.h"
#include "linkedlist.h"
#include "linkedlistio.h"
#include "retrieve.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  int_double_linkedlist list;
  init_int_double_linkedlist(&list);
  accept_int_double_linked_list(&list);
  int x = 0;
  printf("Enter the value you want to search:");
  scanf("%d", &x);
  int index = get_index_of_first_occurance_int_double_linkedlist(list, x);
  if (index != -1)
    printf("value found at: %d", index);
  else
    printf("element not found");
  /*
  int_double_linkedlist list;
  init_int_double_linkedlist(&list);
  int x = 0;
  printf("enter the value to append:");
  scanf("%d", &x);
  append_to_int_double_linkedlist(&list, x);
  print_int_double_linkedlist(list);
  printf("Enter the index of element you want to delete:");
  scanf("%d", &x);
  delete_at_index_int_double_linkedlist(&list, x);
  print_int_double_linkedlist(list);
  */

  /*
  int_single_linkedlist list;
  init_int_single_linkedlist(&list);
  accept_int_single_linked_list(&list);
  int x = 0, index = 0;
  printf("Enter the element you want to search:");
  scanf("%d", &x);
  index = get_index_of_first_occurance_int_single_linkedlist(list, x);
  printf("Element found at: %d\n", index);
  if (index == -1)
    printf("Element not found\n");

  */
  /*
int_single_linkedlist list;
init_int_single_linkedlist(&list);
append_to_int_single_linkedlist(&list, 10);
append_to_int_single_linkedlist(&list, 20);
append_to_int_single_linkedlist(&list, 30);
Node *found_node = get_first_value_int_single_linkedlist(list, 10);
if (found_node != NULL)
  printf("node found %d\n", found_node->value);
else
  printf("not found");
  */

  /*
  int_single_linkedlist list;
  init_int_single_linkedlist(&list);
  int x = 0;
  accept_int_single_linked_list(&list);
  print_int_single_linkedlist(list);
  printf("enter the index of the node you want to delete:");
  scanf("%d", &x);
  Node *delete_node = get_by_index_int_single_linkedlist(list, x);
  Node *prev_node = get_by_index_int_single_linkedlist(list, x - 1);
  delete_node_int_single_linkedlist(&list, delete_node, prev_node);
  print_int_single_linkedlist(list);
  */

  /*
  int_single_linkedlist list;
  init_int_single_linkedlist(&list);
  accept_int_single_linked_list(&list);
  print_int_single_linkedlist(list);
  */

  /*
 int_single_linkedlist list;
 int_double_linkedlist double_list;
 init_int_single_linkedlist(&list);
 init_int_double_linkedlist(&double_list);

 accept_int_double_linked_list(&double_list);
 print_int_double_linkedlist(double_list);

 accept_int_single_linked_list(&list);

 print_int_single_linkedlist(list);

 Node *needed = get_first_value_int_single_linkedlist(list, 2);
 if (needed != NULL) {
   insert_after_int_single_linked_list(&list, needed, 5);
 }
 print_int_single_linkedlist(list);

 Node *delete_node = get_by_index_int_single_linkedlist(list, 2);
 Node *prev_node = get_by_index_int_single_linkedlist(list, 1);
 delete_node_int_single_linkedlist(&list, delete_node, prev_node);
 print_int_single_linkedlist(list);

 return 0;
 */
}
