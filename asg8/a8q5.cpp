#include<stdio.h>

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    
    for(int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapSortDesc(int arr[], int n) { 
    buildMaxHeap(arr, n);
    
    for(int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    // Reverse for decreasing order
    for(int i = 0; i < n/2; i++)
        swap(&arr[i], &arr[n-1-i]);
}

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    printf("Original: "); print(arr, n);
    
    heapSort(arr, n);
    printf("Increasing: "); print(arr, n);
    
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    heapSortDesc(arr2, n);
    printf("Decreasing: "); print(arr2, n);
    
    return 0;
}
