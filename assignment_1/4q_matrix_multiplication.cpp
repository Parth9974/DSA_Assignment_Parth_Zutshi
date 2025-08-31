#include <iostream>
using namespace std;

int main()
{
    int row1,col1,row2,col2;
    cout<<"enter the row and columnn of the first matrix"<<endl;
    cin>>row1>>col1;
    cout<<"enter the row and columnn of the second matrix"<<endl;
    cin>>row2>>col2;
    int arr1[row1][col1];
    int arr2[row2][col2];

    if(col1!=row2)
    {
        cout<<"Matrix Multiplication not possible"<<endl;
        exit(0);
    }
    else{
        cout<<"enter the elements of the first matrix";
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                cin>>arr1[i][j];
            }
        }
        cout<<"enter the elements of the second matrix";
        for(int i=0;i<row2;i++)
        {
            for(int j=0;j<col2;j++)
            {
                cin>>arr2[i][j];
            }
        }
        int arr3[row1][col2];
        int copy_col=0;
        int copy_row=0;
        int sum=0;
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col2;j++)
            {
                for(int k=0;k<col1;k++)
                {
                    sum+=arr1[i][copy_col]*arr2[copy_row][j];
                    copy_col++;
                    copy_row++;
                }
                arr3[i][j]=sum;
                sum=0;
                copy_col=0;
                copy_row=0;
            }
        }

        cout<<"The resultant matrix is:"<<endl;

        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col2;j++)
            {
                cout<<arr3[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
}