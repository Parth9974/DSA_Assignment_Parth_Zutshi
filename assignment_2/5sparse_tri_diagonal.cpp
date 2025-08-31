#include <iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"enter the row and col of a matrix";
    cin>>row>>col;
    int arr[3*row-2];
    cout<<"enter the tri-diagonal values of the matrix";
    for(int i=0;i<3*row-2;i++)
    {
        cin>>arr[i];
    }
    int flag=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==j)
            {
                cout<<arr[flag]<<"  ";
                flag++;
            }
            else if(i<j && j-i==1)
            {
                cout<<arr[flag]<<"  ";
                flag++;
            }
            else if(i>j && i-j==1)
            {
                cout<<arr[flag]<<"  ";
                flag++;
            }
            else{
                cout<<"0"<<"  ";
            }
        }
        cout<<endl;
    }
}