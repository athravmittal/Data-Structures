#include <iostream>
using namespace std;

int main()
{

    int row[100], colunm[100], value[100];
    int total;
    cout << "Enter total values to be stored: ";
    cin >> total;
    cout << "Enter row, column and value for non-zero elements: ";
    for (int i = 0; i < total; i++)
    {
        cin >> row[i] >> colunm[i] >> value[i];
    }

    // for transpose of the matrix
    for (int i = 0; i < total; i++)
    {
        int temp;
        temp = row[i];
        row[i] = colunm[i];
        colunm[i] = temp;
    }

    cout << "\nTranspose of Sparse Matrix (Triplets):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i < total; i++) {
        cout << row[i] << "   " << colunm[i] << "   " << value[i] << "\n";
    }

    return 0;
}