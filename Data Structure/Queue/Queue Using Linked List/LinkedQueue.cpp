#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr){}
};

class Queue
{
public:
    Node *front;
    Node *rear;
    Queue() : front(nullptr) , rear(nullptr){}

    bool isEmpty()
    {
        return (front == nullptr && rear == nullptr);
    }

    void enQueue(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        if(isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void Dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty...!" << endl;
            return;
        }

        int value;
        if(front == rear)
        {
            value = front->data;
            delete front;
            front = rear = nullptr;
        }
        else
        {    
            Node *delPtr = front;
            value = front->data;
            front = front->next;
            delete delPtr;
        }

        cout << "Deleted Value = " << value << endl;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return front->data;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return rear->data;
    }

    int count()
    {
        
        int counter = 0;

        if(isEmpty())
        {
            cout << "Queue is Empty.....!" << endl;
        }
        else
        {
            Node *temp = front;
            while(temp != nullptr)
            {
                counter++;
                temp = temp->next;
            }
        }

        return counter;
    }

    bool isFound(int item)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            Node *temp = front;
            while (temp != nullptr)
            {
                if(temp->data == item)
                {
                    return true;
                    break;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    void clear()
    {
        while(!isEmpty())
        {
            Dequeue();
        }
    }    

    void display()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty...!" << endl;
        }
        else
        {
            Node *temp = front;
            while(temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

};

int main()
{
    Queue Q;

    cout << "Enqueue elements:\n";
    Q.enQueue(10);
    Q.enQueue(20);
    Q.enQueue(30);
    Q.enQueue(40);
    Q.enQueue(50);

    cout << "Queue: ";
    Q.display();

    cout << "\nCount = " << Q.count() << endl;

    cout << "\nDequeue one element:\n";
    Q.Dequeue();

    cout << "Queue after dequeue: ";
    Q.display();

    cout << "\nCount = " << Q.count() << endl;

    int item = 50;
    if (Q.isFound(item))
        cout << item << " is Found\n";
    else
        cout << item << " is Not Found\n";

    cout << "\nFront = " << Q.getFront() << endl;
    cout << "Rear = " << Q.getRear() << endl;

    cout << "\nClearing queue...\n";
    Q.clear();

    cout << "After clear: ";
    Q.display();

    return 0;
}