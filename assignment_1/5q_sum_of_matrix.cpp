#include <iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"enter the rows and columns"<<endl;
    cin>>row>>col;
    int arr[row][col];
    cout<<"enter the element of the array"<<endl;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"the entered array is:"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int sum_row=0;
    for(int i=0;i<row;i++)
    {
        sum_row=0;
        for(int j=0;j<col;j++)
        {
            sum_row+=arr[i][j];
        }
        cout<<"the sum of row "<<i+1<<":"<<sum_row<<endl;
    }
    int sum_col=0;
    for(int i=0;i<col;i++)
    {
        sum_col=0;
        for(int j=0;j<row;j++)
        {
            sum_col+=arr[j][i];
        }
        cout<<"the sum of column "<<i+1<<":"<<sum_col<<endl;
    }
}