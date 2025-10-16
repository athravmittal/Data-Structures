#include <iostream>
using namespace std;

void SymmetricMatrix(int arr[], int n)
{
    cout << "Symmetric Matrix:" << endl;
    int k = 0;
}

int main()
{
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int mat[n][n];
    cout << "Enter the elements of the matrix:" << endl;
    int total = (n * (n + 1)) / 2;
    int a[total];
    for (int i = 0; i < total; i++)
    {
        cout << "Enter " << total << " elements: ";
        cin >> a[i];
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            mat[i][j] = a[k];
            mat[j][i] = a[k];
            k++;
        }
    }

    cout << "Symmetric Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
