#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the no of elements in the array" << endl;
    cin >> n;
    int arr[n + 1];
    cout << "enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "the array entered is :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout << "the reversed array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}