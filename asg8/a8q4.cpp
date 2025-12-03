#include<stdio.h>
#include<stdlib.h>
#include<limits.h>  // ✅ FIXED: For INT_MIN, INT_MAX

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

int isBST(struct Node* root, int min, int max) {
    if(!root) return 1;
    
    if(root->data <= min || root->data >= max) return 0;
    
    return isBST(root->left, min, root->data) && 
           isBST(root->right, root->data, INT_MAX);
}

int isBSTWrapper(struct Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* bst = newNode(50);
    bst->left = newNode(30); bst->right = newNode(70);
    bst->left->left = newNode(20); bst->left->right = newNode(40);
    
    printf("BST: %s\n", isBSTWrapper(bst) ? "YES" : "NO");
    
    struct Node* not_bst = newNode(50);
    not_bst->left = newNode(30);
    not_bst->left->right = newNode(60);  // 60 > 50! Violation!
    
    printf("Not BST: %s\n", isBSTWrapper(not_bst) ? "YES" : "NO");
    
    return 0;
}
