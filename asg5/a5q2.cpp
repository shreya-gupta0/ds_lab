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

int countDelete(int k) {
    int c = 0;
    struct Node *p = NULL, *cur = head;
    
    // Count
    for(struct Node* t = head; t; t = t->next)
        if(t->data == k) c++;
    
    printf("Count: %d\n", c);
    
    // Delete all
    while(cur) {
        if(cur->data == k) {
            if(!p) head = cur->next;
            else p->next = cur->next;
            struct Node* temp = cur;
            cur = cur->next;
            free(temp);
        } else {
            p = cur;
            cur = cur->next;
        }
    }
    return c;
}

void show() {
    for(struct Node* t = head; t; t = t->next) {
        printf("%d", t->data);
        if(t->next) printf("->");
    }
    printf("\n");
}

int main() {
    add(1); add(2); add(1); add(2); add(1); add(3); add(1);
    printf("Original: 1->2->1->2->1->3->1\n");
    
    int key; scanf("%d", &key);
    countDelete(key);
    printf("Updated: "); show();
}
