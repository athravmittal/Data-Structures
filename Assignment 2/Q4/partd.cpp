#include <iostream>
using namespace std;

int stringLength(string s)
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}

string toLowerCase(string s)
{
    for (int i = 0; i < stringLength(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

string sort(string s)
{
    int n = stringLength(s);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] > s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    return s;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    str = toLowerCase(str);
    str = sort(str);

    cout << "Sorted string : " << str;
    return 0;
}
