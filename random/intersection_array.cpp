#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cout << "enter the number of elements in the two arrays";
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    int arr3[n1 + n2];
    int flag = 0;
    cout << "enter the elements of the array";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    int i = 0;
    int j = 0;
    while (i < n1)
    {
        while (j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                if (arr1[i] == arr3[flag - 1])
                {
                    i++;
                }
                else
                {
                    arr3[flag] = arr1[i];
                    flag++;
                    i++;
                    break;
                }
            }
            else if (arr2[j] < arr1[i])
            {
                if (arr2[j] == arr3[flag - 1])
                {
                    j++;
                }
                else
                {
                    arr3[flag] = arr2[j];
                    flag++;
                    j++;
                }
            }
            else if (arr1[i] == arr2[j])
            {
                j++;
            }
        }
    }
    while(j<n2)
    {
        arr3[flag]=arr2[j];
        j++;
    }
    while(i<n1)
    {
        arr3[flag]=arr2[j];
        i++;
    }
    for (int k = 0; k < n1 + n2; k++)
    {
        cout << arr3[k] << ",";
    }
}