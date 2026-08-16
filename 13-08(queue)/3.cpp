#include<iostream>
using namespace std;

#define MAX 5

struct Deque {
    int arr[MAX];
    int front = -1;
    int rear = -1;

    // Insert at front
    void insertFront(int item) {
        if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
            cout << "Overflow\n";
            return;
        }

        if (front == -1) { // empty
            front = rear = 0;
        }
        else if (front == 0) {
            front = MAX - 1;
        }
        else {
            front--;
        }

        arr[front] = item;
        cout << "Inserted at front: " << item << endl;
    }

    // Insert at rear
    void insertRear(int item) {
        if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
            cout << "Overflow\n";
            return;
        }

        if (rear == -1) { // empty
            front = rear = 0;
        }
        else if (rear == MAX - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = item;
        cout << "Inserted at rear: " << item << endl;
    }

    // Delete from front
    void deleteFront() {
        if (front == -1) {
            cout << "Underflow\n";
            return;
        }

        cout << "Deleted from front: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == MAX - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    // Delete from rear
    void deleteRear() {
        if (rear == -1) {
            cout << "Underflow\n";
            return;
        }

        cout << "Deleted from rear: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = MAX - 1;
        }
        else {
            rear--;
        }
    }

    // Display
    void display() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque elements: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, val;

    while (true) {
        cout << "\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dq.insertFront(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                dq.insertRear(val);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}