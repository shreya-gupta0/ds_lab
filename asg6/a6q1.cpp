#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *ch = NULL, *dh = NULL;  // Circular head, Doubly head

struct Node* newNode(int d) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d; return n;
}

// ===== CIRCULAR SIMPLE =====
void cins(int p, int v) {
    struct Node* nn = newNode(v);
    if(!ch) { ch = nn; nn->next = nn->prev = nn; return; }
    
    struct Node* t = ch;
    if(p == 0) {  // First
        while(t->prev != ch) t = t->prev;
        nn->next = ch; nn->prev = t; t->next = ch->prev = nn; ch = nn;
    } else if(p == 1) {  // Last
        while(t->next != ch) t = t->next;
        t->next = nn; nn->prev = t; nn->next = ch; ch->prev = nn;
    } else {  // After value
        do { if(t->data == p) { nn->next = t->next; nn->prev = t; t->next->prev = nn; t->next = nn; return; } t = t->next; } while(t != ch);
    }
    printf("Inserted!\n");
}

void cdel(int v) {
    if(!ch) return;
    struct Node* t = ch;
    do {
        if(t->data == v) {
            if(t->next == t) { free(ch); ch = NULL; return; }
            t->prev->next = t->next; t->next->prev = t->prev;
            if(t == ch) ch = t->next;
            free(t); printf("Deleted %d\n", v); return;
        }
        t = t->next;
    } while(t != ch);
}

void cshow() {
    if(!ch) { printf("Empty\n"); return; }
    struct Node* t = ch;
    do { printf("%d ", t->data); t = t->next; } while(t != ch); printf("\n");
}

// ===== DOUBLY SIMPLE =====
void dins(int p, int v) {
    struct Node* nn = newNode(v);
    if(!dh) { dh = nn; return; }
    
    if(p == 0) { nn->next = dh; dh->prev = nn; dh = nn; }
    else if(p == 1) {
        struct Node* t = dh; while(t->next) t = t->next;
        t->next = nn; nn->prev = t;
    } else {
        struct Node* t = dh;
        while(t && t->data != p) t = t->next;
        if(!t) return;
        nn->next = t->next; nn->prev = t;
        if(t->next) t->next->prev = nn; t->next = nn;
    }
    printf("Inserted!\n");
}

void ddel(int v) {
    if(!dh) return;
    struct Node* t = dh;
    while(t && t->data != v) t = t->next;
    if(!t) return;
    
    if(!t->prev) dh = t->next;
    else t->prev->next = t->next;
    if(t->next) t->next->prev = t->prev;
    free(t); printf("Deleted %d\n", v);
}

void dshow() {
    if(!dh) { printf("Empty\n"); return; }
    struct Node* t = dh;
    while(t) { printf("%d ", t->data); t = t->next; } printf("\n");
}

int main() {
    int t, op, p, v;
    while(1) {
        printf("1.Circ 2.Doubly 0.Exit: "); scanf("%d", &t);
        if(!t) break;
        
        if(t == 1) {
            printf("1.Ins 2.Del 3.Show: "); scanf("%d", &op);
            if(op == 1) { printf("0=first,1=last,val=after: "); scanf("%d%d", &p, &v); cins(p, v); }
            else if(op == 2) { scanf("%d", &v); cdel(v); }
            else cshow();
        } else {
            printf("1.Ins 2.Del 3.Show: "); scanf("%d", &op);
            if(op == 1) { printf("0=first,1=last,val=after: "); scanf("%d%d", &p, &v); dins(p, v); }
            else if(op == 2) { scanf("%d", &v); ddel(v); }
            else dshow();
        }
    }
}
