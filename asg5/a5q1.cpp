#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertBeg() {
    int val; scanf("%d", &val);
    struct Node* newNode = create(val);
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning!\n");
}

void insertEnd() {
    int val; scanf("%d", &val);
    struct Node* newNode = create(val);
    if(head == NULL) {
        head = newNode; printf("Inserted at end!\n"); return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    printf("Inserted at end!\n");
}

void insertBefore() {
    int search, val; scanf("%d%d", &search, &val);
    if(head == NULL) { printf("List empty!\n"); return; }
    
    struct Node* newNode = create(val);
    if(head->data == search) {
        newNode->next = head; head = newNode;
        printf("Inserted before %d!\n", search); return;
    }
    
    struct Node* prev = NULL, *curr = head;
    while(curr != NULL && curr->data != search) {
        prev = curr; curr = curr->next;
    }
    if(curr == NULL) printf("%d not found!\n");
    else { prev->next = newNode; newNode->next = curr; printf("Inserted before %d!\n", search); }
}

void insertAfter() {
    int search, val; scanf("%d%d", &search, &val);
    struct Node* curr = head;
    while(curr != NULL && curr->data != search) curr = curr->next;
    
    if(curr == NULL) printf("%d not found!\n");
    else {
        struct Node* newNode = create(val);
        newNode->next = curr->next; curr->next = newNode;
        printf("Inserted after %d!\n", search);
    }
}

void deleteBeg() {
    if(head == NULL) { printf("List empty!\n"); return; }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if(head == NULL) { printf("List empty!\n"); return; }
    if(head->next == NULL) {
        printf("Deleted %d\n", head->data); free(head); head = NULL; return;
    }
    struct Node* prev = NULL, *curr = head;
    while(curr->next != NULL) { prev = curr; curr = curr->next; }
    prev->next = NULL; printf("Deleted %d\n", curr->data); free(curr);
}

void deleteSpecific() {
    int val; scanf("%d", &val);
    if(head == NULL) { printf("List empty!\n"); return; }
    if(head->data == val) { deleteBeg(); return; }
    
    struct Node* prev = NULL, *curr = head;
    while(curr != NULL && curr->data != val) { prev = curr; curr = curr->next; }
    if(curr == NULL) printf("%d not found!\n");
    else { prev->next = curr->next; printf("Deleted %d\n", val); free(curr); }
}

void search() {
    int val, pos = 1; scanf("%d", &val);
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp->data == val) { printf("Found at position %d\n", pos); return; }
        temp = temp->next; pos++;
    }
    printf("Not found!\n");
}

void display() {
    if(head == NULL) { printf("List empty!\n"); return; }
    struct Node* temp = head;
    printf("List: ");
    while(temp != NULL) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

int main() {
    int ch;
    while(1) {
        printf("\n=== MENU ===\n1.Insert Beg 2.End 3.Before 4.After\n5.Del Beg 6.End 7.Specific 8.Search 9.Display 0.Exit\nChoice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertBefore(); break;
            case 4: insertAfter(); break;
            case 5: deleteBeg(); break;
            case 6: deleteEnd(); break;
            case 7: deleteSpecific(); break;
            case 8: search(); break;
            case 9: display(); break;
            case 0: exit(0);
            default: printf("Wrong choice!\n");
        }
    }
    return 0;
}
