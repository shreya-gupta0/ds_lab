#include <iostream>
using namespace std;

class DiagonalMatrix {
    int *arr;
    int n; // size
public:
    DiagonalMatrix(int n) {
        this->n = n;
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = 0;
    }

    void set(int i, int j, int val) {
        if (i == j) arr[i - 1] = val;
    }

    int get(int i, int j) {
        if (i == j) return arr[i - 1];
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
    DiagonalMatrix d(4);
    d.set(1, 1, 5);
    d.set(2, 2, 8);
    d.set(3, 3, 12);
    d.set(4, 4, 20);

    cout << "Diagonal Matrix:" << endl;
    d.display();
    return 0;
}
