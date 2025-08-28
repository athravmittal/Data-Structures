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
        capacity = c;
        top = -1;
        arr = new char[c];
    }

    void push(char x)
    {
        if (top == capacity - 1) return;
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1) return;
        top--;
    }

    char peek()
    {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    stack st(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isOperand(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                postfix += st.peek();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
            {
                postfix += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        postfix += st.peek();
        st.pop();
    }

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
