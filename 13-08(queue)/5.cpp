#include <iostream>
using namespace std;

#define MAX 6

int main() {
    char deque[MAX + 1] = {' ', ' ', 'A', 'B', 'C', 'D', ' '};

    int left = 2;
    int right = 5;

    // 1. F is added to the right
    if (right < MAX) {
        right++;
        deque[right] = 'F';
    }

    // 2. Two letters on right are deleted
    if (left <= right) {
        deque[right] = ' ';
        right--;
    }

    if (left <= right) {
        deque[right] = ' ';
        right--;
    }

    // 3. K, L, M are added to the left
    if (left > 1) {
        deque[--left] = 'K';
    }

    if (left > 1) {
        deque[--left] = 'L';
    }

    if (left > 1) {
        deque[--left] = 'M';
    }

    // 4. B is deleted from the left
    if (left <= right) {
        deque[left] = ' ';
        left++;
    }

    // 5. R is added to the left
    if (left > 1) {
        deque[--left] = 'R';
    }

    // 6. S is added to the right
    if (right < MAX) {
        deque[++right] = 'S';
    }

    // 7. T is added to the right
    if (right < MAX) {
        deque[++right] = 'T';
    }

    // Display final deque
    cout << "Final Deque: ";

    for (int i = 1; i <= MAX; i++) {
        if (deque[i] != ' ')
            cout << deque[i] << " ";
        else
            cout << "- ";
    }

    cout << "\nLeft = " << left;
    cout << "\nRight = " << right << endl;

    return 0;
}