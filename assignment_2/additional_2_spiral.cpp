#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cout << "enter the row and columns of the matrix";
    cin >> row >> col;
    int arr[row][col];
    int arr1[row * col];
    cout << "enter the elements of the array";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int right = col - 1, left = 0, down = row - 1, up = 0;
    int i = 0, j = 0, flag = 0;
    while (flag <= row * col)
    {
        if (i == left && j == left) // condition for right
        {
            if (j <= right)
            {
                while (j <= right)
                {
                    arr1[flag] = arr[i][j];
                    cout<<arr1[flag]<<",";
                    flag++;
                    j++;
                }
                j--;
                right--;
            }
            else if (i == up && j == right) // condition for down
            {
                if (i <= down)
                {
                    while (i <= down)
                    {
                        arr1[flag] = arr[i][j];
                        cout<<arr1[flag]<<",";
                        i++;
                        flag++;
                    }
                    i--;
                    down--;
                }
            }
            else if (i == down && j == left) // condition for up
            {
                if (i >= up)
                {
                    while (i >= up)
                    {
                        arr1[flag] = arr[i][j];
                        cout<<arr1[flag]<<",";
                        flag++;
                        i--;
                    }
                    i++;
                    up++;
                }
            }
            else if (i == right && j == right) // condition for left
            {
                if (j >= left)
                {
                    while (j >= left)
                    {
                        arr1[flag] = arr[i][j];
                        cout<<arr1[flag]<<",";
                        flag++;
                        j--;
                    }
                    j++;
                    left++;
                }
            }
        }
    }
}