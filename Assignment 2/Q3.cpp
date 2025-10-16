#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<("Enter size of array: ");
    cin>> n;
    int arr[n];

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i]!=i+1)
        {
            cout<<"The missing number is "<<i+1<<" at position"<<i+1<<endl;
            break;
        }
        
    }
    

    return 0;
}