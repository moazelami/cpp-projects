#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return (top == NULL); // True .. else False
    }

    void push(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        if(isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    
    int pop()
    {
        int value;
        Node *delptr = top;
        value = top->data;
        top = top->next;
        delete delptr;
        return value;
    }

    int peak()
    {
        return top->data;
    }

    bool isFound(int item)
    {
        bool found = false;
        Node *temp = top;
        while(temp != NULL)
        {
            if(temp->data == item)
            {
                found = true;
            }
            temp = temp->next;
        }
        return found;
    }

    bool isFull()
    {
        bool Full;
        Node *ptr = new Node();
        if(ptr == NULL)
            Full = true;
        else
            Full = false;
        return Full;
    }


    int count()
    {
        int counter = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void display()
    {
        Node *temp = top;
        while(temp != NULL)
        {
            cout << temp->data << " , ";
            temp = temp->next;
        }
    }
};

int main()
{
    Stack stk;
    int item , NumberOfItems;
    
    cout << "Enter The Number Of Stack Items = ";
    cin >> NumberOfItems;
    cout << endl;
    
    for (int i = 0; i < NumberOfItems; i++)
    {
        cout << "Enter  Items to Push" << endl;
        cin >> item;
        stk.push(item);
    }
    
    cout << "\n================\n";
    
    cout << "Stack = ";
    stk.display();
    cout << endl;
    cout << "TOP Item = " << stk.peak() << endl;
    cout << "Count Of items = " << stk.count() << endl;
    
    cout << "\n================\n";
    
    cout << "Enter Item For Search : ";
    cin >> item;
    if(stk.isFound(item))
        cout << "Item Founded" << endl;
    else
        cout << "Item Not Founded!!" << endl;
    
    cout << "\n================\n";
    if(stk.isFull())
        cout << "Stack is Full!! , Can't Enter More Items" << endl;
    else
        cout << "Stack Not Full , Can Enter More Items" << endl;
    stk.pop();
    stk.pop();
    stk.pop();
    cout << "Stack After POP : " << endl;
    stk.display();
    
    return 0;
}
