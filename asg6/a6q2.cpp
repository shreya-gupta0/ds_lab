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

void insertEnd(int val) {
    struct Node* newNode = create(val);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;  // Circular
        return;
    }
    struct Node* temp = head;
    while(temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void displayCircular() {
    if(head == NULL) {
        printf("List empty!\n");
        return;
    }
    
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");  // Head repeats at end automatically!
}

int main() {
    // Input: 20 → 100 → 40 → 80 → 60
    insertEnd(20); insertEnd(100); insertEnd(40);
    insertEnd(80); insertEnd(60);
    
    printf("Output: ");
    displayCircular();  // 20 100 40 80 60 20
    
    return 0;
}
