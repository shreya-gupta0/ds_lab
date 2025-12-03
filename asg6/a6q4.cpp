#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node *next, *prev;
};

struct Node* head = NULL;

struct Node* newNode(char c) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = c; return n;
}

void add(char c) {
    struct Node* n = newNode(c);
    if(!head) { head = n; return; }
    struct Node* t = head;
    while(t->next) t = t->next;
    t->next = n; n->prev = t;
}

int palindrome() {
    struct Node *left = head, *right = NULL;
    
    // Find last node
    struct Node* t = head;
    while(t->next) t = t->next;
    right = t;
    
    // Compare from both ends
    while(left && right && left != right->next) {
        if(left->data != right->data) return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}

int main() {
    add('A'); add('B'); add('A');
    printf("%s\n", palindrome() ? "Palindrome" : "Not");
    
    head = NULL;
    add('A'); add('B'); add('C');
    printf("%s\n", palindrome() ? "Palindrome" : "Not");
}
