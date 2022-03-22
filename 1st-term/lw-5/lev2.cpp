#include <iostream>

using namespace std;

int main() {
    int n, m, **a;
    cout << "Input N: ";
    cin >> n;
    cout << "Input M: ";
    cin >> m;

    // Create matrix N x M
    a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    } // end


    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m-1; j++) {
            if ((a[i][j] > a[i][j - 1]) && (a[i][j] < a[i][j + 1]));
            {
                counter++;
            }
        }
    }

    cout << "Answer is " << counter;
}
