#include <iostream>
using namespace std;

void merge(int a[], int b[], int n, int m) {
   
    int i = 0;
    int j = 0;
    int k = 0;

    int c[n + m]; // Create a new array to hold the merged result

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
            k++;
        } else {
            c[k] = b[j];
            j++;
            k++;

        }
       
    }

    while (i < n) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < m) {
        c[k] = b[j];
        j++;
        k++;
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
    merge(a, b, n, m);

    cout << "Merged array: ";
    for (int i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}

