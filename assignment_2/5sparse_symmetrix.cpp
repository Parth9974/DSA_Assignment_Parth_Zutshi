#include <iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"enter the no of rows and columns";
    cin>>row>>col;
    int len=(row*(row+1))/2;
    int arr[len];
    cout<<"enter the elements";
    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    int flag=0;
    int flag1=0;
    int val=0;
    int arr1[row*row-row];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==j)
            {
                cout<<arr[flag]<<"  ";
                flag++;
            }
            else if(j<i)
            {
                cout<<arr[flag]<<"  ";
                arr1[val]=arr[flag];
                val++;
                flag++;
            }
            else{
                cout<<arr1[flag1]<<"  ";
                flag1++;
            }
        }
        cout<<endl;
    }
}