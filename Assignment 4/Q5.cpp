#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() { return q1.empty(); }
};

class StackOneQueue
{
    queue<int> q;

public:
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() { return q.empty(); }
};

int main()
{
    cout << "Stack Using Two Queues " << endl;
    StackTwoQueues st1;
    st1.push(10);
    st1.push(20);
    st1.push(30);
    cout << "Top: " << st1.top() << endl;
    st1.pop();
    cout << "Top after : " << st1.top() << endl;
    cout << endl;

    cout << "Stack Using One Queue " << endl;
    StackOneQueue st2;
    st2.push(10);
    st2.push(20);
    st2.push(30);
    cout << "Top: " << st2.top() << endl;
    st2.pop();
    cout << "Top after : " << st2.top() << endl;
    cout << endl;

    return 0;
}
