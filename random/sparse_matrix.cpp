#include <iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"enter the row and col of the matrix";
    cin>>row>>col;
    int val;
    cout<<"enter the no of non zero values";
    cin>>val;
    int arr[3][val];
    cout<<"Enter the row first and then the columns and then the value in the matrix for non zero";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<val;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<val;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int row_count=0;
    int col_count=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==arr[row_count][col_count] && j==arr[row_count+1][col_count])
            {
                cout<<arr[2][col_count]<<" ";
                col_count++;
            }
            else{
                cout<<"0"<<" ";
            }
            
        }
        cout<<endl;
    }
}