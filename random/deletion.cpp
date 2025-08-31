#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of elements in the array"<<endl;
    cin>>n;
    int arr[n];
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
    int idx;
    cout<<"enter the index of the element to be deleted"<<endl;
    cin>>idx;


    for(int i=idx;i<n;i++)
    {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
    }
    cout<<"the new array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}