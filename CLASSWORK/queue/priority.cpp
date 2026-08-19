#include <iostream>
using namespace std;

#define MAX 5

struct PriorityQueue {
    int arr[MAX];
 
       int size = 0; // Keeps track of the number of elements

    // Function to insert an element based on priority
    void Enqueue(int item) {
        // 1. Check for Overflow
        if (size == MAX) {
            cout << "Overflow! Priority Queue is full." << endl;
            return;
        }

        
        int i;
        for (i = size - 1; (i >= 0 && arr[i] > item); i--) {
            arr[i + 1] = arr[i]; // Shift larger elements to the right
        }

        // 3. Insert item at its correct sorted place
        arr[i + 1] = item;
        size++;

        cout << "Inserted: " << item << endl;
    }

    // Function to delete the highest priority element
    void Dequeue() {
        // 1. Check for Underflow
        if (size == 0) {
            cout << "Underflow! Priority Queue is empty." << endl;
            return;
        }

        
        cout << "Deleted (Highest Priority): " << arr[size - 1] << endl;

        
        size--;
    }

    
    void display() {
        if (size == 0) {
            cout << "Queue empty" << endl;
            return;
        }

        cout << "Priority Queue elements (Low to High Priority): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, val;

    while (true) {
        cout << "\n--- SELECT---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Dequeue " << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                pq.Enqueue(val);
                break;

            case 2:
                pq.Dequeue();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}