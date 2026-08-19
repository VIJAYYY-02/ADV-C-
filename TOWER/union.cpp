#include <iostream>
using namespace std;

void unionArrays(int a[], int b[], int n, int m, int c[], int &size) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else if (b[j] < a[i]) {
            c[k++] = b[j++];
        } else { 
            c[k++] = a[i];
            i++;
            j++;
        }
    }

    while (i < n) {
        c[k++] = a[i++];
    }

    while (j < m) {
        c[k++] = b[j++];
    }

    size = k; // final size of union array
}

int main() {
    int n, m;
    cout << "Enter the size of first array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the size of second array: ";
    cin >> m;
    int b[m];
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int c[n + m], size;
    unionArrays(a, b, n, m, c, size);

    cout << "Union array: ";
    for (int i = 0; i < size; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}
