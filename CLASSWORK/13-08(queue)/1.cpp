#include <iostream>
#include <queue>
using namespace std;

#define n 5
int q[n];
int f = -1;
int r = -1;


void enqueue(){
    int val;
    if( r == n - 1){
        cout << "overflow" << endl;
    }
    
    else {
        if(f == -1){
            f = 0;
        }
        cin >> val;
        r ++;
    q[r] = val;
    }
    
    

}

void dequeue(){
    if( f == -1 || f > r){
        cout << "underflow" << endl;
    }
    else {
        cout << q[f];
        f ++;
    }

}

void display(){
    if(f == -1 || f > r){
        cout << "queue is empty" << endl;
    }
    else {
        for (int i = f; i <= r ; i ++){
            cout << q[i] << " ";
        }
        cout << endl;
    }
}

int main(){

    int x;
    
    while(true){
    cin >> x;
    
        switch (x) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
            cout << "exiting program...\n";
            return 0;
            default:
                cout << "Invalid choice! Please enter a option between 1 and 4.\n";
    }

   
    }
}