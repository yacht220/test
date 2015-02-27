#ifndef UTILITY_H
#define UTILITY_H

#define ARRAY_SIZE 10

struct Node
{
  Node *left;
  Node *right;
  int num;
};
typedef Node* PNode;

void insertBST(PNode* root, int value);

void createBST(PNode *t);

#endif
