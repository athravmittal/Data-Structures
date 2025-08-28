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

    char peek()
    {
        if (isEmpty())
            return '\0';
        return this->arr[this->top];
    }
};

int main()
{
    string a = "({[[]]]})";
    stack st(a.length());
    bool valid= true;
    for (int i = 0; i < a.length(); i++)
    {
        
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
        {
            st.push(a[i]);
        }
        else
        {
            if ((a[i] == ')' && st.peek() != '(') ||
                (a[i] == '}' && st.peek() != '{') ||
                (a[i] == ']' && st.peek() != '['))
            {
                valid = false; 
                break;
            }
            else{
                st.pop();
            }
        }
    }
    
    if (!st.isEmpty())
        valid = false;

    if (valid)
        cout << "Valid " << endl;
    else
        cout << "Not valid " << endl;


    return 0;
}