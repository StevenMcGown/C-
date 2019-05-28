#ifndef NODE_HEADER
#define NODE_HEADER

int height(Node *N);
int max(int a, int b);
Node* newNode(int key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node* insert(Node* node, int key);
void preOrder(Node *root);

#endif
