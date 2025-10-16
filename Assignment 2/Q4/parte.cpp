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

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    str = toLowerCase(str);

    cout << "Sorted string : " << str;
    return 0;
}
