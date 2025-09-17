#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}


int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1; 
        else
            right = mid - 1; 
    }
    return -1; 
}

int main() {
    int arr[] = {11, 22, 29, 34, 64, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter element to search: ";
    cin >> key;


    int linResult = linearSearch(arr, n, key);
    if (linResult != -1)
        cout << "Linear Search: Element found at index " << linResult << endl;
    else
        cout << "Linear Search: Element not found." << endl;

 
    int binResult = binarySearch(arr, n, key);
    if (binResult != -1)
        cout << "Binary Search: Element found at index " << binResult << endl;
    else
        cout << "Binary Search: Element not found." << endl;

    return 0;
}
