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
        if(isEmpty())
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
        while(temp != NULL)
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
            if(temp -> data ==key)
                found = true;

            temp = temp->next;
        }
        return found;
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



    return 0;
}