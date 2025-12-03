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
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int isCircular() {
    if(head == NULL) return 0;
    
    struct Node* slow = head;
    struct Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        if(slow == fast) return 1;  // Cycle detected = Circular!
        
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;  // No cycle = Not circular
}

int main() {
    // Test 1: Circular list (1->2->3->2)
    insertEnd(1); insertEnd(2); insertEnd(3);
    head->next->next->next = head->next;  // Make circular
    
    printf("Test 1: %s\n", isCircular() ? "Circular" : "Not Circular");
    
    // Test 2: Normal list
    head = NULL;
    insertEnd(10); insertEnd(20); insertEnd(30);
    printf("Test 2: %s\n", isCircular() ? "Circular" : "Not Circular");
    
    return 0;
}
