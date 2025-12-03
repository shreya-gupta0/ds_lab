#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int d) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d; n->next = NULL;
    return n;
}

void add(int d) {
    struct Node* n = create(d);
    if(!head) { head = n; return; }
    struct Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}

void reverse() {
    struct Node *prev = NULL, *curr = head, *next;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void print() {
    struct Node* t = head;
    while(t) {
        printf("%d", t->data);
        if(t->next) printf("->");
        t = t->next;
    }
    printf("\n");
}

int main() {
    add(1); add(2); add(3); add(4);
    printf("Original: "); print();     // 1->2->3->4
    reverse();
    printf("Reversed: "); print();     // 4->3->2->1
}
