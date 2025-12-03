#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// (a) Search - RECURSIVE
int searchRec(struct Node* root, int key) {
    if(!root) return 0;
    if(root->data == key) return 1;
    return (key < root->data) ? searchRec(root->left, key) : searchRec(root->right, key);
}

// (a) Search - NON-RECURSIVE
int searchIter(struct Node* root, int key) {
    struct Node* curr = root;
    while(curr) {
        if(curr->data == key) return 1;
        curr = (key < curr->data) ? curr->left : curr->right;
    }
    return 0;
}

// (b) Maximum element
int findMax(struct Node* root) {
    while(root && root->right) root = root->right;
    return root ? root->data : -1;
}

// (c) Minimum element
int findMin(struct Node* root) {
    while(root && root->left) root = root->left;
    return root ? root->data : -1;
}

// (d) Inorder Successor
int inorderSuccessor(struct Node* root, int key) {
    struct Node* curr = root;
    int succ = -1;
    
    // Find successor in right subtree
    while(curr && curr->data != key) {
        if(curr->data > key) {
            succ = curr->data;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    
    
    if(curr && curr->right) return findMin(curr->right);
    return succ;
}

// (e) Inorder Predecessor
int inorderPredecessor(struct Node* root, int key) {
    struct Node* curr = root;
    int pred = -1;
    
    
    while(curr && curr->data != key) {
        if(curr->data < key) {
            pred = curr->data;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    
    
    if(curr && curr->left) return findMax(curr->left);
    return pred;
}

int main() {
    
    struct Node* root = newNode(50);
    root->left = newNode(30); root->right = newNode(70);
    root->left->left = newNode(20); root->left->right = newNode(40);
    root->right->left = newNode(60); root->right->right = newNode(80);
    
    printf("Search 40 (Rec): %s\n", searchRec(root, 40) ? "Found" : "Not Found");
    printf("Search 45 (Iter): %s\n", searchIter(root, 45) ? "Found" : "Not Found");
    printf("Max: %d\n", findMax(root));
    printf("Min: %d\n", findMin(root));
    printf("Successor of 30: %d\n", inorderSuccessor(root, 30));
    printf("Predecessor of 60: %d\n", inorderPredecessor(root, 60));
    
    return 0;
}
