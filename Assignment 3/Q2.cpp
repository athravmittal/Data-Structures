#include <iostream>
using namespace std;

class stack
{
    int capacity;
    char *arr;
    int top;

public:
    stack(int c)
    {
        this->capacity = c;
        this->top = -1;
        arr = new char[c];
    }

    void push(char num)
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
            cout << "The elements in the stack are: ";
            for (int i = c; i >= 0; i--)
            {
                cout << this->arr[i];
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
    string a= "DataStructures";
    stack st(a.length());
    for (int i = 0; i < a.length(); i++)
    {
        st.push(a[i]);
    }

    st.display();
    

    return 0;
}