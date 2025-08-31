#include <iostream>
using namespace std;

int main()

{
    int n;
    cout<<"enter the no of elements in the array";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int interval=(arr[0]+arr[n-1])/n;
    for(int i=0;i<n-1;i++)
    {
       if(arr[i+1]-arr[i]!=interval)
       {
            cout<<"the missing no is: "<<(arr[i]+arr[i+1])/2;
            exit(0);
       }
    }
    cout<<"No such missing no found";
}