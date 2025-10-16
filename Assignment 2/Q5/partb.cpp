#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n][n];

    cout << "Enter the elements of tri-diagonal matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i == j + 1 || i == j - 1)
            {
                cin >> arr[i][j];
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    cout << "The tri-diagonal Matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}