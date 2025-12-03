#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct PriorityQueue {
    int heap[MAX];
    int size;
};

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void heapify(struct PriorityQueue* pq, int i) {
    int parent = (i - 1) / 2;
    if(parent >= 0 && pq->heap[parent] < pq->heap[i]) {
        swap(&pq->heap[parent], &pq->heap[i]);
        heapify(pq, parent);
    }
}

void buildHeap(struct PriorityQueue* pq) {
    for(int i = pq->size / 2 - 1; i >= 0; i--) {
        int child1 = 2 * i + 1, child2 = 2 * i + 2;
        int largest = i;
        if(child1 < pq->size && pq->heap[child1] > pq->heap[largest]) largest = child1;
        if(child2 < pq->size && pq->heap[child2] > pq->heap[largest]) largest = child2;
        
        if(largest != i) {
            swap(&pq->heap[i], &pq->heap[largest]);
            buildHeap(pq);
        }
    }
}

void insert(struct PriorityQueue* pq, int val) {
    if(pq->size >= MAX) return;
    pq->heap[pq->size] = val;
    heapify(pq, pq->size);
    pq->size++;
}

int extractMax(struct PriorityQueue* pq) {
    if(pq->size == 0) return -1;
    
    int max = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    
    // Heapify down
    int i = 0;
    while(1) {
        int child1 = 2 * i + 1, child2 = 2 * i + 2;
        int largest = i;
        
        if(child1 < pq->size && pq->heap[child1] > pq->heap[largest]) largest = child1;
        if(child2 < pq->size && pq->heap[child2] > pq->heap[largest]) largest = child2;
        
        if(largest == i) break;
        swap(&pq->heap[i], &pq->heap[largest]);
        i = largest;
    }
    return max;
}

void display(struct PriorityQueue* pq) {
    printf("PQ: ");
    for(int i = 0; i < pq->size; i++) printf("%d ", pq->heap[i]);
    printf("\n");
}

int main() {
    struct PriorityQueue pq = {{0}, 0};
    
    insert(&pq, 10); insert(&pq, 30); insert(&pq, 20);
    insert(&pq, 50); insert(&pq, 40);
    
    display(&pq);  // 50 40 20 30 10 
    
    printf("Extract Max: %d\n", extractMax(&pq));
    display(&pq);  // 40 30 20 10 
    
    printf("Extract Max: %d\n", extractMax(&pq));
    display(&pq);  // 30 10 20 
    
    return 0;
}
