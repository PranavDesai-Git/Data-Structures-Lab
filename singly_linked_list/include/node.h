#ifndef NODE_H
#define NODE_H

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct DoubleNode {
  int value;
  struct DoubleNode *next;
  struct DoubleNode *prev;
} DoubleNode;

#endif
