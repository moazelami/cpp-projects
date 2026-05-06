#include <iostream>
#include <cassert>
using namespace std;

template <class t>
class ArrayQueueType
{
    int rear;
    int front;      
    int length;     
    t *arr;
    int MAX_LENGTH;

public:
    ArrayQueueType(int size)
    {
        if(size <= 0)
            MAX_LENGTH = 100;
        else
            MAX_LENGTH = size;
        arr = new t[MAX_LENGTH];
        front = 0;
        rear = MAX_LENGTH - 1;
        length = 0;
    }
    bool isEmpty()
    {
        return (length == 0);
    }
    bool isFull()
    {
        return length == MAX_LENGTH;
    }
    void addQueue(t item)
    {
        if(isFull())
        {
            cout << "Queue Full Can't Enqueue /...!" << endl;
        }else
        {
            rear = (rear + 1) % MAX_LENGTH;
            arr[rear] = item;
            length++;
        }
    }

    void Delete()
    {
        if(isEmpty())
        {
            cout << "Queue Empty Can't Enqueue /...!" << endl;
        }else
        {
            front = (front + 1) % MAX_LENGTH;
            --length;
        }
    }

    int frontQueue()
    {
        assert(!isEmpty());
        return arr[front]; 
    }
    
    int rearQueue()
    {
        assert(!isEmpty());
        return arr[rear];
    }

    int search(t item)
    {
        int pos = -1;
        if(!isEmpty())
        {
            for (int i = front; i != rear + 1; i = (i + 1) % MAX_LENGTH)
            {
                if(arr[i] == item)
                {
                    pos = i;
                    break;
                }
            }

            if(pos == -1)
            {
                if(arr[rear] == item)
                {
                    pos == rear;
                }
            }
        }
        else
            cout << "Q is empty !" << endl;
        return pos;
    }

    void display()
    {
        for (int i = front; i != rear + 1; i = (i+1)%MAX_LENGTH)
        {
            cout << " " << arr[i];
        }
    }
};

int main()
{
    ArrayQueueType <int>Q(100);
    
    Q.addQueue(10);
    Q.addQueue(20);
    Q.addQueue(30);
    Q.addQueue(40);
    Q.addQueue(50);

    cout << "\n.....................\n";
    cout << "Queue Elements = ";
    Q.display();
    cout << "\n.....................\n";
    cout << "Front of Queue = ";
    cout << Q.frontQueue() << endl;
    cout << "\n.....................\n";
    cout << "Back of Queue = ";
    cout<< Q.rearQueue() << endl;
    cout << "\n.....................\n";
    Q.Delete();
    cout << "Queue After Delete = ";
    Q.display();
    cout << "\n.....................\n";
    cout<<"element 50 in pos --> "<<Q.search(50);
    return 0;
}