#include<stdio.h>

void swap(int* a, int* b) { 
    int t = *a; *a = *b; *b = t; 
}

void improvedSelection(int arr[], int n) {
    int left = 0, right = n-1;
    
    while(left < right) {
        int min_idx = left, max_idx = left;
        
        // Find min and max in unsorted portion
        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[min_idx]) min_idx = i;
            if(arr[i] > arr[max_idx]) max_idx = i;
        }
        
        // Place min at left, max at right
        swap(&arr[min_idx], &arr[left]);
        swap(&arr[max_idx], &arr[right]);
        
        left++; right--;
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
    
    improvedSelection(arr, n);
    printf("Improved Selection: "); print(arr, n);
    
    return 0;
}
