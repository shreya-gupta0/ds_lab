#include <iostream>
using namespace std;

int main() {
    int matrix[10][10];
    int row, col;

    // Step 1: Take input for matrix size
    cout << "Enter number of rows: ";
    cin >> row;

    cout << "Enter number of columns: ";
    cin >> col;

    if (row <= 0 || row > 10 || col <= 0 || col > 10) {
        cout << "Invalid size! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    // Step 2: Input elements
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    // Step 3: Sum of each row
    cout << "\nSum of each row:\n";
    for (int i = 0; i < row; i++) {
        int rowSum = 0;
        for (int j = 0; j < col; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    // Step 4: Sum of each column
    cout << "\nSum of each column:\n";
    for (int j = 0; j < col; j++) {
        int colSum = 0;
        for (int i = 0; i < row; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }

    return 0;
}
