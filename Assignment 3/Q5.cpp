#include <iostream>
#include <math.h>
using namespace std;

class stack
{
    int capacity;
    int *arr;
    int top;

public:
    stack(int c)
    {
        capacity = c;
        top = -1;
        arr = new int[c];
    }

    void push(int x)
    {
        if (top == capacity - 1)
            return;
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1)
            return;
        top--;
    }

    int peek()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int Op(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    if (op == '^')
        return pow(a, b);
    return 0;
}

int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    stack st(postfix.length());

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (c >= '0' && c <= '9')
        {
            st.push(c - '0'); // convert char to int
        }
        else if (isOperator(c))
        {
            int val2 = st.peek();
            st.pop();
            int val1 = st.peek();
            st.pop();
            int res = Op(val1, val2, c);
            st.push(res);
        }
    }

    cout << "Result: " << st.peek() << endl;
    return 0;
}
