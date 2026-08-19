
#include <iostream>
using namespace std;

void merge(int a[], int b[], int n, int m, int c[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < n) {
        c[k++] = a[i++];
    }

    while (j < m) {
        c[k++] = b[j++];
    }
}

int main() {
    int n, m;
    cout << "Enter the size of first array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the size of second array: ";
    cin >> m;
    int b[m];
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int c[n + m];
    merge(a, b, n, m, c);

    cout << "Merged array: ";
    for (int i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}


