#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

void add(Element a[], Element b[], Element c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible\n";
        return;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    int i = 1, j = 1, k = 1;
    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        } else if ((a[i].row < b[j].row) || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];

    c[0].val = k - 1;
}

int main() {
    Element a[4] = {{2, 2, 2}, {0, 0, 3}, {1, 1, 4}};
    Element b[4] = {{2, 2, 2}, {0, 1, 5}, {1, 1, 6}};
    Element c[10];

    add(a, b, c);

    cout << "Addition (Triplet form):\n";
    for (int i = 0; i <= c[0].val; i++) {
        cout << c[i].row << " " << c[i].col << " " << c[i].val << endl;
    }
    return 0;
}
