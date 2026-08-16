#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *head = NULL;


void push()
{
    int x;
    
    cin >> x;

    node *temp = new node;

    if(head == NULL)
    {
        temp->data = x;
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->data = x;
        temp->next = head;
        head = temp;
    }
}

int pop()
{
    if(head == NULL)
    {
        cout << "Underflow" << endl;
        return -1;
    }
    else
    {
        int x = head->data;
        node *temp = head;
        head = head->next;
        delete(temp);
        return x;
    }
}


void display()
{
    if(head == NULL)
    {
        cout << "Empty" << endl;
    }
    else
    {
        node *temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    int choice, value;

    do
    {
       
        
        cin >> choice;

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                value = pop();
                if(value != -1)
                    cout << "Deleted Element = " << value << endl;
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program Ended.";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while(choice != 4);

    return 0;
}