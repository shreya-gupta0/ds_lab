#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter size of array: ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "Invalid array size! Must be between 1 and 100.\n";
        return 1;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Swapping elements from start and end
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    cout << "Reversed array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
