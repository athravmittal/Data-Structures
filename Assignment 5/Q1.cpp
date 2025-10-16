#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = createNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertBeforeAfter(int value, int target, bool after) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* newNode = createNode(value);
        Node* temp = head;

        if (!after && head->data == target) {
            newNode->next = head;
            head = newNode;
            return;
        }

        while (temp && temp->next) {
            if ((after && temp->data == target) || (!after && temp->next->data == target)) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Target value not found!" << endl;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int key) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (!temp->next)
            cout << "Node not found!" << endl;
        else {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found." << endl;
    }

    void displayList() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int number, value, target;

    while (true) {
        cout << "MENU" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before a Node" << endl;
        cout << "4. Insert After a Node" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete a Specific Node" << endl;
        cout << "8. Search a Node" << endl;
        cout << "9. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your number: ";
        cin >> number;

        switch (number) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value and target: ";
            cin >> value >> target;
            list.insertBeforeAfter(value, target, false);
            break;
        case 4:
            cout << "Enter value and target: ";
            cin >> value >> target;
            list.insertBeforeAfter(value, target, true);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteSpecific(value);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            list.searchNode(value);
            break;
        case 9:
            list.displayList();
            break;
        case 0:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid number!" << endl;
        }
    }
}
