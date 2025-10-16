#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};


class CircularLL
{
public:
    Node *head;

    CircularLL() { head = nullptr; }

    void insertAtStart(int data)
    {
        Node *new_node = new Node(data);
        if (!head)
        {
            head = new_node;
            new_node->next = head;
            cout << "Node inserted at start." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
        cout << "Node inserted at start." << endl;
    }

    void insertAtEnd(int data)
    {
        Node *new_node = new Node(data);
        if (!head)
        {
            head = new_node;
            new_node->next = head;
            cout << "Node inserted at end." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
        cout << "Node inserted at end." << endl;
    }

    void insertAtPos(int data, int pos)
    {
        if (pos == 0)
        {
            insertAtStart(data);
            return;
        }
        Node *temp = head;
        int currentPos = 0;
        while (temp->next != head && currentPos < pos - 1)
        {
            temp = temp->next;
            currentPos++;
        }
        if (currentPos != pos - 1)
        {
            cout << "Position out of range" << endl;
            return;
        }
        Node *new_node = new Node(data);
        new_node->next = temp->next;
        temp->next = new_node;
        cout << "Node inserted at position " << pos << "." << endl;
    }

    void deleteAtStart()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            cout << "Node deleted from start." << endl;
            return;
        }
        Node *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        delete temp;
        cout << "Node deleted from start." << endl;
    }

    void deleteAtEnd()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            cout << "Node deleted from end." << endl;
            return;
        }
        while (temp->next->next != head)
            temp = temp->next;
        Node *del = temp->next;
        temp->next = head;
        delete del;
        cout << "Node deleted from end." << endl;
    }

    void deleteAtPos(int pos)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 0)
        {
            deleteAtStart();
            return;
        }
        Node *temp = head;
        int currentPos = 0;
        while (temp->next != head && currentPos < pos - 1)
        {
            temp = temp->next;
            currentPos++;
        }
        if (temp->next == head)
        {
            cout << "Position out of range" << endl;
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Node deleted at position " << pos << "." << endl;
    }

    void displayList()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "Circular List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayWithHeadRepeat()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        cout << "Circular List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << endl;
    }
};

int main()
{
    

    CircularLL list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);

    list1.displayWithHeadRepeat();

    return 0;
}
