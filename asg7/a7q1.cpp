#include<stdio.h>

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

// a. SELECTION SORT
void selection(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[min_idx]) min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// b. INSERTION SORT
void insertion(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; j--;
        }
        arr[j+1] = key;
    }
}

// c. BUBBLE SORT
void bubble(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
}

// d. MERGE SORT
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// e. QUICK SORT
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    printf("Original: "); print(arr, n);
    
    // Test all sorts
    selection(arr, n); printf("Selection: "); print(arr, n);
    insertion(arr, n); printf("Insertion: "); print(arr, n);
    bubble(arr, n); printf("Bubble: "); print(arr, n);
    mergeSort(arr, 0, n-1); printf("Merge: "); print(arr, n);
    quickSort(arr, 0, n-1); printf("Quick: "); print(arr, n);
    
    return 0;
}
