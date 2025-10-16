#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter characters: ";
    getline(cin, s);

    queue<char> q;
    int freq[26] = {0};

    for (char ch : s)
    {
        if (ch == ' ')
            continue;

        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    cout << endl;
    return 0;
}
