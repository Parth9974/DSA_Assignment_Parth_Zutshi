#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;
    int val1, val2;
    cout << "Enter the number of non-zero values for the first matrix: ";
    cin >> val1;
    cout << "Enter the number of non-zero values for the second matrix: ";
    cin >> val2;
    int A[3][val1];
    int B[3][val2];
    int C[3][val1 + val2];
    int C_count = 0;
    cout << "Enter the non-zero values for the first matrix (row, column, value):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < val1; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter the non-zero values for the second matrix (row, column, value):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < val2; j++) {
            cin >> B[i][j];
        }
    }
    int i = 0, j = 0;
    while (i < val1 && j < val2) {
        if (A[0][i] < B[0][j]) {
            C[0][C_count] = A[0][i];
            C[1][C_count] = A[1][i];
            C[2][C_count] = A[2][i];
            i++;
        } else if (B[0][j] < A[0][i]) {
            C[0][C_count] = B[0][j];
            C[1][C_count] = B[1][j];
            C[2][C_count] = B[2][j];
            j++;
        } else {
            if (A[1][i] < B[1][j]) {
                C[0][C_count] = A[0][i];
                C[1][C_count] = A[1][i];
                C[2][C_count] = A[2][i];
                i++;
            } else if (B[1][j] < A[1][i]) {
                C[0][C_count] = B[0][j];
                C[1][C_count] = B[1][j];
                C[2][C_count] = B[2][j];
                j++;
            } else {
                C[0][C_count] = A[0][i];
                C[1][C_count] = A[1][i];
                C[2][C_count] = A[2][i] + B[2][j];
                i++;
                j++;
            }
        }
        C_count++;
    }
    while (i < val1) {
        C[0][C_count] = A[0][i];
        C[1][C_count] = A[1][i];
        C[2][C_count] = A[2][i];
        i++;
        C_count++;
    }
    while (j < val2) {
        C[0][C_count] = B[0][j];
        C[1][C_count] = B[1][j];
        C[2][C_count] = B[2][j];
        j++;
        C_count++;
    }
    cout << "Resultant Sparse Matrix (Row, Column, Value):" << endl;
    for (int k = 0; k < C_count; k++) {
        if (C[2][k] != 0) {
            cout << C[0][k] << " " << C[1][k] << " " << C[2][k] << endl;
        }
    }
    return 0;
}