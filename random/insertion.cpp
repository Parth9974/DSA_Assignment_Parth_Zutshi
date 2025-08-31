#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of elements in the array"<<endl;
    cin>>n;
    int arr[n+1];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"the array entered is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int num,idx;
    cout<<"enter the element to be inserted and at what index of the array"<<endl;
    cin>>num>>idx;


    for(int i=n;i>=0;i--)
    {
        if(i==idx)
        {
            arr[i]=num;
            break;
        }
        else{
            arr[i]=arr[i-1];
        }
    }
    cout<<"the new array is:"<<endl;
    for(int i=0;i<n+1;i++)
    {
        cout<<arr[i]<<" ";
    }
}