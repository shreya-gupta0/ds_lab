#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    // Input sizes
    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;
    if (r1 <= 0 || r1 > 10 || c1 <= 0 || c1 > 10) {
        cout << "Invalid size for Matrix A! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;
    if (r2 <= 0 || r2 > 10 || c2 <= 0 || c2 > 10) {
        cout << "Invalid size for Matrix B! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    // Check multiplication rule
    if (c1 != r2) {
        cout << "Matrix multiplication not possible (columns of A ≠ rows of B)." << endl;
        return 0;
    }

    // Input Matrix A
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    // Input Matrix B
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    // Multiply matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output result
    cout << "Resultant Matrix (A x B):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
