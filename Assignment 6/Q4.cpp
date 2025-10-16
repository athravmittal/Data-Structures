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

    bool isPalindrome()
    {
        if (!head)
            return true;

        Node *left = head;
        Node *right = head;

        while (right->next != nullptr)
            right = right->next;

        while (left != right && left->prev != right)
        {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main()
{
    Doublell list;

    list.insertAtStart(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtPos(15, 1);

    cout << list.isPalindrome() << endl;

    return 0;
}