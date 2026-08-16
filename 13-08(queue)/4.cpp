#include <iostream>
#include <deque>   // STL deque
using namespace std;

int main() {
    deque<int> dq;
    int choice, val;

    while (true) {
        cout << "\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dq.push_front(val);   // STL insert at front
                cout << "Inserted at front: " << val << endl;
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                dq.push_back(val);    // STL insert at rear
                cout << "Inserted at rear: " << val << endl;
                break;

            case 3:
                if (!dq.empty()) {
                    cout << "Deleted from front: " << dq.front() << endl;
                    dq.pop_front();   // STL delete from front
                } else {
                    cout << "Underflow\n";
                }
                break;

            case 4:
                if (!dq.empty()) {
                    cout << "Deleted from rear: " << dq.back() << endl;
                    dq.pop_back();    // STL delete from rear
                } else {
                    cout << "Underflow\n";
                }
                break;

            case 5:
                if (dq.empty()) {
                    cout << "Deque is empty\n";
                } else {
                    cout << "Deque elements: ";
                    for (int x : dq) {
                        cout << x << " ";
                    }
                    cout << endl;
                }
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
