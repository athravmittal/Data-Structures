#include <iostream>
using namespace std;

int main()
{

    int row1[100], colunm1[100], value1[100];
    int total,total2;
    cout << "Enter total values to be stored: ";
    cin >> total;
    cout << "Enter row, column and value for non-zero elements: ";
    for (int i = 0; i < total; i++)
    {
        cin >> row1[i] >> colunm1[i] >> value1[i];
    }
    
    int row2[100], colunm2[100], value2[100];
    cout << "Enter total non-zero values for Matrix 2: ";
    cin >> total2;
    cout << "Enter row, column and value for non-zero elements: ";
    for (int i = 0; i < total2; i++)
    {
        cin >> row2[i] >> colunm2[i] >> value2[i];
    }

    
    int row[200],colunm[200],value[200];
    int k=0;
    for (int i = 0; i < total; i++) {
        bool found = false;
        for (int j = 0; j < total2; j++) {
            if (row1[i] == row2[j] && colunm1[i] == colunm2[j]) {
                row[k] = row1[i];
                colunm[k] = colunm1[i];
                value[k] = value1[i] + value2[j];
                found = true;
                break;
            }
        }
        if (!found) { // only in matrix 1
            row[k] = row1[i];
            colunm[k] = colunm1[i];
            value[k] = value1[i];
        }
        k++;
    }

  
    for (int j = 0; j < total2; j++) {
        bool found = false;
        for (int i = 0; i < total; i++) {
            if (row2[j] == row1[i] && colunm2[j] == colunm1[i]) {
                found = true;
                break;
            }
        }
        if (!found) { // only in matrix 2
            row[k] = row2[j];
            colunm[k] = colunm2[j];
            value[k] = value2[j];
            k++;
        }
    }
    
    cout << "\nAddition of Sparse Matrix (Triplets):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i < total; i++) {
        cout << row[i] << "   " << colunm[i] << "   " << value[i] << "\n";
    }

    return 0;
}