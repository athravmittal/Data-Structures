#include <iostream>
using namespace std;

class stack
{
    int capacity;
    int *arr;
    int top;

public:
    stack(int c)
    {
        this->capacity = c;
        this->top = -1;
        arr = new int[c];
    }

    void push(int num)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Overflow";
            return;
        }
        this->top++;
        this->arr[this->top] = num;
        return;
    }

    void pop()
    {
        if (this->top < 0)
        {
            cout << "Underflow";
            return;
        }
        this->top--;
        return;
    }

    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top == this->capacity - 1;
    }

    void display()
    {
        if (this->top < 0)
        {
            cout << "No element is in the stack!!" << endl;
            return;
        }
        else
        {
            int c = this->top;
            for (int i = c; i >= 0; i--)
            {
                cout << "The elements in the stack are: " << this->arr[i];
            }
        }
        return;
    }

    void peek(){
        cout<<"The top element is: "<<this->arr[this->top]<<endl;
    }
};

int main()
{
    return 0;
}