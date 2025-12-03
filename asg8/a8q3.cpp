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

// (a) Insert (no duplicates)
struct Node* insert(struct Node* root, int val) {
    if(!root) return newNode(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    // Skip duplicates
    return root;
}

// (b) Delete - Fixed version
struct Node* minValueNode(struct Node* node) {
    while(node && node->left) node = node->left;
    return node;
}

struct Node* deleteNode(struct Node* root, int val) {
    if(!root) return root;
    
    if(val < root->data)
        root->left = deleteNode(root->left, val);
    else if(val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // Node with only one child or no child
        if(!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children - get inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// (c) Maximum depth
int maxDepth(struct Node* root) {
    if(!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

// (d) Minimum depth - Fixed!
int minDepth(struct Node* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    
    if(root->left == NULL) return 1 + r;
    if(root->right == NULL) return 1 + l;
    
    return 1 + (l < r ? l : r);
}

void inorder(struct Node* root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    
    root = insert(root, 50);
    insert(root, 30); insert(root, 70);
    insert(root, 20); insert(root, 40);
    insert(root, 60); insert(root, 80);
    
    printf("BST: "); inorder(root); printf("\n");
    printf("Max Depth: %d\n", maxDepth(root));
    printf("Min Depth: %d\n", minDepth(root));
    
    printf("\nAfter deleting 30: ");
    root = deleteNode(root, 30);
    inorder(root); printf("\n");
    
    return 0;
}
