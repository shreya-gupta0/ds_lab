#include <iostream>
using namespace std;


struct Element {
    int row, col, val;
};


void transpose(Element a[], Element b[]) {
    int n = a[0].val;  
    int p = 1;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;

    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j].col == i) {
                b[p].row = a[j].col;
                b[p].col = a[j].row;
                b[p].val = a[j].val;
                p++;
            }
        }
    }
}

int main() {
    Element a[5] = {{3, 3, 4}, {0, 0, 1}, {0, 2, 2}, {1, 1, 3}, {2, 0, 4}};
    Element b[5];

    transpose(a, b);

    cout << "Transpose (Triplet form):\n";
    for (int i = 0; i <= b[0].val; i++) {
        cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
    }
    return 0;
}
