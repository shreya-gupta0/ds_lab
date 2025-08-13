#include <iostream>
using namespace std;

int main() {
    int matrix[10][10], transpose[10][10];
    int r, c;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    if (r <= 0 || r > 10 || c <= 0 || c > 10) {
        cout << "Invalid size! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    cout << "Enter the matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];

    // Transposing
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            transpose[j][i] = matrix[i][j];

    // Display result
    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
