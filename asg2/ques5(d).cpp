#include <iostream>
using namespace std;

class UpperTriangularMatrix {
    int *arr;
    int n;
public:
    UpperTriangularMatrix(int n) {
        this->n = n;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++) arr[i] = 0;
    }

    void set(int i, int j, int val) {
        if (i <= j) arr[(i - 1) * n - (i - 1) * (i - 2) / 2 + (j - i)] = val;
    }

    int get(int i, int j) {
        if (i <= j) return arr[(i - 1) * n - (i - 1) * (i - 2) / 2 + (j - i)];
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UpperTriangularMatrix u(4);
    u.set(1, 1, 5); u.set(1, 2, 6); u.set(1, 3, 7); u.set(1, 4, 8);
    u.set(2, 2, 10); u.set(2, 3, 12); u.set(2, 4, 14);
    u.set(3, 3, 18); u.set(3, 4, 20);
    u.set(4, 4, 22);

    cout << "Upper Triangular Matrix:" << endl;
    u.display();
    return 0;
}
