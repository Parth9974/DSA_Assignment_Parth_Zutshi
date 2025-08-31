//Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion 
// if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number 
// of inversions in an array. 
#include <iostream>
using namespace std;
void reverse(int arr1[],int num)
{
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(arr1[i]>arr1[j])
            {
                cout<<"("<<arr1[i]<<","<<arr1[j]<<")";
            }
        }
        cout<<endl;
    }
}
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
    reverse(arr,n);
}