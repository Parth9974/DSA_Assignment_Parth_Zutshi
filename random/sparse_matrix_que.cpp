#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of non-zero elements in the array";
    cin>>n;
    int arr[3][n];
    cout<<"enter the rows , then columns then elements of the array";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    
}