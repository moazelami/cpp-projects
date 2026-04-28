#include <iostream>
using namespace std;

class Node
{
public:
        int val;
        Node *next;

        Node()
        {
                val = 0;
                next = nullptr;
        }
        Node(int x)
        {
                val = x;
                next = nullptr;
        }
};

int main()
{
        Node *head;

        Node *node1 = new Node(1);
        Node *node2 = new Node(2);
        Node *node3 = new Node(3);

        node1->next = node2;
        node2->next = node3;

        head = node1;

        while(head != nullptr)
                {
                        cout << head->val << endl;
                        head = head->next;
                }


        return 0;
}