#include <iostream>
using namespace std;

class SinglyLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;

    Node *createNode(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int value)
    {
        Node *newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = createNode(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertBeforeAfter(int value, int target, bool after)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *newNode = createNode(value);
        Node *temp = head;

        if (!after && head->data == target)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        while (temp && temp->next)
        {
            if ((after && temp->data == target) || (!after && temp->next->data == target))
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Target value not found!" << endl;
    }

    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int key)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (!temp->next)
            cout << "Node not found!" << endl;
        else
        {
            Node *del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    void searchNode(int key)
    {
        Node *temp = head;
        int pos = 1;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Node found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found." << endl;
    }

    void displayList()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "Linked List: ";
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverseList()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.displayList();
    
    list.reverseList();
    list.displayList();

    return 0;
}
