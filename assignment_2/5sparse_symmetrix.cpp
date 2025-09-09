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
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==j)
            {
                cout<<arr[flag]<<"  ";
                flag++;
                flag1++;
            }
            else if(j<i)
            {
                cout<<arr[flag]<<"  ";
                flag++;
            }
            else{
                cout<<arr[flag1]<<"  ";
                flag1++;
            }
        }
        cout<<endl;
    }
}