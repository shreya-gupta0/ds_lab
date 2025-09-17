#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    // Step 1: Ask the user how many numbers they want to enter
    cout << "How many numbers do you want to enter? ";
    cin >> n;
    if (n > 100 || n <= 0) {
        cout << "Invalid number of elements! Must be between 1 and 100.\n";
        return 1;
    }

    // Step 2: Take input from the user
    cout << "Please enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Now we'll remove duplicates from this array
    // We'll use a new index (newLength) to track unique values
    int newLength = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // Check if this number already exists in the new part of the array
        for (int j = 0; j < newLength; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;  // We found a duplicate
                break;
            }
        }

        // If it's not a duplicate, add it to the "unique" part of the array
        if (!isDuplicate) {
            arr[newLength] = arr[i];  // Move the value forward
            newLength++;              // Increase the count of unique values
        }
    }

    // Step 4: Print the array after removing duplicates
    cout << "\nArray after removing duplicate values:\n";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
