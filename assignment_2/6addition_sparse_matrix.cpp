#include <iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"enter the row and col of the matrix";
    cin>>row>>col;
    int val1,val2;
    cout<<"enter the no of non zero values for the first one";
    cin>>val1;
    int arr1[3][val1];
    cout<<"enter the no of non zero values for the first one";
    cin>>val2;
    int arr2[3][val2];
    cout<<"Enter the row first and then the columns and then the value in the matrix for non zero";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<val1;j++)
        {
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter the row first and then the columns and then the value in the matrix for non zero";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<val2;j++)
        {
            cin>>arr2[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<val1;j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<val2;j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int row_count1=0;
    int col_count1=0;
    int row_count2=0;
    int col_count2=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if((i==arr1[row_count1][col_count1] && j==arr1[row_count1+1][col_count1]) && (i==arr2[row_count2][col_count2] && j==arr2[row_count2+1][col_count2]))
            {
                cout<<arr1[2][col_count1]+arr2[2][col_count2]<<" ";
                col_count1++;
                col_count2++;
            }
            else if(i==arr1[row_count1][col_count1] && j==arr1[row_count1+1][col_count1])
            {
                cout<<arr1[2][col_count1]<<" ";
                col_count1++;
            }
            else if(i==arr2[row_count2][col_count2] && j==arr2[row_count2+1][col_count2])
            {
                cout<<arr2[2][col_count2]<<" ";
                col_count2++;
            }
            else{
                cout<<"0"<<" ";
            }
            
        }
        cout<<endl;
    }
}