#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the elements of the array" << endl;
    cin >> n;
    int arr[n];
    int num_not;
    cout << "enter a random no which is not in the array" << endl;
    cin >> num_not;
    cout << "enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == num_not || arr[i] == num_not)
            {
                continue;
            }
            if (arr[i] == arr[j])
            {
                arr[j] = num_not;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << "Resultant array:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != num_not)
        {
            cout << arr[i] << ",";
        }
    }
}