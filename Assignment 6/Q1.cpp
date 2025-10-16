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

class Doublell
{
public:
    Node *head;

    Doublell()
    {
        head = nullptr;
    }

    void insertAtStart(int data)
    {
        Node *new_node = new Node(data);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insertAtTail(int data)
    {
        Node *new_node = new Node(data);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
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

        while (temp != nullptr && currentPos < pos - 1)
        {
            temp = temp->next;
            currentPos++;
        }

        if (temp == nullptr)
        {

            cout << "Position out of range\n";
            return;
        }

        Node *new_node = new Node(data);
        new_node->next = temp->next;
        new_node->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = new_node;
        }

        temp->next = new_node;
    }

    void delAtStart()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
    }

    void delAtEnd()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;

        if (temp->next == nullptr)
        {
            delete temp;
            head = nullptr;
            return;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void delAtPos(int pos)
    {
        if (head == nullptr)
        {
            return;
        }

        if (pos == 0)
        {
            delAtStart();
            return;
        }

        Node *temp = head;
        int currentPos = 0;

        while (temp != nullptr && currentPos < pos)
        {
            temp = temp->next;
            currentPos++;
        }

        if (temp == nullptr)
        {

            cout << "Position out of range\n";
            return;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void displayList()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
            cout << "Node inserted at start.\n";
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
        cout << "Node inserted at start.\n";
    }

    void insertAtEnd(int data)
    {
        Node *new_node = new Node(data);
        if (!head)
        {
            head = new_node;
            new_node->next = head;
            cout << "Node inserted at end.\n";
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
        cout << "Node inserted at end.\n";
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
            cout << "Position out of range\n";
            return;
        }
        Node *new_node = new Node(data);
        new_node->next = temp->next;
        temp->next = new_node;
        cout << "Node inserted at position " << pos << ".\n";
    }

    void deleteAtStart()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            cout << "Node deleted from start.\n";
            return;
        }
        Node *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        delete temp;
        cout << "Node deleted from start.\n";
    }

    void deleteAtEnd()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            cout << "Node deleted from end.\n";
            return;
        }
        while (temp->next->next != head)
            temp = temp->next;
        Node *del = temp->next;
        temp->next = head;
        delete del;
        cout << "Node deleted from end.\n";
    }

    void deleteAtPos(int pos)
    {
        if (!head)
        {
            cout << "List is empty.\n";
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
            cout << "Position out of range\n";
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Node deleted at position " << pos << ".\n";
    }

    void displayList()
    {
        if (!head)
        {
            cout << "List is empty.\n";
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

    
};

int main()
{
    Doublell list;

    list.insertAtStart(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtPos(15, 1);

    list.delAtStart();

    list.delAtEnd();

    list.delAtPos(1);

    list.delAtPos(0);

    CircularLL list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);

    return 0;
}