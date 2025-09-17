#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

// Multiply sparse matrices in triplet form
void multiply(Element a[], Element b[], Element c[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible\n";
        return;
    }

    c[0].row = a[0].row;
    c[0].col = b[0].col;
    int k = 1;

    for (int i = 0; i < a[0].row; i++) {
        for (int j = 0; j < b[0].col; j++) {
            int sum = 0;
            for (int x = 1; x <= a[0].val; x++) {
                if (a[x].row == i) {
                    for (int y = 1; y <= b[0].val; y++) {
                        if (b[y].col == j && b[y].row == a[x].col) {
                            sum += a[x].val * b[y].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                c[k].row = i;
                c[k].col = j;
                c[k].val = sum;
                k++;
            }
        }
    }
    c[0].val = k - 1;
}

int main() {
    Element a[4] = {{2, 2, 2}, {0, 0, 1}, {1, 1, 2}};
    Element b[4] = {{2, 2, 2}, {0, 0, 3}, {1, 1, 4}};
    Element c[10];

    multiply(a, b, c);

    cout << "Multiplication (Triplet form):\n";
    for (int i = 0; i <= c[0].val; i++) {
        cout << c[i].row << " " << c[i].col << " " << c[i].val << endl;
    }
    return 0;
}
