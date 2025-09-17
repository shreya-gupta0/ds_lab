#include <iostream>
using namespace std;

class TriDiagonalMatrix {
    int *arr;
    int n;
public:
    TriDiagonalMatrix(int n) {
        this->n = n;
        arr = new int[3 * n - 2]; 
        for (int i = 0; i < 3 * n - 2; i++) arr[i] = 0;
    }

    void set(int i, int j, int val) {
        if (i - j == 0) arr[n - 1 + i - 1] = val;       
        else if (i - j == 1) arr[i - 2] = val;          
        else if (j - i == 1) arr[2 * n - 1 + i - 1] = val; 
    }

    int get(int i, int j) {
        if (i - j == 0) return arr[n - 1 + i - 1];
        else if (i - j == 1) return arr[i - 2];
        else if (j - i == 1) return arr[2 * n - 1 + i - 1];
        else return 0;
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
    TriDiagonalMatrix t(4);
    t.set(1, 1, 10);
    t.set(1, 2, 2);
    t.set(2, 1, 3);
    t.set(2, 2, 15);
    t.set(2, 3, 5);
    t.set(3, 2, 7);
    t.set(3, 3, 18);
    t.set(3, 4, 9);
    t.set(4, 3, 11);
    t.set(4, 4, 20);

    cout << "Tri-Diagonal Matrix:" << endl;
    t.display();
    return 0;
}
