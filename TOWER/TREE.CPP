#include <iostream>
using namespace std;

void toh(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << A << " to rod " << C << endl;
        return;
    }
    toh(n - 1, A, C, B);
    cout << "Move disk " << n << " from rod " << A << " to rod " << C << endl;
    toh(n - 1, B, A, C);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    toh(n, 'A', 'B', 'C');
    return 0;
}