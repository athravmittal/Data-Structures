
#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
        }
        else
        {
            if (isEmpty())
                front = 0;
            rear = (rear + 1) % size;
            arr[rear] = value;
            cout << value << " enqueued into queue." << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
        }
        else
        {
            cout << arr[front] << " dequeued from queue." << endl;
            if (front == rear) // Queue has only one element
                front = rear = -1;
            else
                front = (front + 1) % size;
        }
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Nothing at front." << endl;
        }
        else
        {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue elements (front to rear): ";
            int i = front;
            while (true)
            {
                cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    q.peek();

    return 0;
}