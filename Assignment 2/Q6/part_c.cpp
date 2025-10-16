#include <iostream>
using namespace std;

int main() {
    int row1[100], col1[100], val1[100], total1;
    int row2[100], col2[100], val2[100], total2;

    cout << "Enter total non-zero values for Matrix A: ";
    cin >> total1;
    cout << "Enter row, column and value for non-zero elements of A:\n";
    for (int i = 0; i < total1; i++) {
        cin >> row1[i] >> col1[i] >> val1[i];
    }

    cout << "Enter total non-zero values for Matrix B: ";
    cin >> total2;
    cout << "Enter row, column and value for non-zero elements of B:\n";
    for (int i = 0; i < total2; i++) {
        cin >> row2[i] >> col2[i] >> val2[i];
    }

    int row[100], col[100], val[100];
    int k = 0;

    for (int i = 0; i < total1; i++) {
        for (int j = 0; j < total2; j++) {
          
            if (col1[i] == row2[j]) {
                int r = row1[i];
                int c = col2[j];
                int v = val1[i] * val2[j];

             
                bool found = false;
                for (int x = 0; x < k; x++) {
                    if (row[x] == r && col[x] == c) {
                        val[x] += v; 
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    row[k] = r;
                    col[k] = c;
                    val[k] = v;
                    k++;
                }
            }
        }
    }

    cout << "\nResult of Multiplication (Sparse Matrix Triplets):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i < k; i++) {
        cout << row[i] << "   " << col[i] << "   " << val[i] << "\n";
    }

    return 0;
}
