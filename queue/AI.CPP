#include <iostream>
using namespace std;

#define MAX 100

struct Item {
    int value;
    int priority;
};

Item pq[MAX];   // array for priority queue
int size = 0;   // current size

// Insert element into priority queue
void insert(int value, int priority) {
    if (size == MAX) {
        cout << "Queue overflow!" << endl;
        return;
    }
    pq[size].value = value;
    pq[size].priority = priority;
    size++;
}

// Delete element with highest priority
void deleteHighest() {
    if (size == 0) {
        cout << "Queue underflow!" << endl;
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    cout << "Deleted: " << pq[highestPriorityIndex].value 
         << " (priority " << pq[highestPriorityIndex].priority << ")" << endl;

    // Shift elements left
    for (int i = highestPriorityIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Display queue
void display() {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Priority Queue: ";
    for (int i = 0; i < size; i++) {
        cout << "(" << pq[i].value << "," << pq[i].priority << ") ";
    }
    cout << endl;
}

int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);
    insert(40, 4);

    display();

    deleteHighest();
    display();

    deleteHighest();
    display();

    return 0;
}
