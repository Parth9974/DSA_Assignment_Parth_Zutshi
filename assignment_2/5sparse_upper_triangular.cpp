#include <iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"enter the row and col of a matrix";
    cin>>row>>col;
    int len=(row*(row+1))/2;
    int arr[len];
    cout<<"enter the lower triangular values of the matrix";
    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    int flag=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==j || i<j)
            {
                cout<<arr[flag]<<"   ";
                flag++;
            }
            else{
                cout<<"0"<<"  ";
            }
        }
        cout<<endl;
    }
}