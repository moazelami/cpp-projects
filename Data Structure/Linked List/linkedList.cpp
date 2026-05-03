#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL); // True .. else False
    }

    void insertFirst(int newValue)
    {
        Node *newNode = new Node;
        newNode->data = newValue;
        if (isEmpty())
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int count()
    {
        int counter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isFound(int key)
    {
        bool found = false;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
                found = true;

            temp = temp->next;
        }
        return found;
    }

    void insertbefore(int item , int newValue)
    {
        if(isEmpty())
        {
            insertFirst(newValue);
        }
        else
        {
            if(isFound(item))
            {
            Node *newNode = new Node();
            newNode->data = newValue;
            Node *temp = head;
                while(temp != NULL && temp->next->data != item)
                {
                    temp = newNode->next;
                }
            newNode->next = temp->next;
            temp->next = newNode;
            }
            else
            {
            cout << "Sorry , Item Not Found" << endl;
            }
        }
    }

    void append(int newValue)
    {
        if(isEmpty())
            insertFirst(newValue);
        else
        {
            Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *newNode = new Node();
            newNode->data = newValue;
            temp->next - newNode;
            newNode->next = NULL;
        }
    }

};

int main()
{
    linkedList lst;
    if(lst.isEmpty())
        cout << "The List is Empty" << endl;
    else
        cout << "The List contains " << lst.count() << endl;
    cout << "\n==========================\n";
    int item;
    cout << "Enter item to insert in the list" << endl;
    cin >> item;
    lst.insertFirst(item);
    lst.display();
    cout << "\n==========================\n";
    cout << "Enter item to insert in the list" << endl;
    cin >> item;
    lst.insertFirst(item);
    lst.display();
    cout << "\n==========================\n";
    cout << "Enter item to insert in the list" << endl;
    cin >> item;
    lst.insertFirst(item);
    lst.display();
    cout << "\n==========================\n";
    cout << "Enter item to insert in the list" << endl;
    cin >> item;
    lst.insertFirst(item);
    lst.display();
    cout << "\n==========================\n";
    cout << "The List contains " << lst.count() << endl;
    cout << "\n==========================\n";
    cout << "Enter item to search for" << endl;
    cin >> item;
    if(lst.isFound(item))
        cout << "item Founded" << endl;
    else
        cout << "item not Founded" << endl;

    cout << "\n==========================\n";
    int newValue;
    cout << "Enter Item and new value to insert" << endl;
    cin >> item >> newValue;
    lst.insertbefore(item , newValue);
    lst.display();
    cout << "\n==========================\n";
    lst.append(newValue);
    lst.display();
    return 0;
}