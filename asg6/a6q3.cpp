#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *dll_head = NULL, *cll_head = NULL;  

struct Node* create(int d) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d; return n;
}


void dll_add(int d) {
    struct Node* n = create(d);
    if(!dll_head) { dll_head = n; return; }
    struct Node* t = dll_head;
    while(t->next) t = t->next;
    t->next = n; n->prev = t;
}

int dll_size() {
    int cnt = 0;
    struct Node* t = dll_head;
    while(t) { cnt++; t = t->next; }
    return cnt;
}


void cll_add(int d) {
    struct Node* n = create(d);
    if(!cll_head) { cll_head = n; n->next = n; return; }
    n->next = cll_head;
    struct Node* t = cll_head;
    while(t->next != cll_head) t = t->next;
    t->next = n; cll_head->prev = n; n->prev = t;
}

int cll_size() {
    if(!cll_head) return 0;
    int cnt = 1;
    struct Node* t = cll_head->next;
    while(t != cll_head) { cnt++; t = t->next; }
    return cnt;
}

int main() {

    dll_add(10); dll_add(20); dll_add(30);
    printf("Doubly Linked List Size: %d\n", dll_size());  // 3
    
    
    cll_add(40); cll_add(50); cll_add(60);
    printf("Circular Linked List Size: %d\n", cll_size());  // 3
    
    return 0;
}
