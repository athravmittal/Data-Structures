#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target: ";
    cin >> target;
    int left = 0;
    int right = n-1;
    bool flag = true;
    int mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            flag = false;
            break;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (!flag)
    {
        cout << "Target at index: " << mid << endl;
    }
    else
    {
        cout << "No such element present in the array";
    }

    return 0;
}