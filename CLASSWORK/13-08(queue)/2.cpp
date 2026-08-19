#include <iostream>
using namespace std;

#define MAX 5

class Deque {
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    void insertFront(int x) {
        if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX-1;
        } else {
            front--;
        }
        arr[front] = x;
        cout << "Inserted at front: " << x << endl;
    }

    void insertRear(int x) {
        if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
            cout << "Overflow\n";
            return;
        }
        if (rear == -1) {
            front = rear = 0;
        } else if (rear == MAX-1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        cout << "Inserted at rear: " << x << endl;
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Underflow\n";
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX-1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (rear == -1) {
            cout << "Underflow\n";
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX-1;
        } else {
            rear--;
        }
    }
};
#include <iostream>
using namespace std;

#define MAX 5

// (Deque class definition stays the same)

int main() {
    Deque dq;

    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(30);

    dq.deleteFront();
    dq.deleteRear();

    dq.insertRear(40);
    dq.insertFront(50);

    dq.deleteFront();
    dq.deleteRear();

    return 0;
}
