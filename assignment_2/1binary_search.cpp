#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of elements in the array";\
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int num,start=0,end=n-1;
    cout<<"enter the no to be searched";
    cin>>num;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==num)
        {
            cout<<"element found at index: "<<mid;
            exit(0);
        }
        else if(arr[mid]<num)
        {
            start=mid+1;
        }
        else if(arr[mid]>num)
        {
            end=mid-1;
        }
    }
    cout<<"element not found";
}