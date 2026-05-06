#include <iostream>
using namespace std;

#define size 5
int Stack[size], top = -1;

void push(int value);
int pop();
int peek();
void display();

int main()
{
    push(5);
    push(10);
    push(15);
    display();
    cout << "\n=============\n";
    pop();
    display();
    cout << "\n=============\n";
    cout <<"peek = "<< peek() << endl;
    display();
    cout << "\n=============\n";
    return 0;
}

void push(int value)
{
    if(top == size - 1)
        cout << "Stack overflow" << endl;
    else
        top++;
        Stack[top] = value;
}

int pop()
{
    if(top == -1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        return Stack[top--];
    }
}

int peek()
{
    if (top == -1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        return Stack[top];
    }
}

void display()
{
    if(top == -1)
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        for (int i = top; i >= 0;i--)
        {
            cout << Stack[i] << endl;
        }
    }
}