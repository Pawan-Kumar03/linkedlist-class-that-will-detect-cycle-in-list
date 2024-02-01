/*
    Lab05 Task03
    Code By  : Pawan Kumar
    CMS : 023-21-0136
    Section-C

    Write a method in linkedlist class that will detect cycle in list?
*/


#include <iostream>
using namespace std;

// node class
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Singly Linked List Class
class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    // 2.Append a node  to the list
    void appendeNode(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            cout << "Node Appended." << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
            cout << "Node Appended" << endl;
        }
    }

    void makeCycle()
    {
        Node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        if (ptr->next == NULL)
            ptr->next = head->next->next;
            cout<<"Now Link is Cyclic."<<endl;
    }

    void checkCycle(Node *n)
    {
        Node *slow = n;
        Node *fast = n;
        do
        {
            if (slow->next == NULL || fast->next == NULL || fast->next->next == NULL){
                fast=fast->next;
                break;
            }

            slow = slow->next;
            fast = fast->next->next;

        } while (slow != fast);
        if (slow == fast)
            cout << "Link is Cyclic : " << endl;
        else
            cout << "Link is not Cyclic : " << endl;
    }

    // 7.Printing  SinglyLinkedList
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in  Linked List " << endl;
        }
        else
        {
            cout << endl
                 << " Linked List Values : ";
            Node *temp = head;
            Node *ptr = NULL;
            bool check=true;
            while (check)
            {
                ptr=head;
                cout << "( " << temp->data << " )-- > ";
                while (ptr!=temp)
                {
                    ptr=ptr->next;
                    if (ptr->next==temp->next && ptr->data!=temp->data)
                    {
                        check=false;
                        break;
                    }
                }
                
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << endl
             << "What Operation do you want to perform?\nSelect Option number.Enter 0 to exist" << endl;
        cout << "1. Append Node ." << endl;
        cout << "2. Check Cycle ." << endl;
        cout << "3. Print list ." << endl;
        cout << "4. Make Cycle : " << endl;
        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 1:
            cout << "Append Node Operation \nEnter  Data of the Node to be Appended" << endl;
            cin >> data1;
            n1->data = data1;
            s.appendeNode(n1);
            break;
        case 2:
            s.checkCycle(s.head);
            break;
        case 3:
            s.printList();
            break;
        case 4:
            s.makeCycle();
            break;
        default:
            cout << "Enter proper Option Number." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
