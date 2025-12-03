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

int middle() {
    struct Node *s = head, *f = head;
    while(f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    return s->data;
}

int main() {
    add(1); add(2); add(3); add(4); add(5);
    printf("Middle: %d\n", middle());  // Output: 3
}
