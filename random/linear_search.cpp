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
    int num;
    cout<<"enter the element to be searched"<<endl;
    cin>>num;
    int idx;
    for(int i=0;i<n;i++)
    {
        if(num==arr[i])
        idx=i;
    }
    cout<<"element found at index "<<idx;
}