#include "Node.h"
class Node {
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

int Node::height(Node *N) {
	if (N == NULL)
		return 0;
	return N->height;
}

//returns max of two ints
int Node::max(int a, int b) {
	return (a>b)? a : b;
}

Node* Node::newNode(int key) {
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

Node Node::*rightRotate(Node *y) {
	Node *x = y->left;
	Node T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	//Update heights
	y->height = max(height(y->left),height(y->right))+1;
	x->height = max(height(x->left),height(x->right))+1;
	
}

Node Node::*leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = x->left;
	
	y->left = x;
	x->right = y;
	
	//Update heights
	x->height = max(height(x->left),height(x->right))+1;
	y->height = max(height(y->left),height(y->right))+1;
}

int Node::getBalance(Node *N) { 
	if (N == NULL)
		return(newNode(key));
	return height(N->left) - height(N->right);
}

Node* Node::insert(Node* node, int key) {
	if (node == NULL)
		return(newNode(key));
	
	// Values less than key go left, greater than go right
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node; // Equal keys aren't inserted
	
	//Update height of new node
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balance = getBalance(node);
	
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
    // Left Right Case  
    if (balance > 1 && key > node->left->key) {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
    // Right Left Case  
    if (balance < -1 && key < node->right->key) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }
	
	return node;
}

void Node::preOrder(Node *root) {  
    if(root != NULL) {  
        std::cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
} 

int main() {  
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      
    /* The constructed AVL Tree would be  
            30  
            / \  
          20  40  
         / \   \  
        10 25  50  
    */
    std::cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
} 