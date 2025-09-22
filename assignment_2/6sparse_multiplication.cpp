#include <iostream>
using namespace std;

struct Triplet
{
    int row, col, val;
};

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2)
    {
        cout << "Matrix multiplication not possible";
        return 0;
    }

    int n1, n2;
    cout << "Enter number of non-zero values in first matrix: ";
    cin >> n1;
    Triplet A[n1];
    cout << "Enter row col value for first matrix:" << endl;
    for (int i = 0; i < n1; i++)
        cin >> A[i].row >> A[i].col >> A[i].val;

    cout << "Enter number of non-zero values in second matrix: ";
    cin >> n2;
    Triplet B[n2];
    cout << "Enter row col value for second matrix:" << endl;
    for (int i = 0; i < n2; i++)
        cin >> B[i].row >> B[i].col >> B[i].val;

    int result[r1][c2];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (A[i].col == B[j].row)
                result[A[i].row][B[j].col] += A[i].val * B[j].val;
        }
    }

    int count = 0;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            if (result[i][j] != 0)
                count++;

    Triplet C[count];
    int k = 0;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            if (result[i][j] != 0)
            {
                C[k].row = i;
                C[k].col = j;
                C[k].val = result[i][j];
                k++;
            }
        }
    }

    cout << "Result in Triplet form:" << endl;
    for (int i = 0; i < count; i++)
        cout << C[i].row << " " << C[i].col << " " << C[i].val << endl;

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
