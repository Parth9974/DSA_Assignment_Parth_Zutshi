#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int len = (n * (n + 1)) / 2;
    int arr[len];

    cout << "Enter the lower triangular values row-wise (including diagonal):" << endl;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int k = 0;
    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            matrix[i][j] = arr[k];
            matrix[j][i] = arr[k];
            k++;
        }
    }

    cout << "Symmetric Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}
