// smallest in the row but largest in its column
#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cout << "enter the rows and columns of the matrix";
    cin >> row >> col;
    int arr[row][col];
    cout << "enter the elements of the array";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int min = arr[0][0];
    int max = arr[0][0];
    int col_idx = 0;
    int flag=0;
    for (int i = 0; i < row; i++)
    {
        min=arr[i][0];
        for (int j = 0; j < col; j++)
        {
            if (min > arr[i][j])
            {
                min = arr[i][j];
                col_idx = j;
            }
        }
        max = arr[0][col_idx];
        for (int l = 1; l < row; l++)
        {
            if (max <= arr[l][col_idx])
            {
                max = arr[l][col_idx];
            }
        }
        if (min == max)
        {
            flag++;
            cout << min;
        }
    }
    if(flag>0)
    exit(0);
    else
    cout << "no saddle point";
}